/*array concatination*/
#include<stdio.h>
void concatination(int a[],int b[],int c[],int n,int m);
int main()
{
	int c[200];
	int n,m;
	printf("enter the value of n for 1st array\n");
	scanf("%d",&n);
	printf("enter the value of m for the 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m];
	concatination(a,b,c,n,m);
}
void concatination(int a[],int b[],int c[],int n,int m)
{
	int i,j;
	printf("enter the values for 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	int k=i;
	printf("enter the values for 2nd array\n");
	for(i=0;j<m;j++)
	{
		scanf("%d",&b[j]);
		c[k]=b[j];
		k++;
	}
	printf("the resultant array\n");
	for(i=0;i<n+m;i++)
	{
		printf("%d\n",c[i]);
	}
}
