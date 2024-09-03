/*stack*/
#include<stdio.h>
int main()
{
	int n,top=-1;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[++top]);
	}
	printf("array elements are\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	if(top==n)
	printf("stack is full\n");
	return 0;
}

