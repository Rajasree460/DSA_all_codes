/*array op*/
#include<stdio.h>
void traversal(int a[],int n);
void search(int a[],int n);
void reversal(int a[],int n);
void insertion(int a[],int n);
void deletion(int copy[],int n);
int main()
{
	int n,i;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n],copy[n],copy1[n];
	printf("enter the array elements\n");
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
	traversal(a,n);
	search(a,n);
	reversal(a,n);
	insertion(a,n);
	deletion(copy,n);
	return 0;
}
void traversal(int a[],int n)
{
	int i;
	printf("after traversal the array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	
		}
	}
void search(int a[],int n)
{
	int i,key,found,location;
	printf("enter your search(key)element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			found=1;
			location=i;
			break;
		}
		else
		{
			found=0;
		}
	}
	if(found==0)
	printf("searching unsuccessful:element not found\n");
	else
	printf("searching successful:%d is found at the place %d\n",key,(location+1));
}	
void reversal(int a[],int n)
{
	int i;
	printf("after reversal the array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
}
void insertion(int a[],int n)
{
	int i,key,location;
	printf("enter the new element to be inserted\n");
	scanf("%d",&key);
	printf("enter the location of the new element to be inserted\n");
	scanf("%d",&location);
	n++;
	for(i=n-1;i>location;i--)
	{
		a[i]=a[i-1];
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
	int i,key,found,location;
	printf("enter your search(key)element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(copy[i]==key)
		{
			found=1;
			location=i;
			break;
		}
		else
		{
			found=0;
		}
	}
	if(found==0)
	printf("searching unsuccessful:element not found\n");
	else
	{
		for(i=location;i<n;i++)
		{
			copy[i]=copy[i+1];
		}
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",copy[i]);
	}
}
