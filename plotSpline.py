# plot spline points
import numpy as np
import matplotlib.pyplot as plt


from mpl_toolkits import mplot3d

ptsX = []
ptsY = []
ptsZ = []

PtsX = []
PtsY = []
PtsZ = []

# read the file
def readFile(fileName, cp):
    f = open(fileName, "r")
    for x in f:
        #print(x.split(",",2))
        y = x.split(",",2)
        y[2] = y[2].rstrip()
        #y = list(x)
        print(float(y[0]), float(y[1]), float(y[2]))
        ptsX.append(float(y[0]))
        ptsY.append(float(y[1]))
        ptsZ.append(float(y[2]))
     
    f1 = open(cp, "r")

    for x in f1:
        d = x.split(",",2)
        d[2] = d[2].rstrip()
        print(d[0],d[1])
        PtsX.append(float(d[0]))
        PtsY.append(float(d[1]))
        PtsZ.append(float(d[2]))


    figs, axs = plt.subplots(1)
    plt.plot(PtsX, PtsY, "g")
    plt.plot(ptsX, ptsY, "r")
    plt.show()

    fig = plt.figure()
    ax = plt.axes(projection='3d')

    ax.plot3D(ptsX, ptsY, ptsZ, 'gray')
    #ax.plot3D(PtsX, PtsY, PtsZ, 'red')
    plt.show()

readFile("data.txt", "dataControlPoints.txt")