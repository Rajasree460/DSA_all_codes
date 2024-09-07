/*q using ll*/
#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue*link;
};
struct queue*front;
struct queue*rear;
void insert_queue(int);
void delete_queue();
void display_queue();
int main()
{
	int ch,item;
	while(1)
	{
		printf("main menu\n");
		printf("1-insert\n");
		printf("2-delete\n");
		printf("3-display\n");
		printf("4-exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the item to be inserted\n");
				scanf("%d",&item);
				insert_queue(item);
				break;
			case 2:delete_queue();
			break;
			case 3:display_queue();
			break;
			case 4:exit(0);
			default:
			printf("invalid ch\n");	
		}
	}
}
void insert_queue(int item)
{
	struct queue*new_node;
	new_node=(struct queue*)malloc(sizeof(struct queue));
	new_node->data=item;
	if(front==NULL)
	{
		new_node->link=NULL;
		front=new_node;
		rear=new_node;
	}
	else
	{
		rear->link=new_node;
		new_node->link=NULL;
		rear=new_node;
	}
	printf("node inserted\n");
}
void delete_queue()
{
	int x;
	if(front==NULL)
	{
		printf("q empty\n");
	}
	else
	{
		x=front->data;
		front=front->link;
		printf("%d deleted\n",x);
		free(front);
	}
}
void display_queue()
{
	struct queue*ptr;
	if(front==NULL)
	{
		printf("q empty\n");
	}
	else
	{
		printf("q is below\n");
		ptr=front;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;	
		}
	}
}
