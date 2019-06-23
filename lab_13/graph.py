#!/usr/bin/python
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt

def graph(name, filename, color):
    f = open(filename, 'rb')
    year = []
    temp = []

    for line in f:
        massiv = line.split()
        if int(massiv[1]) != 0:
            year.append(int(massiv[0]))
            temp.append(float(massiv[1])/10)
    f.close()
    plt.title(name)
    plt.plot(year, temp, color)
    plt.show()


def main():
    graph(u'Екатеринбург', 'EKB.txt', 'y')
    graph(u'Санкт-Петербург', 'SPB.txt', 'b')
    graph(u'Сочи', 'STC.txt', 'r')

if __name__ == "__main__":
    main()
