def reverseList(lista):
    length = len(lista)
    for i in range(0, length//2):
        (lista[i], lista[length-1-i]) = (lista[length-1-i], lista[i])

def strAdd(stra, strb):
    lengtha = len(stra)
    lengthb = len(strb)
    
    if (lengtha > lengthb):
        length = lengtha
        strb = '0'*(lengtha - lengthb) + strb
    else:
        length = lengthb
        stra = '0'*(lengthb - lengtha) + stra
    
    tempList = []
    step = 0

    for i in range (length-1, -1, -1):
        temp = int(stra[i]) + int(strb[i]) + step
        if (temp >  10 or temp == 10):
            tempList.append(str(temp-10))
            step = 1
        else:
            tempList.append(str(temp))
            step = 0

    if step == 1:
        tempList.append('1')
        
    reverseList(tempList)
    result = ''.join(tempList)
       
    return result

#not finished
def strMinus(stra, strb):
    lengtha = len(stra)
    lengthb = len(strb)
    
    if (lengtha > lengthb):
        length = lengtha
        strb = '0'*(lengtha - lengthb) + strb
    else:
        length = lengthb
        tempStr = strb
        strb = '0'*(lengthb - lengtha) + stra
        stra = tempStr
        
    tempList = []
    rent = 0

    for i in range (length-1, -1, -1):
        temp = int(stra[i]) - int(strb[i]) - rent
        if (temp < 0):
            tempList.append(str(temp + 10))
            rent = 1
        else:
            tempList.append(str(temp))
            rent = 0

    if rent == 1:
        tempList.append('-')

    reverseList(tempList)
    result = ''.join(tempList)
       
    return result

def deciTobase(num, base):
    tempList = []
    while num:
        temp = num % base
        tempList.append(str(temp))
        num = num // base
    reverseList(tempList)
    result = ''.join(tempList)

    return result

def baseTodeci(num, base):
    num = str(num)
    result = '00'
    for i in range (0, len(num)):
        temp = (int(num[i])) * (base**(len(num)-i-1))
        temp = str(temp)
        result = strAdd(result, temp)
        
    return result


number = int(input())

resultStr = deciTobase(number, 8)
#have problem when input is 0

print(resultStr)

