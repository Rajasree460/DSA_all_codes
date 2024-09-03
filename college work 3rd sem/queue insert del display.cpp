#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define MAX 10
int front=-1;
int rear=-1;
int queue[MAX];
void insert_queue();
void delete_queue();
void display_queue();
int main()
{
	int ch;
	while(1)
	{
		printf("press 1 for insert element\n");
		printf("press 2 for delete element\n");
		printf("press 3 for display\n");
		printf("press 4 for exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_queue();
			       break;
			case 2:delete_queue();
			       break;
			case 3:display_queue();		
			      break;
			case 4:exit(0);
			default:
			printf("invalid choice\n");	   
		}
	}
}
void insert_queue()
{
	int value;
	if(rear==MAX-1)
	{
		printf("queue is full\n");
	}
	else
	{
		if(front==-1)
		front=0;
		rear++;
		printf("enter a value\n");
		scanf("%d",&value);
		queue[rear]=value;
	}
}
void delete_queue()
{
	int x;
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		x=queue[front];
		printf("%d is deleted\n",x);
		front++;
		if(front>rear)
		front=rear=-1;
	}
}
void display_queue()
{
	int i;
	if(rear==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
