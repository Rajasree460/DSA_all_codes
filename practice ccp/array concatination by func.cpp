/*array concatination by func*/
#include<stdio.h>
void concatination(int a[],int b[],int n,int m,int c[]);
int main()
{
	int n,m,i;
	printf("enter the value of n for 1st array\n");
	scanf("%d",&n);
	printf("enter the value of m for the 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m],c[n+m];
	concatination(a,b,n,m,c);
	return 0;
}
void concatination(int a[],int b[],int n,int m,int c[])
{
	int i,j;
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	int k=i;
	printf("enter the values for 2nd array\n");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&b[i]);
    	c[k]=b[i];
    	k++;
	}
	printf("after concatination the resultant array is\n");
	for(j=0;j<m+n;j++)
	{
		printf("%d\n",c[j]);
	}
}
