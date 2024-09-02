/*array deletion*/
#include<stdio.h>
int main()
{
	int n,i,location;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your entered array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("enter the location of new element to be deleted\n");
	scanf("%d",&location);
	if(location>=n+1)
	{
		printf("deletion is not possible\n");
	}
	else
	{
		for(i=location;i<n;i++)
		{
			a[i]=a[i+1];
		}
		printf("after deletion the resultant array is\n");
		for(i=0;i<n-1;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
