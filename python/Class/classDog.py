class Dog():
    '''an attempt to simulate dog'''

    cm1 = 0.8

    def __init__(self, name = 'alice', age = 5):
        '''initiation attribute name and age'''
        self.name = name
        self.age = age
    
    def __str__(self) -> str:
        return(str(self.age) + self.name)

    def sit(self, action1 = 'sitting'):
        print(self.name + ' is now ' + action1)

    def roll_over(self):
        print(self.name + 'rolled over!')


class DogWeight(Dog):
    def __init__(self, name = 'alice', age = 5, weight = 10):
        super().__init__(name, age)
        self.weight = weight * Dog.cm1
    
    def change_weight(self, weight2):
        self.weight = weight2

Dog.weight2 = 0.9

dog_1 = Dog('ann', 10)

dog_2 = DogWeight('any', 10, 20)

print(dog_2)




