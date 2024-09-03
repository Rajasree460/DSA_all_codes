/*array insertion*/
#include<stdio.h>
int main()
{
	int n,i,key,location;
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
	printf("enter the location of new element to be inserted\n");
	scanf("%d",&location);
	printf("enter the value of new element to be inserted\n");
	scanf("%d",&key);
	n++;
	for(i=n-1;i>=location;i--)
	{
		a[i]=a[i-1];
	}
	a[location]=key;
	printf("after inserrtion the array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
