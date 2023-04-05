import unittest

#define a funtion to test
def capitalword(text):
    return text.upper()
#    upper method captilize every char, this case should use
#    return text.title()

#inherit a class from unittest.TestCase
class TestFunc(unittest.TestCase):
    def setUp(self):
        pass
    
    def testfunc(self):
        text = 'test of string methods'
        result = capitalword(text)
        self.assertEqual(result, 'Test Of String Methods')


#run as script mode
if __name__ == '__main__':
    unittest.main()