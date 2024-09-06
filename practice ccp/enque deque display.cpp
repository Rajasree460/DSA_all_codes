/*enque,deque,display by using circular queue*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=0;
int rear=0;
void insert_queue();
void delete_queue();
void display_queue();
int main()
{
	int ch;
	while(1)
	{
		printf("**main menu**\n");
		printf("press 1 for insert\n");
		printf("press 2 for delete\n");
		printf("press 3 for display\n");
		printf("press 4 for exit\n");
		printf("enter your choice:\n");
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
	 if(((rear%MAX)+1)==front)
	 {
	 	printf("queue full\n");
	}
	else
	{
		if(rear==0 && front==0)
		{
	   front=1;	
        }	
	rear=(rear%MAX)+1;
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
		printf("queue  empty\n");
	}
	else
	{
		x=queue[front];
		if(front==rear)
		{
			front=0;
			rear=0;
			printf("the only element %d deleted",x);
		}
		else
		{
			front=(front%MAX)+1;
			printf("%d deleted\n",x);
		}
	}
}
void display_queue()
{
	printf("the queue is below\n");
	if(front==0 && rear==0)
	{
		printf("queue  empty\n");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
