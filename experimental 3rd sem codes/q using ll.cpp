/*queue using ll*/
#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue*link;
};
struct queue*front;    //here,header=front
struct queue*rear;
struct queue*insert_queue(struct queue*,struct queue*,int);
struct queue*delete_queue(struct queue*);
struct queue*display_queue(struct queue*);
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
				front=insert_queue(front,rear,item);
				break;
			case 2:front=delete_queue(front);
			break;
			case 3:front=display_queue(front);
			break;
			case 4:exit(0);
			default:
			printf("invalid ch\n");	
		}
	}
}
struct queue*insert_queue(struct queue*front,struct queue*rear,int item)
{
	struct node*new_node;
	new_node=(struct queue*)malloc(sizeof(struct queue));
	new_node->data=item;
	if(front==NULL)
	{
		
	}
}
