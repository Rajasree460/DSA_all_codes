/*array searching for multiple occurance of same element*/
#include<stdio.h>
int main()
{
	int key,n,i,j=0,count=0,k;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n],b[k];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value of key\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			b[j]=i;
			j++;
			count++;
		}
	}
	if(count>0)
	{
		printf("%d found at location:\n",key);
		for(j=0;j<count;j++)
		{
			printf("%d\n",b[j]);
		}
	}
	else
	{
		printf("key don not found\n");
	}
	return 0;
}
