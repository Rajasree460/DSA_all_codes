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
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],copy[n];
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
	for(i=0;i<n;i++)
	{
		copy[i]=a[i];
	}
	while(ch!=6)
	{
		printf("main menu\n");
		printf("1.traversal\n2.search\n3.reversal\n4.insetion\n5.deletion\n6.exit\n");
		printf("enter your ch:\n");
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
	printf("after traversal array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void search(int a[],int n)
{
	int i,key,loc,flag=0;
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
		printf("%d found at loc: %d\n",key,loc);
	}
}
void reversal(int a[],int n)
{
	int i;
	printf("after reversal array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
}
void insertion(int a[],int n)
{
	int  loc,item,i;
	printf("enter the location at which you want to insert data\n");
	scanf("%d",&loc);
	printf("enter the data to be inserted\n");
	scanf("%d",&item);
	n++;
	/*
	i=n-1;
	while(i>loc)
	{
		a[i]=a[i-1];
		i--;
	}
	a[loc]=item;
	*/
	for(i=n-1;i>loc;i--)
	{
		a[i]=a[i-1];
	}
	a[loc]=item;
	printf("after insertion the array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void deletion(int copy[],int n)
{
	int i,item,loc,flag=0;
	printf("enter the data to be deleted\n");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(copy[i]==item)
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
		printf("item not found\n");
	}
	else
	{
		for(i=loc;i<n-1;i++)
	{
		copy[i]=copy[i+1];
	}
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",copy[i]);
	}
	/*
	i=loc;
		while(i<n-1)
		{
			copy[i]=copy[i+1];
			i++;
		}
*/
}
