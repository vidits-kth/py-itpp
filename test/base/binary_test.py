from py_itpp import bin

def setup_teardown_test(obj_type):
    print '=========================================================================='
    print 'Testing setup and teardown of ', obj_type
    ival = 1
    
    print 'Default constructor'
    obj = obj_type()
    print obj
    del obj
    print 'Set the binary object equal to \c value. Either "0" or "1".'
    obj = obj_type(ival)
    print obj
    del obj
    print 'Copy constructor'
    obj = obj_type()
    obj1 = obj_type(obj)
    print obj1
    print '=========================================================================='
    del obj, obj1

def logical_operator_test(obj_type):
    print '=========================================================================='
    print 'Testing logical operators for ', obj_type
    obj1 = obj_type(0)
    obj2 = obj_type(1)
    
    print 'OR'
    print obj1 | obj2
    print 'XOR'
    print obj1 ^ obj2
    print 'AND'
    print obj1 & obj2
    print 'NOT'
    print ~obj1
    print '=========================================================================='
    del obj1, obj2

def relational_operator_test(obj_type):
    print '=========================================================================='
    print 'Testing relational operators for ', obj_type
    obj1 = obj_type(0)
    obj2 = obj_type(1)  # Not equal to obj1
    val = 0 # Equal value to obj1
    
    print 'Check if equal'
    print obj1 == obj1
    print obj1 == obj_type(obj1)
    print obj1 == obj2
    print 'Check if equal'
    print obj1 == val
    print obj2 == val
    print 'Check if not equal'
    print obj1 != obj1
    print obj1 != obj_type(obj1)
    print obj1 != obj2    
    print 'Check if not equal'
    print obj1 != val
    print obj2 != val
    print 'Less than (interpret the binary values {0,1} as integers)'
    print obj1 < obj1
    print obj1 < obj2
    print 'Less than equal (interpret the binary values {0,1} as integers)'
    print obj1 <= obj1
    print obj1 <= obj2
    print '=========================================================================='
    del obj1, obj2
    
def data_manipulation_test(obj_type):
    print '=========================================================================='
    print 'Testing data manipulation for ', obj_type
    obj1 = obj_type(0)
    obj2 = obj_type(1)  # Not equal to obj1

    obj1 = obj1 | obj2
    print obj1
    print '=========================================================================='
    del obj1, obj2
    
if __name__ == '__main__':
    '''Create and destroy objects'''
    setup_teardown_test(bin)
        
    '''Logical operators'''
    logical_operator_test(bin)
    
    '''Relational operators'''
    relational_operator_test(bin)

    '''Data manipulation'''
    data_manipulation_test(bin)    