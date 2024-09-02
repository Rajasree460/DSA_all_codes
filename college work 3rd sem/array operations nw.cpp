/*array traversal,insertion,deletion,searching,reversal*/
#include<stdio.h>
void traversal(int a1[],int n);
void search(int a1[],int n);
void reversal(int a1[],int n);
void insertion(int a1[],int n);
void deletion(int copy[],int n);
int main()
{
	int n,i;
	printf("enter the value of n\n");
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
	traversal(a,n);
	search(a,n);
	reversal(a,n);
	insertion(a,n);
	deletion(copy,n);
	return 0;

}
void traversal(int a1[],int n)
{
	int i;
	printf(" after traversal array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a1[i]);
	}
}
void search(int a1[],int n)
{
	int i,key,found,location;
	printf("enter your key(search)element\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{

		if(a1[i]==key)
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
	printf("SEARCH UNSUCCESSFUL:element not found\n");
	else
	printf("SEARCH SUCCESSFUL:%d is present at place %d\n",key,(location+1));
}
void reversal(int a1[],int n)
{
	int i;
	printf("after reversing array the array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a1[i]);
	}
}
void insertion(int a1[],int n)
{
	int i,key,location;
	printf("enter the location of new element to be inserted\n");
scanf("%d",&location);
printf("enter the value of new element to be inserted\n");
scanf("%d",&key);
n++;
i=n-1;
while(i>=location)
{
	a1[i]=a1[i-1];
	i--;
}
a1[location]=key;
printf("after insertion array is\n");
for(i=0;i<n;i++)
{
printf("%d\n",a1[i]);
}
}
void deletion(int copy[],int n)
{
	int i,key,location,found;
	printf("enter the value of element to be deleted\n");
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
	printf("SEARCH UNSUCCESSFUL:element not found,deletion is not possible\n");
	else
	while(location<n)
	{
		copy[location]=copy[location+1];
		location++;
	}
	printf("after deletion the array is\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",copy[i]);
	}
}
