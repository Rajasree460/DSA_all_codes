/*array concatination*/
#include<stdio.h>
int main()
{
	int c[200];
	int n,m,i;
	printf("enter the value of  n of 1st array\n");
	scanf("%d",&n);
	printf("enter the value of m of 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m];
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
		
	}
	int k=i;
	printf("enter the values of 2nd array\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		c[k]=b[i];
		k++;
	}
	printf("the merged array is\n");
	for(i=0;i<n+m;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}
