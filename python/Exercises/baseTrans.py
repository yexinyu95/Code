def splitNumber(number):
    '''split the given number to a list of it's digit, from left to right'''
    split = []
    end = not(number % 10)

    division = 10

    if type(number) == int:
        
        while((number // division) > 0):
            division = division * 10

        division = division / 10

        while(number > 0):
            digit = number // division
            split.append(int(digit))

            number = number - (division * digit)
            division = division / 10

        if (end):
            split.append(0)
        
        return split

    else:
        return number
    

def todecimal(number, base):
    '''convert a number of 'base' to decimal,'''
    if base > 10 and base != 16:
        return number
    
    elif base == 16:
        hexdict = {'1': 1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'A':10, 'B':11, 'C':12, 'D':13, 'E':14, 'F':15}
        j = len(number) - 1
        hexnum = 0
        k = 0
        while k < len(number):
            hexnum = hexnum + hexdict[number[k]] * (16 ** j)  
            j = j - 1
            k = k + 1
        return hexnum
    
    else:
        if type(number) == int:
            i = 1
            while number - (10 ** i) > 0:
                i = i + 1
            i = i - 1
            
            num = 0
            while i >= 0:
                temp1 = number // (10 ** i)
                if temp1 >= base:
                    num = 0
                    break
                else:
                    num = num + temp1 * (base ** i)
                    number = number - temp1 * (10 ** i)
                    i = i - 1
        else:
            return number
            
        return num

def fromdecimal(number, base):
    '''conver a number from decimal to 'base','''
    if base > 10 and base != 16:
        return number
    
    elif base == 16:
        hexdec = ['1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
        j = 1
        while number - (16 ** j) > 0:
            j = j + 1
        j = j - 1

        hexlist = []
        while j >= 0:
            temp1 = number // (16 ** j)
            hexlist.append(hexdec[temp1 - 1])
            number = number - temp1 * (16 ** j)
            j = j - 1
        hexstr = ''
        hexstr = hexstr.join(hexlist)

        return hexstr

    else:
        i = 1
        while number - (base ** i) > 0:
            i = i + 1
        i = i - 1
        
        num = 0
        while i >= 0:
            temp1 = number // (base ** i)
            num = num + temp1 * (10 ** i)
            number = number - temp1 * (base ** i)
            i = i - 1
            
        return num

def convert(number, startbase, endbase):
    '''convert a number from startbase to endbase,'''
    temp = todecimal(number, startbase)
    output = fromdecimal(temp, endbase)

    return output


if __name__ == "__main__":
    print(splitNumber(123090))
