/*stack using array*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=0,stack[MAX];
void push();
void pop();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("main menu\n");
		printf("press 1 to push\n");
		printf("press 2 to pop\n");
		printf("press 3 to display\n");
		printf("press 4 to exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
void push()
{
	int item;
	printf("enter the data to be inserted:\n");
	scanf("%d",&item);
	if(top==MAX)
	{
		printf("stack full\n");
	}
	else
	{
		top++;
		stack[top]=item;
	}
	printf("item inserted at top\n");
}
void pop()
{
	int x;
	if(top<1)
	{
		printf("stack is empty\n");
	}
	else
	{
		x=stack[top];
		top--;
		printf("%d is popped from top\n",x);
	}
}
void display()
{
	int i;
	if(top<1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("stack is below\n");
		for(i=top;i>=1;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
