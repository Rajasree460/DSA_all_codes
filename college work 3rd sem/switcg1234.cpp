/*linear & binary search by switch_case*/
#include<stdio.h>
int main()
{
	int ch;
int n,m,i,found,location,key,j,k,temp,first,last,mid;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the values of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value of m\n");
	scanf("%d",&m);
	int b[m];
	printf("enter the values of array\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	printf("enter your choice\n");
	printf("1.linear search\n2.binary search\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter your key(search)element\n");
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
	{
	printf("SEARCH UNSUCCESSFUL:element not found\n");
    }
	else
	{
	printf("SEARCH SUCCESSFUL:%d is present at place %d",key,(location+1));
    }

	
	 case 2:
	
	for(j=0;j<m;j++)
	{
		for(k=j+1;k<m;k++)
		{
			if(b[j]>b[k])
			{
			temp=b[j];
			b[j]=b[k];
			b[k]=temp;
		    }
		}
	}
	printf("sorted array\n");
	for(j=0;j<m;j++)
	{
		printf("%d\n",b[j]);
	}
	first=0;
	last=n-1;
	printf("enter the value of key\n");
	scanf("%d",&key);
	mid=(first+last)/2;
	while(first<=last)
	{
		if(b[mid]<key)
		{
			first=mid+1;
		}
		else if(b[mid]==key)
		{
			printf("%d is found at %d",key,mid+1);
			break;
		}
		else
		{
			last=mid-1;
			mid=(first+last)/2;
		}
		mid=(first+last)/2;
		
	}
	if(first>last)
	{
		printf("value is not found");
	}
	break;
	default:
		{
		printf("invalid choice\n");
        }
}
return 0;
}
