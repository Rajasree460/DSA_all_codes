/*array searching of multiple occurance*/
#include<stdio.h>
void search(int a[],int b[],int n);
int main()
{
	int n,i,k;
	printf("entrr the value of n\n");
	scanf("%d",&n);
	int a[n],b[k];
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
	search(a,b,n);
}
void search(int a[],int b[],int n)
{
	int i,j=0,count=0,key;
	printf("enter the search element\n");
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
		printf("key not found\n");
	}
}
