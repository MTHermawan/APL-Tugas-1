import numpy as np
import matplotlib.pyplot as plt

def segitigaMatrix(n):
    matrix = np.zeros((n, n), dtype=int)
    for i in range(n):
        for j in range(n):
            if i > j:
                matrix[i, j] = 1
            elif i < j:
                matrix[i, j] = 9
    return matrix

def visBox(matrix):
    n = len(matrix)
    fig, ax = plt.subplots()
    ax.set_xticks(np.arange(n + 1) - 0.5, minor=True)
    ax.set_yticks(np.arange(n + 1) - 0.5, minor=True)
    ax.grid(which="minor", color="white", linestyle='-', linewidth=2)
    ax.tick_params(which="minor", size=0)
    
    cmap = plt.cm.Blues
    ax.imshow(matrix, cmap=cmap, origin="upper")
    
    for i in range(n):
        for j in range(n):
            ax.text(j, i, matrix[i, j], ha='center', va='center', color='black', fontsize=16, fontweight='bold')
    
    plt.xticks([])
    plt.yticks([])
    plt.show()

n = 5  
matrix = segitigaMatrix(n)
visBox(matrix)
