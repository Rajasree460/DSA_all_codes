/*A application of stack(=recursion)*/
/*factorial of a no.(using recursion)*/
#include<stdio.h>
int fact(int x);
int main()
{
	int n,p;
	printf("enter the no: ");
	scanf("%d",&n);
	printf("\n");
	p=fact(n);
	printf("the fact of the no:%d",p);
	printf("\n");
}
int fact(int x)
{
	if(x==0||x==1)
	return 1;
	else
	return x*fact(x-1);
}
