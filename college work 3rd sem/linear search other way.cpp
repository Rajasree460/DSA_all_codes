/*array searching(linear search)*/
#include<stdio.h>
int main()
{
	int n,i,found,location,key;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter your key(search)element\n");
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
	printf("SEARCH UNSUCCESSFUL:element not found\n");
	else
	printf("SEARCH SUCCESSFUL:%d is present at place %d",key,(location+1));
	return 0;
}
