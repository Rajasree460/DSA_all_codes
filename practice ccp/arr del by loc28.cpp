/*array del by loc*/
#include<stdio.h>
void deletion(int a[],int n);
int main()
{
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your entered array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	deletion(a,n);
}
void deletion(int a[],int n)
{
	int i,loc;
	printf("enter the loc from which you want to delete data\n");
	scanf("%d",&loc);
	for(i=loc;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	printf("after deletion array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
