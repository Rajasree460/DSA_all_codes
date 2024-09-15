#mm for large dim
import numpy as np
def split(mat):
    r,c=mat.shape
    r2,c2=r//2,c//2
    return mat[:r2,:c2],mat[:r2,c2:],mat[r2:,:c2],mat[r2:,c2:]

def mm(A,B):
    if len(A)==1: #base condition when 1x1 mat
        return(A*B)
    
    a,b,c,d=split(A)
    e,f,g,h=split(B)
    c11=mm(a,e)+mm(b,g)
    c12=mm(a,f)+mm(b,h)
    c21=mm(c,e)+mm(d,g)
    c22=mm(c,f)+mm(d,h)
    
    C=np.vstack((np.hstack((c11,c12)),np.hstack((c21,c22))))
    return C

def printf(mat):
    r,c=mat.shape
    for i in range(r):
        for j in range(c):
            print(mat[i][j],end=" ")
        print()
    print()
    #or,other way
    # for i in mat:
    #     print(i)   
    
def readmat():
    r=int(input("enter the no. of rows: ")) 
    c=int(input("enter the no. of cols: "))
    print("enter (rxc) no. of eles at one line seperated by space")
    eles=list(map(int,input().split()))
    mat=np.array(eles).reshape(r,c)
    print(mat)
    return mat

#main func
A=readmat()
B=readmat()
C=mm(A,B)
print("the resultant matrix is:")
printf(C)        