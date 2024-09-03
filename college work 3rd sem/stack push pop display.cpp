#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define MAX 10
int top=-1,stack[MAX];
void push();
void pop();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("press 1 for push\n");
		printf("press 2 for pop\n");
		printf("press 3 for display\n");
		printf("press 4 for exit\n");
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
	int value;
	if(top==MAX-1)
	{
		printf("stack is full\n");
	}
	else
	{
		printf("enter the value\n");
		scanf("%d",&value);
		top++;
		stack[top]=value;
	}
}
void pop()
{
	int x;
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		x=stack[top];
		printf("deleted value is %d",x);
		top--;
	}
}
void display()
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
