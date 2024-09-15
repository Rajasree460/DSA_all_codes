#mcm dp
def print_mat(m):
    for i in m:
        print(i)

def mcm(p):
    n=len(p)-1
    max_val=9999999
    M=[[0 for x in range(n)]for x in range(n)]        
    S=[[0 for x in range(n)]for x in range(n)]   
    
    for i in range(n):
        M[i][i]=0
        
    for L in range(2,n+1):
        for i in range(n-L+1):
            j=i+L-1
            M[i][j]=max_val
            for k in range(i,j):
                q=M[i][k]+M[k+1][j]+p[i]*p[k+1]*p[j+1]
                if q<M[i][j]:
                    M[i][j]=q
                    S[i][j]=k                
                    
    #print M & S
    mp=[[M[i][i]for i in range(n)]]
    for L in range(1,n):
        temp=[M[i][i+L]for i in range(n-L)]
        mp.append(temp)
    
    print("matrix M is")
    print_mat(mp) 
    
    sp=[]
    for L in range(1,n):
        temp=[(S[i][i+L]+1)for i in range(n-L)]
        sp.append(temp)
    
    print("matrix S is")
    print_mat(sp)
    
    return M[0][n-1]
                  
#main func
n1=int(input("enter the no. of matrix dims: "))
p=[]
print("enter the dims")
for i in range(n1):
    l1=int(input())
    p.append(l1)
print("the dim array: ",p)    
print("min no. of scaler muls: ",mcm(p))                           