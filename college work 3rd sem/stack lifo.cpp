/*stack lifo*/
#include<stdio.h>
int main()
{
	int n,top=-1;
	printf("enter the value of n\n");
	scanf("%d",&n);
	int stack[n];
	printf("enter the values of stack\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&stack[++top]);
	}
	printf("display the stack\n");
	for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	printf("doing LIFO \n");
	int x;
	if(top==-1)      //by again & again deletion
	{
		printf("stack is empty\n");
	}
	else
	{
		x=stack[top];
		printf("deleted value is %d\n",x);
		top--;
    }
	printf("aftet LIFO the stack is\n");
	for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	return 0;
}


