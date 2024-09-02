/*array insertion*/
#include<stdio.h>
int main()
{
	int n,i,key,location;
printf("enter the value of n\n");
scanf("%d",&n);
int a[n];
printf("enter the values of array\n");
{
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}
printf("your entered array elements are\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("enter the location of new element to be inserted\n");
scanf("%d",&location);
printf("enter the value of new element to be inserted\n");
scanf("%d",&key);
n++;
i=n-1;
while(i>=location)
{
	a[i]=a[i-1];
	i--;
}
a[location]=key;
printf("after insertion array is\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
return 0;
}
