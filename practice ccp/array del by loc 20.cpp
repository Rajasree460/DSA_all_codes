/*array deletion by loc*/
#include<stdio.h>
void deletion(int a[],int n);
int main()
{
	int n,i;
	printf("enter the value of n or size of arryay\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("your array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",&a[i]);
	}
	deletion(a,n);
 } 
 void deletion(int a[],int n)
 {
 	int i,location;
 	printf("enter he loc from where you want to delete the element\n");
 	scanf("%d",&location);
 	for(i=location;i<n-1;i++)
 	{
 		a[i]=a[i+1];
	 }
	 printf("after deletion the array elements are\n");
	 
	 	for(i=0;i<n-1;i++)
	 	{
	 		printf("%d\n",&a[i]);
		 }
	
 }
