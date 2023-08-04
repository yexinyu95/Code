print('take a guess of a number between 1 and 20')


while (True):
    num = int(input('your number: '))
    
    if num == 10:
        print('you are right')
        break
    elif num < 10:
        print('your guess is too low')
    else:
        print('your guess is too high')
        
    
