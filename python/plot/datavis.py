import matplotlib.pyplot as plt

'''
#basic plot
input_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]

plt.plot(input_values, squares, linewidth = 5)

plt.title("Square Numbers", fontsize = 24)
plt.tick_params(axis = 'both', labelsize = 14)

plt.show()
'''

'''
#scatter plot
x_values = list(range(1, 1001))
y_values = [x ** 2 for x in x_values]

plt.scatter(x_values, y_values, c = y_values, 
    cmap = plt.cm.Blues, edgecolor='none')

plt.axis([0, 1100, 0, 1100000])
plt.tick_params(axis='both', which='major', labelsize=14)

plt.show()
'''

from random import choice

class RandomWalk():
    '''a class to generate RandomWalks'''

    def __init__(self, num_points = 5000):
        self.num_points = num_points

        self.x_values = [0]
        self.y_values = [0]
    
    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x_direction = choice([1, -1])
            x_distance  = choice([0, 1, 2, 3, 4])
            x_step      = x_direction * x_distance
            
            y_direction = choice([1, -1])
            y_distance  = choice([0, 1, 2, 3, 4])
            y_step      = y_direction * y_distance

            if x_step == 0 and y_step == 0:
                continue

            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            self.x_values.append(next_x)
            self.y_values.append(next_y)


rw = RandomWalk(50000)
rw.fill_walk()

point_numbers = list(range(rw.num_points))

plt.scatter(rw.x_values, rw.y_values, c = point_numbers, \
    cmap = plt.cm.Blues, s = 15)

plt.scatter(0, 0, c = 'green', s = 100)
plt.scatter(rw.x_values[-1], rw.y_values[-1], c = 'red', s = 100)


plt.show()








        








