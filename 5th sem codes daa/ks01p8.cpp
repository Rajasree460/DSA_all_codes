//ks 0 1
#include<stdio.h>

int n=0,c=0;

int knapsack_0_1(int w[],int p[]);

int main(){
	int w[20],p[20],i;
	printf("enter the no. of objs(size of both weight & profit array): ");
	scanf("%d",&n);
	printf("\nenter weights & profits");
	for(i=0;i<n;i++){
		printf("\nweight[%d]: ",i+1);
		scanf("%d",&w[i]);
		printf("profit[%d]: ",i+1);
		scanf("%d",&p[i]);
	}
	printf("\nenter the capacity: ");
	scanf("%d",&c);
	int max_profit=knapsack_0_1(w,p);
	printf("\nmax profit: %d\n",max_profit);
	return 0;
}

int knapsack_0_1(int w[],int p[]){
	int i,j;
	int ks[n+1][c+1];
	
	for(i=0;i<=c;i++){
		ks[0][i]=0;
	}
	
	for(i=0;i<=n;i++){
		ks[i][0]=0;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=c;j++){
			if((w[i-1]<=j) && (p[i-1]+ks[i-1][j-w[i-1]])>(ks[i-1][j])){
				ks[i][j]=p[i-1]+ks[i-1][j-w[i-1]];
			}
			else{
				ks[i][j]=ks[i-1][j];
			}
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=c;j++){
			printf("%d ",ks[i][j]);
		}
		printf("\n");
	}
	
	//back tracking for finding selected eles
	i=n;
	j=c;
	while(i>0 && j>0){
	if(ks[i][j]!=ks[i-1][j]){
		printf("\nobj %d selected( weight:%d, profit:%d )",i,w[i-1],p[i-1]);
		j-=w[i-1];
		i--;
	}
	else{
		i--;
	}
    }
	return ks[n][c];
}
