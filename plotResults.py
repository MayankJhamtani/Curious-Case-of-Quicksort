import matplotlib.pyplot as plt
import numpy as np
import csv

def plotData(filename,elements,samples):
    '''This function plots the simple data as a function of the x index'''
    x= np.loadtxt(filename, unpack=True)
    plt.plot(x, label='Loaded from file!')
    plt.xlabel('Running time(s)')
    plt.ylabel('Frequency')
    plt.title('Running time of Quicksort for various permutations')
    plt.legend()
    plt.show()



def plotHistogram(filename,elements,samples,bin_type):
    '''This function plots the simple data as a function of the x index'''
    data = np.loadtxt(filename, unpack=False)
    binwidth=1
    # plt.hist(data, bins=range(int(min(data)), int(max(data)) + int(binwidth), binwidth))
    plt.hist(data,bins=bin_type)
    plt.xlabel('Running time(s)')
    plt.ylabel('Frequency')
    plt.title('Running time of Quicksort for various permutations')
    plt.legend()
    plt.show()


plotHistogram("output2.txt", 100000, 1000,"auto")
plotHistogram("output2.txt", 100000, 1000,"fd")
plotHistogram("output2.txt", 100000, 1000,"scott")
plotHistogram("output2.txt", 100000, 1000,"sturges")
plotHistogram("output2.txt", 100000, 1000,"stone")
plotHistogram("output2.txt", 100000, 1000,"rice")
plotHistogram("output2.txt", 100000, 1000,"doane")

# plotHistogram("randomData.txt",-1,-1)
