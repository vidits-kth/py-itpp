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

def bit_error_ratio_uncoded_awgn(snr_db):
    '''Generate random bits'''
    nrof_bits = 3 * 100000
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
    
    '''Calculate the bit error ratio'''
    return itpp.comm.BERC.count_errors(source_bits, demodulated_bits, 0, 0, 0) / nrof_bits

def bit_error_ratio_hamming_awgn(snr_db):
    '''Hamming encoder and decoder instance'''
    k = 3 # (7,4) Hamming code
    hamm = itpp.comm.hamming_code(k)
    
    '''Generate random bits'''
    nrof_bits = k * 100000
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
    
    '''Calculate the bit error ratio'''
    return itpp.comm.BERC.count_errors(source_bits, decoded_bits, 0, 0, 0) / nrof_bits

if __name__ == '__main__':
    '''SNR range'''
    snrs_db = range(-10, 10) 
    
    print('BER for uncoded bits over AWGN channel')
    ber_unc = [bit_error_ratio_uncoded_awgn(snr) for snr in snrs_db]
    
    print('BER for Hamming (7, 4) coded  bits over AWGN channel')
    ber = [bit_error_ratio_hamming_awgn(snr) for snr in snrs_db]
    
    plt.figure()
    plt.grid(True)
    plt.semilogy(snrs_db, ber)
    plt.semilogy(snrs_db, ber_unc)
    plt.xlabel('SNR [dB]')
    plt.ylabel('Bit Error Ratio')
    plt.legend(['Hamming Code', 'Uncoded'])
    plt.show()
