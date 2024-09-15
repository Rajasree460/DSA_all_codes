#prims algo
import numpy as np
INFINITY=99999999
N=int(input("enter the no. of vertices: "))
print("enter (NxN) no. of eles at one line seperated by spaces")
eles=list(map(int,input().split()))
G=np.array(eles).reshape(N,N)
print(G)

visited=[0,0,0,0,0,0,0]
no_edge=0
visited[0]=True
min_cost=0

while no_edge<N-1:
    min=INFINITY
    u=0
    v=0
    for i in range(N):
        if visited[i]:
            for j in range(N):
                if(not visited[j] and G[i][j]):
                    if min>G[i][j]:
                        min=G[i][j]
                        u=i
                        v=j
    print(str(u+1)+"->"+str(v+1)+":"+str(G[u][v]))
    visited[v]=True
    min_cost+=G[u][v]
    no_edge=no_edge+1
print("min cost: ",min_cost)                        