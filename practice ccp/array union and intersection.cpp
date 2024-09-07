/*array union and intersection*/
#include<stdio.h>
void printunion(int array1[],int n,int array2[],int m)
{
	printf("after union the array is\n");
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(array1[i]<array2[j])
		{
			printf("%d\n",array1[i]);
			i++;
		}
		else if(array1[i]>array2[j])
		{
			printf("%d\n",array2[j]);
			j++;
		}
		else
		{
			printf("%d\n",array1[i]);
			i++;
			j++;
		}
	}
	while(i<n)
	{
		printf("%d\n",array1[i]);
		i++;
	}
	while(j<m)
	{
		printf("%d\n",array2[j]);
		j++;
	}
}
void printintersection(int array1[],int n,int array2[],int m)
{
	int i,j,k=0,count=0;
	int c[k];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(array1[i]==array2[j])
			{
				c[k]=array1[i];
				k++;
				count++;
			}
		}
	}
	printf("after intersection the result is\n");
	for(k=0;k<count;k++)
	{
		printf("%d\n",c[k]);
	}
}
int main()
{
	int n,m,i,j;
	printf("enter the size of 1st array\n");
	scanf("%d",&n);
	printf("enter the size of 2nd array\n");
	scanf("%d",&m);
	int array1[n],array2[m];
	printf("enter the values for 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array1[i]);
	}
	printf("enter the values for 2nd array\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&array2[j]);
	}
	printunion(array1,n,array2,m);
	printintersection(array1,n,array2,m);
}
