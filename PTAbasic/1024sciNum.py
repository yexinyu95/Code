import sys

#receive input string
inputStr = input()

#split string into different parts
signa = inputStr[0]
numa = inputStr[1]

numb = ''
i = 3
while(inputStr[i] != 'E'):
    numb = numb + inputStr[i]
    i += 1

signb = inputStr[i+1]

numc = int(inputStr[i+2:])

#print first sign
if(signa == '-'):
    print('-', end='')

#check second sign
if(signb == '+'):
    if(len(numb) < numc or len(numb) == numc):
        numb = numb + '0' * (numc - len(numb))
        print(numa + numb)
        sys.exit()
    else:
        print(numa + numb[:numc] + '.' + numb[numc:])

else:
    print('0.' + '0'*(numc-1) + numa, end='')
    print(numb)
    sys.exit()
    

