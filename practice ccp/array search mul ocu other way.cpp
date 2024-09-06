/*arry searching for multiple occurance of same element other*/
#include<stdio.h>
void search(int a[],int b[],int n);
int main()
{
	int n,i,k;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n],b[k];
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	search(a,b,n);
	return 0;
}
void search(int a[],int b[],int n)
{
	int i,key,j=0,count=0;
	printf("enter your search(key)element\n");
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
		printf("%d is found at the location:\n",key);
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
