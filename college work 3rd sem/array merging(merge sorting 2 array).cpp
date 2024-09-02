/*array merging*/
#include<stdio.h>
int main()
{
	int m,n,i,j,k=0;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the value of m\n");
	scanf("%d",&m);
	int a[n],b[m],c[k];
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
	while(i<n && j<m)
          {
			if(a[i]<b[j])
			{
				c[k]=a[i];
				k++;
				i++;
			}
			else if(a[i]>b[j])
			{
				c[k]=b[j];
				k++;
				j++;
			}
			else if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
				i++;
				j++;
			}
	}
	
	printf("after merging the array is\n");
	for(k=0;k<m+n;k++)
	{
		printf("%d\n",c[k]);
	}
	return 0;
}
