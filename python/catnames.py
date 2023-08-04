catNames = []

while True:
    print('Enter the name of cat ' + str(len(catNames) + 1) + ' (Or enter exit to stop.):')
    name = input()
    if name == 'exit':
        break
    else:
        catNames.append(name)

print('The cat names are:')
for name in catNames:
    print('  ' + name)


