/*queue using ll*/
#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue*link;
};
struct queue*front;
struct queue*rear;
void insert_queue(int item);
void delete_queue();
void display_queue();
int main()
{
	int ch,item;
while(1)
{
printf("**main menu**\n");
printf("1 - insert\n");
printf("2 -delete\n");
printf("3 -display\n");
printf("4 -exit\n");
printf("enter your choice: \n");
scanf("%d",&ch);
switch(ch) 
{ 
case 1:
printf("enter the no to be inserted in queue: \n");
scanf("%d",&item);
insert_queue(item); 
break; 
case 2: 
delete_queue(); 
break; 
case 3: 
display_queue(); 
break; 
case 4: 
exit(0); 
default: 
printf("invalid choice\n"); 
} 
} 
} 
void insert_queue(int item){
	struct queue*new_node;
	if(new_node==NULL)
	{
		printf("overflow\n");
	}
	else
	{
	new_node=(struct queue*)malloc(sizeof(struct queue*));
	new_node->data=item;
	if(front==NULL)
	{
		front=new_node;
		rear=new_node;
		front->link=NULL;
		rear->link=NULL;
	}
	else
	{
		while(rear->link!=NULL)
		{
			rear=rear->link;
		}
		rear->link=new_node;
		rear=new_node;
		rear->link=NULL;
	}
}
printf("node contains item inserted\n");
}
void delete_queue()
{
	struct queue*ptr;
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		ptr=front;
		front=front->link;
		printf("deleted item is %d\n",ptr->data);
		free(ptr);
	}
	printf("node deleted\n");
}
void display_queue()
{
	struct queue*ptr;
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		ptr=front;
		printf("the queue is below\n");
		while(ptr!=NULL)
		{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	}
}
