while True:
    first_number = input("\nFirst number: ")
    
    if first_number == 'q':
        break
    second_number = input("Second number: ")
    try:
        answer = int(first_number) / int(second_number)
        print(answer)
    
    except IndexError:
        print("You can't divide 0!")

    except ZeroDivisionError:
        print("You can't divide by 0!")

