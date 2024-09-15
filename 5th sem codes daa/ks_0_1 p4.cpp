//knapsack 0/1
#include<stdio.h>

int n=0,c=0;

int knapsack_0_1(int p[],int w[]);

int main(){
	int i,p[20],w[20];
	printf("enter the no. of objs(size of both weight & profit): ");
	scanf("%d",&n);
	printf("\nenter the weights & profits");
	for(i=0;i<n;i++){
		printf("\nweight[%d]: ",i+1);
		scanf("%d",&w[i]);
		printf("profit[%d]: ",i+1);
		scanf("%d",&p[i]);
	}
	printf("\nenter the capacity: ");
	scanf("%d",&c);
	int max=knapsack_0_1(p,w);
	printf("\nMax profit: %d\n",max);
	return 0;
}

int knapsack_0_1(int p[],int w[]){
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
			if((w[i-1]<=j) && ((p[i-1]+ks[i-1][j-w[i-1]])>ks[i-1][j])){
				ks[i][j]=p[i-1]+ks[i-1][j-w[i-1]];
			}
			else{
				ks[i][j]=ks[i-1][j];
			}
		}
	}
	
	printf("\nthe matrix is\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=c;j++){
			printf("%d ",ks[i][j]);
		}
		printf("\n");
	}
	
	//backtracking to find selected items
	i=n;
	j=c;
	while(i>0 && j>0){
		if(ks[i][j]!=ks[i-1][j]){
			printf("object %d selected(weight: %d,profit: %d)\n",i,w[i-1],p[i-1]);
			j-=w[i-1];
			i--;
		}
		else{
			i--;
		}
	}
	return ks[n][c];
}
