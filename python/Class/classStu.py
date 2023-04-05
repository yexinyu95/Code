class Student():
    '''a class to simulate student'''

    '''const variable used in class'''
    
    def __init__(self, name, age, height, weight):
        '''attribute of student, include name, age, weight, height'''
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight
        

    '''methods of student'''

    def bmi(self, n):
        '''calculate bmi'''
        return self.weight / ((self.height / n) ** 2)  
    
    def __str__(self):
        return '<class \'student\'>'

studenta = Student('Tom', 27, 171.7, 61.6)

Student.score = 60

print(vars(Student))


class Collage(Student):
    '''a class to simulate collage student'''

    def __init__(self, name, age, height, weight, GPA, year):
        '''attribute of college student, append GPA and college year'''
        super().__init__(name, age, height, weight)
        self.GPA = GPA
        self.year = year
    


    