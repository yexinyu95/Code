import numpy as np
import matplotlib.pyplot as plt

#arcsin
t = np.arange(0., 1., 0.01)
plt.plot(t, np.arcsin(t))
'''plt.contour(x, y, (y - np.arctan(x)), [0])'''

plt.show()

'''
#log
t = np.arange(0.1, 5., 0.01)
plt.plot(t, np.log(t))

#regular
t = np.arange(-5., 5., 0.01)
plt.plot(t, t**2)

#fraction
t = np.arange(0.1, 5., 0.01)
plt.plot(t, t**(-1))

#sin
t = np.arange(-5., 5., 0.01)
plt.plot(t, np.cos(t))

#exp
t = np.arange(-5., 5., 0.01)
plt.plot(t, np.exp(-t ** 2))
plt.plot(t, 2**t)

#multi
t = np.arange(0., 5., 0.01)
plt.plot(t, t, 'r--', t, t**2, 'bs', t, t**3, 'g^')

#or just type twice
plt.plot(t, t**2)
plt.plot(t, 2**t)

plt.contour(x, y, (x**3 + y**3 + 3*x*y), [0])
plt.contour(x, y, ((x**2 + y**2)**3 - y**4), [0])


#polar
r = np.arange(0, 2, 0.01)
theta = 2 * np.pi * r

#change axes
fig, ax = plt.subplots(subplot_kw=dict(projection="polar"))
ax.plot(theta, 2 * (1 + np.cos(theta)))

#axes settings
ax.set_rlim(0, 2)
ax.set_rticks([0.5, 1, 1.5, 2]) 



#others
x = np.linspace(-5, 5, 400)
y = np.linspace(-5, 5, 400)
x, y = np.meshgrid(x, y)

def axes():
	plt.axhline(0, alpha = .1)
	plt.axvline(0, alpha = .1)
	
axes()
plt.contour(x, y, (x**3 + y**3 + 3*x*y), [0])
plt.contour(x, y, ((x**2 + y**2)**3 - y**4), [0])


#plt.show()
'''