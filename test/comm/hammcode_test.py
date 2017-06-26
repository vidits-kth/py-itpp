# COPYRIGHT_NOTICE

from py_itpp import bvec
from py_itpp import random
from py_itpp import BERC
from py_itpp import hamming_code

def hammcode_encode_decode_test():
    print '-------Creating hamming_code instance-------'
    k = 3 # (7,4) Hamming code
    hamm = hamming_code(k) 
    print 'rate', hamm.get_rate()
    print 'k', hamm.get_k()
    print 'n', hamm.get_n()
    print 'itpp::mat not implemented. Update testcase for get_H and get_G.'

    print '-------Encoding bits-------'
    nrof_bits = 10000 * k
    bits = random.randb(nrof_bits)
    print 'nrof uncoded bits', nrof_bits
    encoded_bits = hamm.encode(bits)
    print 'nrof encoded bits, by value', encoded_bits.length()
    encoded_bits_byref = bvec()
    hamm.encode(bits, encoded_bits_byref)
    print 'nrof encoded bits, by reference', encoded_bits_byref.length()
    
    print '-------Decoding bits-------'
    decoded_bits = hamm.decode(encoded_bits)
    print 'nrof decoded bits, by value', decoded_bits.length()
    decoded_bits_byref = bvec()
    hamm.decode(encoded_bits_byref, decoded_bits_byref)
    print 'nrof decoded bits, by reference', decoded_bits_byref.length()
    err = BERC.count_errors(bits, decoded_bits, 0, 0, 0)
    print 'errors, enc/dec by value', err
    err = BERC.count_errors(bits, decoded_bits_byref, 0, 0, 0)
    print 'errors, enc/dec by reference', err
    
if __name__ == '__main__':
    print '-------Testing Hamming Codes-------'
    hammcode_encode_decode_test()