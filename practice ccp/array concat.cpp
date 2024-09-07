/*array concatination*/
#include<stdio.h>
void concatination(int a[],int n,int b[],int m,int c[]);
int main()
{
	int c[200];
	int n,m;
	printf("enter the size of 1st array\n");
	scanf("%d",&n);
	printf("enter the size of 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m];
	concatination(a,n,b,m,c);
}
void concatination(int a[],int n,int b[],int m,int c[])
{
	int i,j;
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	int k=i;
	printf("enter the values of 2nd array\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
		c[k]=b[j];
		k++;
	}
	printf("after concatination the array is\n");
	for(i=0;i<m+n;i++)
	{
		printf("%d\n",c[i]);
	}
}
