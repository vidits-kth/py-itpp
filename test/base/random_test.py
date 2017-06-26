# COPYRIGHT_NOTICE

from py_itpp import vec, cvec, ivec, bvec
from py_itpp import random

def random_value_generation_test():
    print '-------Testing randb-------'
    print random.randb()
    values = bvec()
    random.randb(10, values)
    print values
    print random.randb(10)
    print 'itpp::bmat not supported yet, add test cases when implemented'
    
    print '-------Testing randu-------'
    print random.randu()
    values = vec()
    random.randu(10, values)
    print values
    print random.randu(10)
    print 'itpp::mat not supported yet, add test cases when implemented'
    
    print '-------Testing randi-------'    
    print random.randi(50, 100)
    print random.randi(10, 50, 100)
    print 'itpp::imat not supported yet, add test cases when implemented'
    
    print '-------Testing randn-------'
    print random.randn()
    values = vec()
    random.randn(10, values)
    print values
    print random.randn(10)
    print 'itpp::mat not supported yet, add test cases when implemented'
    
    print '-------Testing randn_c-------'
    print random.randn_c()
    values = cvec()
    random.randn_c(10, values)
    print values
    print random.randn_c(10)
    print 'itpp::cmat not supported yet, add test cases when implemented'

    print '-------Testing randray-------'    
    print random.randray(10, 1.0)

    print '-------Testing randrice-------'    
    print random.randrice(10, 1.0, 1.0)

    print '-------Testing randexp-------'    
    print random.randexp(10, 1.0)
    
if __name__ == '__main__':
    
    print '-------Testing randon value generation-------'
    random_value_generation_test()