# COPYRIGHT_NOTICE

from matplotlib import pyplot as plt
import numpy as np

from py_itpp.base import bvec, vec, ivec
from py_itpp.base import random

from py_itpp.comm.modulator import modulator_1d, soft_method
from py_itpp.comm.error_counters import BLERC
from py_itpp.comm.hammcode import hamming_code
from py_itpp.comm.turbo import turbo_codec

def block_error_ratio_uncoded_awgn(snr_db, block_size):
    '''Generate random bits'''
    nrof_bits = 3 * 10000 * block_size
    source_bits = random.randb(nrof_bits)
    
    '''Modulate the bits'''
    modulator_ = modulator_1d()
    constellation = vec('-1, 1')
    symbols = ivec('0, 1')
    modulator_.set(constellation, symbols)
    tx_signal = modulator_.modulate_bits(source_bits)
    
    '''Add the effect of channel to the signal'''
    noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
    noise = random.randn(tx_signal.length())
    noise *= np.sqrt(noise_variance)
    rx_signal = tx_signal + noise
    
    '''Demodulate the signal'''
    demodulated_bits = modulator_.demodulate_bits(rx_signal)
    
    '''Calculate the block error ratio'''
    blerc = BLERC(block_size)
    blerc.count(source_bits, demodulated_bits)
    return blerc.get_errorrate()

def block_error_ratio_hamming_awgn(snr_db, block_size):
    '''Hamming encoder and decoder instance'''
    k = 3 # (7,4) Hamming code
    hamm = hamming_code(k)
    
    '''Generate random bits'''
    nrof_bits = k * 10000 * block_size
    source_bits = random.randb(nrof_bits)
    
    '''Encode the bits'''
    encoded_bits = hamm.encode(source_bits)
    
    '''Modulate the bits'''
    modulator_ = modulator_1d()
    constellation = vec('-1, 1')
    symbols = ivec('0, 1')
    modulator_.set(constellation, symbols)
    tx_signal = modulator_.modulate_bits(encoded_bits)
    
    '''Add the effect of channel to the signal'''
    noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
    noise = random.randn(tx_signal.length())
    noise *= np.sqrt(noise_variance)
    rx_signal = tx_signal + noise
    
    '''Demodulate the signal'''
    demodulated_bits = modulator_.demodulate_bits(rx_signal)
    
    '''Decode the received bits'''
    decoded_bits = hamm.decode(demodulated_bits) 
    
    '''Calculate the block error ratio'''
    blerc = BLERC(block_size)
    blerc.count(source_bits, decoded_bits)
    return blerc.get_errorrate()

def block_error_ratio_turbo_awgn(snr_db, interleaver_length):
  '''Create turbo_codec_instance'''
  codec = turbo_codec()
  
  '''Set codec parameters'''
  gen = ivec(2)
  gen[0] = 11
  gen[1] = 13
  constraint_length = 4
  interleaver = ivec('0, 19, 14, 33, 28, 47, 42, 13, 8, 27, 22, 41, 36, 7, 2, 21, 16, 35, 30, 1, 44, 15, 10, 29, 24, 43, 38, 9, 4, 23, 18, 37, 32, 3, 46, 17, 12, 31, 26, 45, 40, 11, 6, 25, 20, 39, 34, 5')
  codec.set_parameters(gen, gen, constraint_length, ivec())
  codec.set_interleaver(interleaver)
  
  '''Generate random bits and encode them'''
  nrof_uncoded_bits = interleaver_length * 1000
  uncoded_bits = random.randb(nrof_uncoded_bits)
  encoded_bits = bvec()
  codec.encode(uncoded_bits, encoded_bits)
  
  '''Modulate bits using BPSK'''
  symbols = vec('1, -1')
  bits2symbol = ivec('0, 1')
  modulator_ = modulator_1d(symbols, bits2symbol)
  tx_signal = modulator_.modulate_bits(encoded_bits)
  
  '''Add AWGN noise'''
  noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
  noise = random.randn(tx_signal.length())
  noise *= np.sqrt(noise_variance)
  rx_signal = tx_signal + noise
  
  '''Demodulate received signal (soft bits, LOGMAP)'''
  soft_bits = vec()
  modulator_.demodulate_soft_bits(rx_signal, 
                                  noise_variance,
                                  soft_bits,
                                  soft_method.LOGMAP)

  '''Turbo decode the soft bits'''
  decoded_bits = bvec()
  codec.decode(soft_bits, decoded_bits, bvec())
    
  '''Count errors'''
  blerc = BLERC(interleaver_length)
  blerc.count(decoded_bits, uncoded_bits)
  return blerc.get_errorrate()

if __name__ == '__main__':
    '''SNR range'''
    snrs_db = range(-10, 10) 
    block_size = 4
    
    '''BLER for uncoded bits over AWGN channel'''
    print 'Evaluating BLER for Uncoded (4,4) over AWGN'
    bler_unc = [block_error_ratio_uncoded_awgn(snr, block_size) for snr in snrs_db]
    
    '''BLER for Hamming (7, 4) coded  bits over AWGN channel'''
    print 'Evaluating BLER for Hamming (7,4) over AWGN'
    bler = [block_error_ratio_hamming_awgn(snr, block_size) for snr in snrs_db]
    
    '''BLER for Turbo coded  bits over AWGN channel, interleaver length 48 and code rate 0.33'''
    print 'Evaluating BLER for Turbo (interleaver len 48, code rate 0.33) over AWGN'
    interleaver_length = 48
    bler_turbo = [block_error_ratio_turbo_awgn(snr, interleaver_length) for snr in snrs_db]
    
    print 'Plotting results'
    plt.figure()
    plt.hold(True)
    plt.grid(True)
    plt.semilogy(snrs_db, bler_unc)
    plt.semilogy(snrs_db, bler)
    plt.semilogy(snrs_db, bler_turbo)
    plt.xlabel('SNR [dB]')
    plt.ylabel('Block Error Ratio')
    plt.legend(['Uncoded (4,4)', 'Hamming (7,4)', 'Turbo (48,0.33)'], loc = 'lower left')
    plt.show()