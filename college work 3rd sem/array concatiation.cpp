/*array concatination*/
#include<stdio.h>
int main()
{
	int n,m,i,j,k=0;
	printf("enter the value of n for 1st element\n");
	scanf("%d",&n);
	printf("enter the value of m for 2nd element\n");
	scanf("%d",&m);
	int a[n],b[j],c[k];
	printf("enter the values for 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the values for 2nd array\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	while(i<n)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	k=i;
	while(j<m)
	{
		c[k]=b[j];
		k++;
		j++;
	}
	printf("the resultant array is\n");
	for(k=0;k<(m+n);k++)
	{
		printf("%d\n",c[k]);
	}
	return 0;
}
