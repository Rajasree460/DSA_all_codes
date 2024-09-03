/*array reversal*/
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
	printf("after reversing array the array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
