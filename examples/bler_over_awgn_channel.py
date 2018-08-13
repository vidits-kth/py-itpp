# MIT License
# 
# Copyright (c) 2018 Vidit Saxena
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import itpp

import matplotlib
matplotlib.use("tkagg")

from matplotlib import pyplot as plt

def block_error_ratio_uncoded_awgn(snr_db, block_size):
    '''Generate random bits'''
    nrof_bits = 3 * 10000 * block_size
    source_bits = itpp.random.randb(nrof_bits)
    
    '''Modulate the bits'''
    modulator_ = itpp.comm.modulator_1d()
    constellation = itpp.vec('-1, 1')
    symbols = itpp.ivec('0, 1')
    modulator_.set(constellation, symbols)
    tx_signal = modulator_.modulate_bits(source_bits)
    
    '''Add the effect of channel to the signal'''
    noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
    noise = itpp.random.randn(tx_signal.length())
    noise *= itpp.math.sqrt(noise_variance)
    rx_signal = tx_signal + noise
    
    '''Demodulate the signal'''
    demodulated_bits = modulator_.demodulate_bits(rx_signal)
    
    '''Calculate the block error ratio'''
    blerc = itpp.comm.BLERC(block_size)
    blerc.count(source_bits, demodulated_bits)
    return blerc.get_errorrate()

def block_error_ratio_hamming_awgn(snr_db, block_size):
    '''Hamming encoder and decoder instance'''
    k = 3 # (7,4) Hamming code
    hamm = itpp.comm.hamming_code(k)
    
    '''Generate random bits'''
    nrof_bits = k * 10000 * block_size
    source_bits = itpp.random.randb(nrof_bits)
    
    '''Encode the bits'''
    encoded_bits = hamm.encode(source_bits)
    
    '''Modulate the bits'''
    modulator_ = itpp.comm.modulator_1d()
    constellation = itpp.vec('-1, 1')
    symbols = itpp.ivec('0, 1')
    modulator_.set(constellation, symbols)
    tx_signal = modulator_.modulate_bits(encoded_bits)
    
    '''Add the effect of channel to the signal'''
    noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
    noise = itpp.random.randn(tx_signal.length())
    noise *= itpp.math.sqrt(noise_variance)
    rx_signal = tx_signal + noise
    
    '''Demodulate the signal'''
    demodulated_bits = modulator_.demodulate_bits(rx_signal)
    
    '''Decode the received bits'''
    decoded_bits = hamm.decode(demodulated_bits) 
    
    '''Calculate the block error ratio'''
    blerc = itpp.comm.BLERC(block_size)
    blerc.count(source_bits, decoded_bits)
    return blerc.get_errorrate()

def block_error_ratio_turbo_awgn(snr_db, interleaver_length):
  '''Create turbo_codec_instance'''
  codec = itpp.comm.turbo_codec()
  
  '''Set codec parameters'''
  gen = itpp.ivec(2)
  gen[0] = 11
  gen[1] = 13
  constraint_length = 4
  interleaver = itpp.ivec('0, 19, 14, 33, 28, 47, 42, 13, 8, 27, 22, 41, 36, 7, 2, 21, 16, 35, 30, 1, 44, 15, 10, 29, 24, 43, 38, 9, 4, 23, 18, 37, 32, 3, 46, 17, 12, 31, 26, 45, 40, 11, 6, 25, 20, 39, 34, 5')
  codec.set_parameters(gen, gen, constraint_length, itpp.ivec())
  codec.set_interleaver(interleaver)
  
  '''Generate random bits and encode them'''
  nrof_uncoded_bits = interleaver_length * 1000
  uncoded_bits = itpp.random.randb(nrof_uncoded_bits)
  encoded_bits = itpp.bvec()
  codec.encode(uncoded_bits, encoded_bits)
  
  '''Modulate bits using BPSK'''
  symbols = itpp.vec('1, -1')
  bits2symbol = itpp.ivec('0, 1')
  modulator_ = itpp.comm.modulator_1d(symbols, bits2symbol)
  tx_signal = modulator_.modulate_bits(encoded_bits)
  
  '''Add AWGN noise'''
  noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
  noise = itpp.random.randn(tx_signal.length())
  noise *= itpp.math.sqrt(noise_variance)
  rx_signal = tx_signal + noise
  
  '''Demodulate received signal (soft bits, LOGMAP)'''
  soft_bits = itpp.vec()
  modulator_.demodulate_soft_bits(rx_signal, 
                                  noise_variance,
                                  soft_bits,
                                  itpp.comm.Soft_Method.LOGMAP)

  '''Turbo decode the soft bits'''
  decoded_bits = itpp.bvec()
  codec.decode(soft_bits, decoded_bits, itpp.bvec())
    
  '''Count errors'''
  blerc = itpp.comm.BLERC(interleaver_length)
  blerc.count(decoded_bits, uncoded_bits)
  return blerc.get_errorrate()

if __name__ == '__main__':
    '''SNR range'''
    snrs_db = range(-10, 10) 
    block_size = 4
    
    print('BLER for uncoded bits over AWGN channel')
    bler_unc = [block_error_ratio_uncoded_awgn(snr, block_size) for snr in snrs_db]
    
    print('BLER for Hamming (7, 4) coded  bits over AWGN channel')
    bler = [block_error_ratio_hamming_awgn(snr, block_size) for snr in snrs_db]
    
    print('BLER for Turbo coded  bits over AWGN channel, interleaver length 48 and code rate 0.33')
    interleaver_length = 48
    bler_turbo = [block_error_ratio_turbo_awgn(snr, interleaver_length) for snr in snrs_db]
    
    print('Plotting results')
    plt.figure()
    plt.grid(True)
    plt.semilogy(snrs_db, bler_unc)
    plt.semilogy(snrs_db, bler)
    plt.semilogy(snrs_db, bler_turbo)
    plt.xlabel('SNR [dB]')
    plt.ylabel('Block Error Ratio')
    plt.legend(['Uncoded (4,4)', 'Hamming (7,4)', 'Turbo (48,0.33)'], loc = 'lower left')
    plt.show()
