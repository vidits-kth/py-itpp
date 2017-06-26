# COPYRIGHT_NOTICE

from py_itpp import vec, bvec, ivec, cvec
from py_itpp import random
from py_itpp import bin
from py_itpp import soft_method, modulator_2d

import numpy as np

def modulator_2d_modulate_demodulate_test():

  print '-------Setup-------'
  symbols = cvec('1+1i, 1-1i, -1-1i, -1+1i')
  symbols *= 1.0/np.sqrt(2)
  bits2symbol = ivec('0, 1, 2, 3')
  modulator_ = modulator_2d(symbols, bits2symbol)
  print 'Successfully created modulator_2d object.'
  print 'Constellation:', modulator_.get_symbols()
  print 'Values to constellation mapping:', modulator_.get_bits2symbols()
  
  print '-------Date Modulation-------'
  input_data = random.randi(10, 0, 3) # size, low, high
  modulated_data = modulator_.modulate(input_data)
  print 'Input:', input_data
  print 'Modulated, return by value:', modulated_data
  modulated_data = cvec()
  modulator_.modulate(input_data, modulated_data)
  print 'Modulated, pass by reference:', modulated_data
  
  print '-------Data Demodulation-------'
  demodulated_data = modulator_.demodulate(modulated_data)
  print 'Demodulated, return by value:', demodulated_data
  demodulated_data = ivec()
  modulator_.demodulate(modulated_data, demodulated_data)
  print 'Demodulated, pass by reference:', demodulated_data
  
  print '-------Bit Modulation-------'
  input_bits = random.randb(20)
  modulated_data = modulator_.modulate_bits(input_bits)
  print 'Input:', input_bits
  print 'Modulated, return by value:', modulated_data
  modulated_data = cvec()
  modulator_.modulate_bits(input_bits, modulated_data)
  print 'Modulated, pass by reference:', modulated_data
  
  print '-------Bit Demodulation-------'
  demodulated_bits = modulator_.demodulate_bits(modulated_data)
  print 'Demodulated, return by value:', demodulated_bits
  demodulated_bits= bvec()
  modulator_.demodulate_bits(modulated_data, demodulated_bits)
  print 'Demodulated, pass by reference:', demodulated_bits
  
  print '-------Soft Bit Demodulation for AWGN Channels-------'
  noise_spectral_density = 1.0
  awgn_noise = random.randn_c(10) # default variance = 1
  modulated_data_noisy = modulated_data + awgn_noise
  print 'Modulated data with AWGN noise', modulated_data_noisy
  demodulated_llr = modulator_.demodulate_soft_bits(modulated_data_noisy, 
                                                    noise_spectral_density, 
                                                    soft_method.LOGMAP)
  print 'Demodulated LLR, return by value:', demodulated_llr
  demodulated_llr= vec()
  modulator_.demodulate_soft_bits(modulated_data_noisy, 
                                  noise_spectral_density,
                                  demodulated_llr,
                                  soft_method.LOGMAP)
  print 'Demodulated LLR, pass by reference:', demodulated_llr
  
  print '-------Approximate Soft Bit Demodulation for AWGN Channels-------'
  demodulated_llr = modulator_.demodulate_soft_bits(modulated_data_noisy, 
                                                    noise_spectral_density, 
                                                    soft_method.APPROX)
  print 'Demodulated LLR, return by value:', demodulated_llr
  demodulated_llr= vec()
  modulator_.demodulate_soft_bits(modulated_data_noisy, 
                                  noise_spectral_density,
                                  demodulated_llr,
                                  soft_method.APPROX)
  print 'Demodulated LLR, pass by reference:', demodulated_llr
  
  print '-------Soft Bit Demodulation for Fading Channels-------'
  print 'Demodulator for fading channels not tested, write test case here'
  
if __name__ == '__main__':
    print '-------Testing modulator_2d (complex-valued constellation)-------'
    modulator_2d_modulate_demodulate_test()