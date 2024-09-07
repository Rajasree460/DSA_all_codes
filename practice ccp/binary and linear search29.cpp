/*linear & binary search*/
#include<stdio.h>
#include<stdlib.h>
void linear_search(int a[],int n);
void binary_search(int a[],int n);
int main()
{
	int ch,n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n];
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
	while(ch!=3)
	{
		printf("main menu\n");
		printf("1.linear search\n2.binary search\n3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:linear_search(a,n);
			break;
			case 2:binary_search(a,n);
			break;
			case 3:exit(0);
			default:
				printf("invalid ch\n");
		}
	}
}
void linear_search(int a[],int n)
{
	int i,loc,key,flag=0;
	printf("enter your search element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			loc=i+1;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("key not found\n");
	}
	else
	{
		printf("%d found at loc:%d\n",key,loc);
	}
}
void binary_search(int a[],int n)
{
	int i,j,temp,key,mid,first,last;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("sorted array in asending order is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("enter your search element\n");
	scanf("%d",&key);
	first=0;
	last=n-1;
	mid=(first+last)/2;
	while(first<=last)
	{
		if(a[mid]<key)
		{
			first=mid+1;
		}
		else if(a[mid]==key)
		{
			printf("key found at %d\n",mid+1);
			break;
		}
		else
		{
			last=mid-1;
		}
		mid=(first+last)/2;
	}
	if(first>last)
	{
		printf("key not found\n");
	}
}
