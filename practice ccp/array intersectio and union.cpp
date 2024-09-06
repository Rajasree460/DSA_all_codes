/*array union and intersection*/
#include<stdio.h>
void printunion(int a1[],int n,int a2[],int m);
void printintersection(int a1[],int n,int a2[],int m);
int main()
{
	int n,m,i,j;
	printf("entrt the value of n(size of 1st array)\n");
	scanf("%d",&n);
	printf("entrt the value of m(size of 2nd array)\n");
	scanf("%d",&m);
	int a1[n],a2[m];
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a1[i]);
	}
	printf("enter the values of 2nd array\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&a2[j]);
	}
	printunion(a1,n,a2,m);
	printintersection(a1,n,a2,m);
	return 0;
}
void printunion(int a1[],int n,int a2[],int m)
{
	int i,j,k=0;
	int c[k];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a1[i]<a2[j])
			{
				c[k]=a1[i];
				k++;
			}
			else if(a1[i]>a2[j])
			{
				c[k]=a2[j];
				k++;
			}
			else if(a1[i]==a2[j])
			{
				c[k]=a1[i];
				k++;
			}
		}
	}
	/*for(i=0;i<n;i++)
	{
		c[k]=a1[i];
		k++;
	}
	for(j=0;j<n;j++)
	{
		c[k]=a1[j];
		k++;
	}*/
	printf("the resultant array\n");
	for(k=0;k<n+m;k++)
	{
		printf("%d\n",c[k]);
	}
}
void printintersection(int a1[],int n,int a2[],int m)
{
	int i,j,k=0,count=0;
	int b[k];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a1[i]==a2[j])
			{
				b[k]=a1[i];
				k++;
				count++;
			}
		}
	}
	printf("the intersection of this 2 array is\n");
	for(k=0;k<count;k++)
	{
		printf("%d\n",b[k]);
	}
}
