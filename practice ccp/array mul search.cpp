/*searching for mul occurance in array*/
#include<stdio.h>
void search(int a[],int n,int b[]);
int main()
{
	int n,i,k;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],b[k];
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
	search(a,n,b);
}
void search(int a[],int n,int b[])
{
	int key,i,j=0,count=0;
	printf("enter your search element\n");
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
		printf("%d found at loc\n",key);
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
