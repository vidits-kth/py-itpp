# COPYRIGHT_NOTICE

from py_itpp import vec, cvec, ivec, bvec
from py_itpp import random
from py_itpp import transforms

def transforms_test():
    print '-------Testing fft-------'
    in_ = random.randn_c(10)
    print 'in_', in_
    out_ = cvec()
    transforms.fft(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.fft(in_)
    print 'out_ with in_ padding',transforms.fft(in_, 20)

    print '-------Testing ifft-------'
    in_ = out_ # flip the input and outputs from above
    out_ = cvec()
    transforms.ifft(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.ifft(in_)
    print 'out_ with in_ padding',transforms.ifft(in_, 20)

    print '-------Testing fft_real-------'
    in_ = random.randn(10)
    print 'in_', in_
    out_ = cvec()
    transforms.fft_real(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.fft_real(in_)
    print 'out_ with in_ padding',transforms.fft_real(in_, 20)

    print '-------Testing ifft_real-------'
    in_ = out_ # flip the input and outputs from above
    out_ = vec()
    transforms.ifft_real(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.ifft_real(in_)
    print 'out_ with in_ padding',transforms.ifft_real(in_, 20)    

    print '-------Testing dct-------'
    in_ = random.randn(10)
    print 'in_', in_
    out_ = vec()
    transforms.dct(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.dct(in_)
    
    print '-------Testing idct-------'
    in_ = out_ # flip the input and outputs from above
    out_ = vec()
    transforms.idct(in_, out_)
    print 'out_ by reference', out_
    print 'out_ by value', transforms.idct(in_)
    
if __name__ == '__main__':
    print '-------Testing transforms-------'
    transforms_test()