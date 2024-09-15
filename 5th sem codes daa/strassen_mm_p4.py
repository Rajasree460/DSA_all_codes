#strassen's mm
import numpy as np
def split(mat):
    r,c=mat.shape
    r2,c2=r//2,c//2
    return mat[:r2,:c2],mat[:r2,c2:],mat[r2:,:c2],mat[r2:,c2:]

def strassen(A,B):
    if len(A)==1: #base condition when 1x1 mat
        return(A*B)
    
    a,b,c,d=split(A)
    e,f,g,h=split(B)
    
    #computing 7 products recursively
    p1=strassen(a,f-h)
    p2=strassen(a+b,h)
    p3=strassen(c+d,e)
    p4=strassen(d,g-e)
    p5=strassen(a+d,e+h)
    p6=strassen(b-d,g+h)
    p7=strassen(a-c,e+f)
    
    c11=p5+p4-p2+p6
    c12=p1+p2
    c21=p3+p4
    c22=p1+p5-p3-p7
    
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
C=strassen(A,B)
print("the resultant matrix is:")
printf(C)        