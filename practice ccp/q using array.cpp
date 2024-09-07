/*queue using array*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int front=0;
int rear=0;
int queue[MAX];
void insert_queue();
void delete_queue();
void display_queue();
int main()
{
	int ch;
	while(1)
	{
		printf("main menu\n");
		printf("press 1 to insert\n");
		printf("press 2 to delete\n");
		printf("press 3 to display\n");
		printf("press 4 to exit\n");
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
	int item;
	if(rear==MAX)
	{
		printf("queue full\n");
	}
	else
	{
		if(front==0 && rear==0)
		{
			front=1;
		}
		rear++;
		printf("enter the data to be inserted:\n");
		scanf("%d",&item);
		queue[rear]=item;
	}
	printf("data inserted\n");
}
void delete_queue()
{
	int x;
	if(front==0)
	{
		printf("queue empty\n");
	}
	else
	{
		x=queue[front];
		if(front==rear)
		{
			front=0;
			rear=0;
			printf("the only node %d deleted\n",x);
		}
		else
		{
			front++;
			printf("%d deleted\n",x);
		}
	}
}
void display_queue()
{
	int i;
	if(front==0 && rear==0)
	{
		printf("queue empty\n");
	}
	else
	{
		printf("queue is below\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
