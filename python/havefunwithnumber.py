def doubleNumber(num):
    length = len(num)

    result = []
    step = 0

    for i in range (length-1, -1, -1):
        temp = (int)(num[i]) *2 + step
        if (temp >  10 or temp == 10):
            result.append(str(temp-10))
            step = 1
        else:
            result.append(str(temp))
            step = 0

    if step == 1:
        result.append('1')

    return result

def reverseList(lista):
    length = len(lista)
    for i in range(0, length//2):
        (lista[i], lista[length-1-i]) = (lista[length-1-i], lista[i])

def sortString (stra):
    lista = []
    for i in range(0, len(stra)):
        lista.append(stra[i])
    lista.sort()
    strb = ''.join(lista)
    return strb

numstr = input()

resa = sortString(numstr)
#print(resa)

tempList = doubleNumber(numstr)
tempStr = ''.join(tempList)
resb = sortString(tempStr)
#print(resb)

if(resa == resb):
    print('Yes')
else:
    print('No')


#for i in range(len(res) - 1, -1, -1):
#    print(res[i], end='')
