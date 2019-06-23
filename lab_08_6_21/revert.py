#!/usr/bin/python
import csv
from numpy.linalg import inv

f = open('rand_matrix.txt', 'rb')

line = f.readline()
massiv = line.split()
matrix = [[0 for j in range(int(massiv[0]))] for i in range(int(massiv[1]))]
fw = open('revert_rand_matrix.txt', 'wb')
fw.write(massiv[0] + ' ' + massiv[1] + '\n')

for line in f:
    massiv = line.split()
    matrix[int(massiv[0]) - 1][int(massiv[1]) - 1] = float(massiv[2])

revert_matrix = inv(matrix)
for i in range(len(revert_matrix)):
    for j in range(len(revert_matrix[i])):
        fw.write(str(round(revert_matrix[i][j], 6)) + ' ')
    fw.write('\n')

fw.close()
f.close()
