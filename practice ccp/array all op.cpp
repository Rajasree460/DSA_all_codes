/*array all op*/
#include<stdio.h>
#include<stdlib.h>
void traversal(int a[],int n);
void search(int a[],int n);
void reversal(int a[],int n);
void insertion(int a[],int n);
void deletion(int copy[],int n);
int main()
{
	int ch,n,i;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n],copy[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your array elements are below\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	for(i=0;i<n;i++)
	{
		copy[i]=a[i];
	}
	while(ch!=6)
	{
		printf("MAIN MENU\n");
		printf("1.traversal\n2.search\n3.reversal\n4.insertion\n5.deletion\n6.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:traversal(a,n);
			break;
			case 2:search(a,n);
			break;
			case 3:reversal(a,n);
			break;
			case 4:insertion(a,n);
			break;
			case 5:deletion(copy,n);
			break;
			case 6:exit(0);
			default:
				printf("invalid ch\n");
		}
	}
}
void traversal(int a[],int n)
{
	int i;
	printf("after traversal the array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void search(int a[],int n)
{
	int i,key,location,flag=0;
	printf("enter the key(search)element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			location=i+1;
			break;
		}
		else
		{
			flag=0;
		}
		
	}
	if(flag==0)
	{
		printf("search unsuccessful,key not found\n");
	}
	else
	{
		printf("search successful,key found at location:%d\n",location);
	}
}
void reversal(int a[],int n)
{
	int i;
	printf("the reversed array is:\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
}
void insertion(int a[],int n)
{
	int i,location,key;
	printf("enter the location of the element where it has to be inserted\n");
	scanf("%d",&location);
	printf("enter the value of the element to be inserted\n");
	scanf("%d",&key);
	n++;
	i=n-1;
	while(i>location)
	{
		a[i]=a[i-1];
		i--;
	}
	a[location]=key;
	printf("after insertion the array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void deletion(int copy[],int n)
{
	int i,key,location,flag=0;
	printf("enter the key element which have to be deleted\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(copy[i]==key)
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
		printf("search unsuccessful,key not found\n");
	}
	else
	{
		while(location<n-1)
		{
			copy[location]=copy[location+1]; //as,i=location
			location++;
		}
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",copy[i]);
	}
}
