/*factorial(iterative method)*/
#include<stdio.h>
int fact(int x);
int main()
{
	int n,p;
	printf("enter the value of n: ");
	scanf("%d",&n);
	printf("\n");
	p=fact(n);
	printf("the fact of the no:%d",p);
	printf("\n");
}
int fact(int x)
{
	int i,m=1;
	for(i=1;i<=x;i++)
	{
		m=m*i;
	}
	return m;
}
