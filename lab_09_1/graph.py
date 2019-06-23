#!/usr/bin/python
import matplotlib.pyplot as plt

f = open('rand.txt', 'rb')
time = []
strndup = []
mystrndup = []

for line in f:
    massiv = line.split()
    time.append(int(massiv[0]))
    strndup.append(int(massiv[1]))
    mystrndup.append(int(massiv[2]))

f.close()

plt.plot(time, strndup, 'r')
plt.plot(time, mystrndup, 'y')
plt.show()
