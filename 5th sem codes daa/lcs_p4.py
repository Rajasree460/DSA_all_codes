#lcs
def lcs(X,Y):
    m=len(X)
    n=len(Y)
    C=[[0]*(n+1) for i in range(m+1)]
    
    for i in range(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                C[i][j]=0
            elif X[i-1]==Y[j-1]:
                C[i][j]=C[i-1][j-1]+1
            else:
                C[i][j]=max(C[i-1][j],C[i][j-1])
    
    #print C
    for i in range(m+1):
        for j in range(n+1):
            print(C[i][j],end=" ")
        print()
    print()
    #or,other way
    # for i in C:
    #     print(i)   
    
    return C[m][n]

#main func
X=input("enter the 1st string: ")
print("1st string: ",X)
Y=input("enter the 2nd string: ")
print("2nd string: ",Y)  
print("length of lcs is: ",lcs(X,Y))                      