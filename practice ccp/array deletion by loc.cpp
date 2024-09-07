/*array deletion by loc*/
#include<stdio.h>
#include<stdlib.h>
void deletion(int a[],int n);
int main()
{
	int n,i;
	printf("enter the size of array\n");
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
	deletion(a,n);
}
void deletion(int a[],int n)
{
	int i,loc;
	printf("enter the locatio from which you want to delete the element\n");
	scanf("%d",&loc);
	while(loc<n-1)
	{
		a[loc]=a[loc+1];
		loc++;
	}
	printf("after deletion array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
