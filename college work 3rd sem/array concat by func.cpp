/*array concatination by func*/
#include<stdio.h>
void concatination(int a1[],int b1[],int c1[],int n,int m);
int main()
{
	int c[200];
	int n,m,i;
	printf("enter the value of  n of 1st array\n");
	scanf("%d",&n);
	printf("enter the value of m of 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m];
	concatination(a,b,c,n,m);
	return 0;
}
void concatination(int a1[],int b1[],int c1[],int n,int m)
{
	int i,j;
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a1[i]);
		c1[i]=a1[i];
		
	}
	int k=i;
	printf("enter the values of 2nd array\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b1[i]);
		c1[k]=b1[i];
		k++;
	}
	printf("the merged array is\n");
	for(i=0;i<n+m;i++)
	{
		printf("%d\n",c1[i]);
	}
	
}
