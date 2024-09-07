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
	int n,i,ch;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],copy[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your entered array elements are\n");
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
		printf("main menu\n");
		printf("1.traversal\n2.search\n3.reversal\n4.insertion\n5.deletion\n6.exit\n");
		printf("enter your ch\n");
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
	printf("after traversing the array is below\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void search(int a[],int n)
{
	int key,i,flag=0,loc;
	printf("enter your search element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			loc=i;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("search element not found\n");
	}
	else
	{
		printf("%d found at %d",key,loc);
	}
}
void reversal(int a[],int n)
{
	int i;
	printf("after reversing the array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
}
void insertion(int a[],int n)
{
	int i,loc,key;
	printf("enter the location at which you want to insert the element\n");
	scanf("%d",&loc);
	printf("enter the element to be inserted\n");
	scanf("%d",&key);
	n++;
	i=n-1;
	while(i>loc)
	{
		a[i]=a[i-1];
		i--;
	}
	a[loc]=key;
	printf("after insertion the array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void deletion(int copy[],int n)
{
	int i,val,loc,flag=0;
	printf("enter the value which you want to delete\n");
	scanf("%d",&val);
	for(i=0;i<n;i++)
	{
		if(copy[i]==val)
		{
			flag=1;
			loc=i;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("value not found\n");
	}
	else
	{
		i=loc;
		while(i<n-1)
		{
			copy[i]=copy[i+1];
			i++;
		}
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",copy[i]);
	}
}
