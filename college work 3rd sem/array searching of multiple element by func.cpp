/*array searching for multiple occurance of same element*/
#include<stdio.h>
void search(int a1[],int b1[],int n);
int main()
{
	int n,i,k;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n],b[k];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	search(a,b,n);
	return 0;
}
void search(int a1[],int b1[],int n)
{
	int i,key,j=0,count=0;
	printf("enter the value of key\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a1[i]==key)
		{
			b1[j]=i;
			j++;
			count++;
		}
	}
	if(count>0)
	{
		printf("%d found at location:\n",key);
		for(j=0;j<count;j++)
		{
			printf("%d\n",b1[j]);
		}
	}
	else
	{
		printf("key don not found\n");
	}
}
