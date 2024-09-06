/*linear & binary search*/
#include<stdio.h>
#include<stdlib.h>
void linear_search(int a[],int n);
void binary_search(int a[],int n);
int main()
{
	int ch,i,n;
	printf("enter the size of array(n)\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	while(ch!=3)
	{
		printf("MAIN MENU\n");
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
	int i,key,location,flag=0;
	printf("enter your search element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			location=i;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("search unccessfull\n");
	}
	else
	{
		printf("search successful,%d found at location %d\n",key,location);
	}
}
void binary_search(int a[],int n)
{
	int key,first,last,mid,i,temp,j;
	printf("enter your search element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
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
			printf("%d found at %d\n",key,mid);
			break;
		}
		else
		{
			last=mid-1;
		}
		mid=(first+last)/2;
		if(first>last)
		{
			printf("key not found\n");
		}
	}
}
