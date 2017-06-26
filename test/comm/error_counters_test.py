# COPYRIGHT_NOTICE

from py_itpp import bvec
from py_itpp import random
from py_itpp import BERC, BLERC

def bit_error_counter_test():
    print '-------Creating BERC instance-------'
    indelay = 0
    inignorefirst = 0
    inignorelast = 0 
    berc = BERC(indelay, inignorefirst, inignorelast)
    
    print '-------Creating random binary vectors-------'
    in1 = random.randb(1000)
    in2 = random.randb(1000)
    
    print '-------Counting bit errors-------'
    berc.count(in1, in2)
    print 'errors', berc.get_errors()
    print 'corrects', berc.get_corrects()
    print 'total_bits', berc.get_total_bits()
    print 'errorrate', berc.get_errorrate()
    print 'count_errors', berc.count_errors(in1, in2, indelay, inignorefirst, inignorelast)
   
    print '-------Counting bit errors with delayed vector-------'
    print 'Testcase not implemented'

def block_error_counter_test(block_size):
    print '-------Creating BLERC instance-------'
    blerc = BLERC(block_size)
    
    print '-------Creating random binary vectors-------'
    in1 = random.randb(1000 * block_size)
    in2 = random.randb(1000 * block_size)
    
    print '-------Counting block errors-------'
    blerc.count(in1, in2)
    print 'block_size', block_size
    print 'errors', blerc.get_errors()
    print 'corrects', blerc.get_corrects()
    print 'total_blocks', blerc.get_total_blocks()
    print 'errorrate', blerc.get_errorrate()
    
    print '-------Counting block errors for new block size-------'
    blerc.clear()
    blerc.set_blocksize(block_size * 2, False)
    blerc.count(in1, in2)
    print 'block_size', block_size * 2
    print 'errors', blerc.get_errors()
    print 'corrects', blerc.get_corrects()
    print 'total_blocks', blerc.get_total_blocks()
    print 'errorrate', blerc.get_errorrate()
    
if __name__ == '__main__':
    print '-------Testing Bit Error Counter-------'
    bit_error_counter_test()
    
    print '-------Testing Block Error Counter-------'
    block_size = 4
    block_error_counter_test(block_size)