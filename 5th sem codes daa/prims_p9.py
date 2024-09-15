#prims algo
import numpy as np
INFINITY=999999
N=int(input("enter the no. of vertices: "))
print("enter (NxN) no. of elements in one line seperated by spaces")
eles=list(map(int,input().split()))
G=np.array(eles).reshape(N,N)
print(G)

visited=[0,0,0,0,0,0,0]
visited[0]=True 
no_edges=0
mincost=0

while no_edges<N-1:
    u=0
    v=0
    min=INFINITY
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
    mincost+=G[u][v]
    no_edges=no_edges+1
    
print("min cost: ",mincost)                       