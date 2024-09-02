/*array deletion*/
#include<stdio.h>
int main()
{
	int n,i,key,location,found;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("enter the value of element to be deleted\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{

		if(a[i]==key)
		{
			found=1;
			location=i;
			break;
		}
		else
		{
			found=0;
		}
	
	}
	if(found==0)
	printf("SEARCH UNSUCCESSFUL:element not found,deletion is not possible\n");
	else
	while(location<n)
	{
		a[location]=a[location+1];
		location++;
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
