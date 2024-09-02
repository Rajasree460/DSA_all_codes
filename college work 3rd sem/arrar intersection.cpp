/*array intersection*/
#include<stdio.h>
int main()
{
	int m,n,i,j,k=0,count=0;
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
	if(count>0)
	{
		printf("there is an commom element between 2 array\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{

		    if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
				j++;
				count++;
			}
		}
	
	}
    }
	else
    {
	  printf("intersection not possible\n");	 	
    }
	printf("after intersection the array is\n");
	for(k=0;k<count;k++)
	{
		printf("%d\n",c[k]);
	}
	return 0;
}
