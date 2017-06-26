# COPYRIGHT_NOTICE

from matplotlib import pyplot as plt
import numpy as np

from py_itpp import vec, bvec, ivec
from py_itpp import bin
from py_itpp import random
from py_itpp import modulator_1d, soft_method
from py_itpp import BERC, BLERC
from py_itpp import turbo_codec

def turbo_codec_encode_decode_test():
  print '-------Create turbo_codec_instance-------'
  codec = turbo_codec()
  
  print '-------Set codec parameters-------'
  gen = ivec(2)
  gen[0] = 11
  gen[1] = 13
  constraint_length = 4
  interleaver_length = 48
  interleaver = ivec('0, 19, 14, 33, 28, 47, 42, 13, 8, 27, 22, 41, 36, 7, 2, 21, 16, 35, 30, 1, 44, 15, 10, 29, 24, 43, 38, 9, 4, 23, 18, 37, 32, 3, 46, 17, 12, 31, 26, 45, 40, 11, 6, 25, 20, 39, 34, 5')
  codec.set_parameters(gen, gen, constraint_length, ivec())
  codec.set_interleaver(interleaver)
  
  print '-------Generate random bits and encode them-------'
  nrof_uncoded_bits = interleaver_length * 1000
  uncoded_bits = random.randb(nrof_uncoded_bits)
  encoded_bits = bvec()
  codec.encode(uncoded_bits, encoded_bits)
  print 'uncoded_bits length', uncoded_bits.length()
  print 'encoded_bits length', encoded_bits.length()
  
  print '-------Modulate bits using BPSK-------'
  symbols = vec('1, -1')
  bits2symbol = ivec('0, 1')
  modulator_ = modulator_1d(symbols, bits2symbol)
  tx_signal = modulator_.modulate_bits(encoded_bits)
  print 'tx_signal length', tx_signal.length()
  
  print '-------Add AWGN noise-------'
  snr_db = 0
  noise_variance = 1.0 / (pow(10, 0.1 * snr_db))
  noise = random.randn(tx_signal.length())
  noise *= np.sqrt(noise_variance)
  rx_signal = tx_signal + noise
  
  print '-------Demodulate received signal (soft bits, LOGMAP)-------'
  soft_bits = vec()
  modulator_.demodulate_soft_bits(rx_signal, 
                                  noise_variance,
                                  soft_bits,
                                  soft_method.LOGMAP)
  print 'soft_bits length', soft_bits.length()

  print '-------Turbo decode the soft bits-------'
  decoded_bits = bvec()
  codec.decode(soft_bits, decoded_bits, bvec())
  print 'decoded_bits length', decoded_bits.length()
    
  print '-------Count errors-------'
  bit_err = BERC.count_errors(decoded_bits, uncoded_bits, 0, 0, 0)
  print 'bit_err', bit_err

def turbo_codec_bler(snr_db):

  '''Create turbo_codec_instance'''
  codec = turbo_codec()
  
  '''Set codec parameters'''
  gen = ivec(2)
  gen[0] = 11
  gen[1] = 13
  constraint_length = 4
  interleaver_length = 48
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
    print '-------Test the Turbo codec functionality-------'
    turbo_codec_encode_decode_test()
    
    print '-------Test the Turbo codec performance-------'
    '''SNR range'''
    snrs_db = range(-10, 10) 
    
    '''BER for Turbo code coded  bits over AWGN channel'''
    bler_turbo = [turbo_codec_bler(snr) for snr in snrs_db]
    
    '''Plot BER vs SNR'''
    plt.figure()
    plt.hold(True)
    plt.grid(True)
    plt.semilogy(snrs_db, bler_turbo)
    plt.xlabel('SNR [dB]')
    plt.ylabel('Bit Error Ratio')
    plt.legend(['Turbo Code'])
    plt.show()
