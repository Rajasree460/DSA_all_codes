/*array union and intersection*/
#include<stdio.h>
void printunion(int array1[],int n,int array2[],int m)
{
	printf("the result of array union\n");
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(array1[i]<array2[j])
		{
			printf("%d\n",array1[i++]);
		}
		else if(array2[j]<array1[i])
		{
			printf("%d\n",array2[j++]);
		}
		else
		{
			printf("%d\n",array1[i]);
			i++;
			j++;
		}
	}
	while(i<n)
	printf("%d\n",array1[i++]);
	while(j<m)
	printf("%d\n",array2[j++]);
}
void printintersection(int array1[],int n,int array2[],int m)
{
	int i,j,k=0,count=0;
	int b[k];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(array1[i]==array2[j])
			{
				b[k]=array1[i];
				k++;
				count++;
			}
		}
	}
	printf("the result of array intersection\n");
	for(i=0;i<count;i++)
	{
		printf("%d\n",b[i]);
	}
}
int main()
{
	int n,m,i,j;
	printf("enter the value of n for 1st array\n");
	scanf("%d",&n);
	printf("enter the value of m for the 2nd array\n");
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
