/*array union & intersection*/
#include<stdio.h>
void printunion(int a[],int n,int b[],int m);
void printintersection(int a[],int n,int b[],int m);
int main()
{
	int i,j,n,m;
	printf("enter the size of 1st array\n");
	scanf("%d",&n);
	printf("enter the size of 2nd array\n");
	scanf("%d",&m);
	int a[n],b[m];
	printf("enter the 1st array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the 2nd array elements\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	printunion(a,n,b,m);
	printintersection(a,n,b,m);
}
void printunion(int a[],int n,int b[],int m)
{
	printf("new array elements are\n");
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
		{
			printf("%d\n",a[i]);
			i++;
		}
		else if(a[i]>b[j])
		{
			printf("%d\n",b[j]);
			j++;
		}
		else
		{
			printf("%d\n",a[i]);
			i++;
			j++;
		}
	}
	while(i<n)
	{
		printf("%d\n",a[i]);
		i++;
	}
	while(j<m)
	{
		printf("%d\n",b[j]);
		j++;
	}
}
void printintersection(int a[],int n,int b[],int m)
{
	int i,j,k=0,count=0;
	int c[k];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
				count++;
			}
		}
	}
	printf("the result of intersection is\n");
	for(k=0;k<count;k++)
	{
		printf("%d\n",c[k]);
	}
}
