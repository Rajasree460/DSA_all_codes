#include <stdio.h>
void deletion();
void insertion();
void traversal();
void search();
void concatenation();
void reversal();
void intersection();
void traversal(int ar[],int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d\t",ar[i]);
	}
	printf("\n");
}
void insertion(int ar[],int n)
{
	int i,key,pos;
	printf("enter element to be inserted and position in which it is inserted");
	scanf("%d%d",&key,&pos);
	if(ar[i]!=0)
	{
		printf("araay is full insertion not possible\n");
	}
	else
	{
		for(i=n;i>pos;i--)
		ar[i]=ar[i-1];
		ar[pos]=key;
		for(i=0;i<n;i++)
		printf("%d",ar[i]);
	}
}
void search(int ar[],int n)
{
	int i=0,key,found=0,pos=-1;
	printf("enter element to search\n");
	scanf("%d",&key);
	while((i<n)&&(found==0))
	{
	if(ar[i]==key)
	{
		found=1;
		pos=i;
		break;
	}
	else
	i++;
	}
	if(found==0)
	printf("element not found\n");
	else
	printf("element found at %d\n",pos);
}
void deletion(int ar[],int n)
{
	int i=0,found=0,key,pos;
	printf("enter locaton of element to delete");
	scanf("%d",&pos);
	while(i<n && found==0)
	{
		if(i==pos)
		{
			found=1;
			n=n-1;
			break;
		}
		else
		{
			i++;
		}
	}
	if(found==0)
	{
		printf("element not found, deletion not possible");
		return;
	}
	else
	{
		while(i<=n)
		{
			ar[i]=ar[i+1];
			i++;
		}
	}
	traversal(ar,n);
}
void concatenation(int ar[],int n)
{
	int i,x,z,j=0;
	printf("enter size of 2nd array\n");
	scanf("%d",&x);
	int c[x];
	printf("enter element of 2nd array\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&c[i]);
	}
	z=x+n;
	int b[z];
	for(i=0;i<n;i++)
	{
		b[i]=ar[i];
	}
	for(;i<z;i++)
	{
		b[i]=c[j];
		j++;
	}
	traversal(b,z);
}
void reversal(int ar[],int n)
{
	int i,b[n];
	int u=n;
	for(i=0;i<u;i++)
	{
		b[i]=ar[n-1];
		n--;
	}
	traversal(b,u);
}
void intersection(int ar[],int n)
{
	int i,x,j,k=0;
	printf("enter size of 2nd array\n");
	scanf("%d",&x);
	int c[x],b[x+n];
	printf("enter element of 2nd array\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<x;j++)
		{
			if(ar[i]==c[j])
			{
				b[k]=ar[i];
				k++;
			}
		}
	}
	traversal(b,k);
}
int main()
{
	int ar[50],i,n,ch;
	for(i=0;i<50;i++)
	{
		ar[i]=0;
	}
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter integer elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	printf("1.traversal\n2.insertion\n3.search\n4.deletion\n5.concatenation\n6.reversal\n7.intersection\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1:
			traversal(ar,n);
			break;
		case 2:
			insertion(ar,n);
			break;
		case 3:
			search(ar,n);
			break;
		case 4:
			deletion(ar,n);
			break;
		case 5:
			concatenation(ar,n);
			break;	
		case 6:
			reversal(ar,n);	
			break;
		case 7:
			intersection(ar,n);
			break;
		default:
			printf("wrong choice\n");
    }
	return 0;
}

