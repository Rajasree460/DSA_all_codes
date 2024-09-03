/*array intersection*/
#include<stdio.h>
void union_intersection(int a1[],int b1[],int n,int m);
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
	union_intersection(a,b,n,m);
	return 0;
}
void union_intersection(int a1[],int b1[],int n,int m)
{
	int i1=0,i2=0,k=0,count=0,l=0;
	int common[k],uni[l];
	while(i1<n && i2<m)
		{
			if(a1[i1]<b1[i2])
			{
				uni[l]=a1[i1];
				i1++;
				l++;
			}
			else if(a1[i1]>b1[i2])
				{
				uni[l]=b1[i2];
				i2++;
				l++;
			}
			 else if(a1[i1]==b1[i2])
			{
			
			common[k]=a1[i1];
			i1++;
			i2++;
			k++;
			count++;
		}
		
	}
	if(count>0)
	{
		printf("the result of intersection is\n");
		for(k=0;k<count;k++)
		{
			printf("%d\n",&common[k]);
		}
	}
	else
	printf("no common elements\n");
	printf("the result of union of array is\n");
	for(l=0;l<m+n;l++)
	{
		printf("%d\n",uni[l]);
	}
	while(i2<=m-1)
	{
		uni[l]=b1[i2];
		l++;
		i2++;
	}
	while(i1<=n-1)
	{
		uni[l]=b1[i1];
		l++;
		i1++;
	}
}
