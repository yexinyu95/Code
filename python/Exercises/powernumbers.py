def powernumber(num, powers):
    '''check if a given number can be decomposed to two powernumbers'''
    
    #make a poerlist by given powers
    powerlist = []
    for i in range(0, 100):
        powerlist.append(i ** powers)
    
    #make a numberlist to record to results
    numberslist  = []

    #calculate to half of given number to save running time
    for j in range(0, 100):
        if num - powerlist[j] > num // 2:
            if (num - powerlist[j]) in powerlist:
                numberslist.append((num, (powerlist[j], num - powerlist[j])))

    return numberslist

print(powernumber(4104, 3))