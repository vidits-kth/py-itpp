# COPYRIGHT_NOTICE

from py_itpp import mat, imat, cmat, bmat, mat_np
import numpy as np

def setup_teardown_test(mat_):
    
    print '-------Testing setup and teardown of-------', mat_
    print '--Create mat based on number of rows and columns--'
    rows = 3
    cols = 7
    m = mat_(rows, cols)
    print 'rows', m.rows()
    print 'cols', m.cols()
    print m.get(1, 2)
    del m
        
    print '--Create mat based on string input--'
    m = mat_('40 3 10;'
             '48 7 12;'
             '56 19 42;'
             '64 7 16;')
    print 'mat', m
    
    print '--Convert mat to np array--'
    m_np = mat_np(m)
    print 'mat_np', m_np
    
    del m, m_np
    
if __name__ == '__main__':
    
    '''Create and destroy objects'''
    setup_teardown_test(imat)
    setup_teardown_test(mat)
    setup_teardown_test(cmat)
    
    m = bmat('1 0 1;'
             '0 0 0;'
             '0 0 1;'
             '1 1 1')
    
    print 'bmat example', m
    print 'bmat to numpy', mat_np(m)