/*array intersection*/
#include<stdio.h>
void intersection(int a1[],int b1[],int n,int m);
int main()
{
	int n,i,m,j;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the value of m\n");
	scanf("%d",&m);
	int a[n],b[m];
	printf("enter the values of 1st array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the values of 2nd array\n");
		for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	intersection(a,b,n,m);
	return 0;
}
void intersection(int a1[],int b1[],int n,int m)
{
	int i,j,k=0,count=0;
	int c[k];
	while(i<n && j<m)
	{
	
		{
			if(a1[i]==b1[j])
			{
			
			c[k]=a1[i];
			i++;
			j++;
			k++;
			count++;
		}
	}
}
	if(count>0)
	{
		printf("the result of intersection is\n");
		for(k=0;k<count;k++)
		{
			printf("%d\n",&c[k]);
		}
	}
	else
	printf("no common elements");
}
