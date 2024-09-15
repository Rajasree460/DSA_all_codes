#prim's algo
import numpy as np
#N = 7
INFINITY = 99999
N = int(input("Enter the number of vertices: "))
# G = []
# for i in range(N):
#         row = list(map(int, input(f"Enter the weights for edges connected to vertex {i + 1} (separated by spaces): ").split()))
#         G.append(row)

#Enter 49 matrix elements separated by spaces
print("Please write the elements of the matrix in a single line and separated by a space: ")
elems = list(map(int, input().split()))
G = np.array(elems).reshape(N,N)
print(G)

# G = [
#     [0, 28, 0, 0, 0, 10, 0],
#     [28, 0, 16, 0, 0, 0, 14],
#     [0, 16, 0, 12, 0, 0, 0],
#     [0, 0, 12, 0, 22, 0, 18],
#     [0, 0, 0, 22, 0, 25, 24],
#     [10, 0, 0, 0, 25, 0, 0],
#     [0, 14, 0, 18, 24, 0, 0]
# ]

visited = [0, 0, 0, 0, 0, 0, 0]
no_edges = 0
visited[0] = True
mincost = 0

while no_edges < N - 1:
    min = INFINITY
    u = 0
    v = 0
    for i in range(N):
        if visited[i]:
            for j in range(N):
                if (not visited[j] and G[i][j]):
                    if min > G[i][j]:
                        min = G[i][j]
                        u = i
                        v = j
    print(str(u + 1) + "->" + str(v + 1) + ":" + str(G[u][v]))
    visited[v] = True
    mincost = mincost + G[u][v]
    no_edges = no_edges + 1

print("MST COST:", mincost)
