/*array deletion by location*/
#include<stdio.h>
void deletion(int a[],int n);
int main()
{
	int n,i;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your entered array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	deletion(a,n);
	return 0;
}
void deletion(int a[],int n)
{
	int i,location;
	printf("enter the location of the element to be deleted\n");
	scanf("%d",&location);
	if(location>=n)
	{
		printf("deletion not possible\n");
	}
	else
	{
		for(i=location;i<n;i++)
		{
			a[i]=a[i+1];
		}
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
