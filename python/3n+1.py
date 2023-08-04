import sys
inp = input('input a number: ')
numlist = []


try:
    num = int(inp)

except ValueError:
    print('Your input is not a integer')
    sys.exit()

while (num != 1):
    numlist.append(num)
    if (num % 2 == 0):
        num = num // 2
    else:
        num = 3*num + 1

numlist.append(1)

for i in range(0, len(numlist)):
    print(numlist[i])

        
