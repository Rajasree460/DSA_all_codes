/*arry searching for multiple occurance of same element*/
#include<stdio.h>
void search(int a[],int n);
int main()
{
	int n,i;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	search(a,n);
	return 0;
}
void search(int a[],int n)
{
	int i,key,j=0,count=0;
	int b[j];
	printf("enter your search(key)element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			b[j]=i+1;
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
