/*array traversal*/
#include<stdio.h>
int main()
{
	int n,i;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
