/*queue using array*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front=0;         //we will start the index from 1
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
printf("**main menu**\n");
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
int item;
if(rear==MAX)
{
printf("queue is full\n");
}
else
{
if(front==0 && rear==0)
{
front=1;
}
rear++;
printf("enter a value to be inserted\n");
scanf("%d",&item);
queue[rear]=item;
}
printf("the value is inserted\n");
}
void delete_queue()
{
int x;               //here,item=x
if(front==0)
{
printf("queue is empty\n");
}
else
{
x=queue[front];
if(front==rear)       //queue has only one element
{
	front=0;
	rear=0;
	printf("only element of this queue is deleted\n");
}
else
{
	front++;
	printf("%d is deleted\n",x);
}
}
}
void display_queue()
{
printf("the queue is below\n");	
int i;
if(rear==0 && front==0)
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
