/*stack using ll*/
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack*link;
};
struct stack*top;    //here,stack_head=top
struct stack*push(struct stack*,int);
struct stack*pop(struct stack*);
struct stack*display(struct stack*);
int main()
{
	int ch,item;
	while(1)
	{
		printf("main menu\n");
		printf("1-push\n");
		printf("2-pop\n");
		printf("3-display\n");
		printf("4-exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the item to be inserted\n");
				scanf("%d",&item);
				top=push(top,item);
				break;
			case 2:top=pop(top);
			break;
			case 3:top=display(top);
			break;
			case 4:exit(0);
			default:
			printf("invalid ch\n");	
		}
	}
}
struct stack*push(struct stack*top,int item)
{
	struct stack*new_node;
	new_node=(struct stack*)malloc(sizeof(struct stack));
	new_node->data=item;
	if(top==NULL)
	{
		new_node->link=NULL;
		top=new_node;
	}
	else
	{
		new_node->link=top;
		top=new_node;
	}
	printf("node pushed\n");
	return top;
}
struct stack*pop(struct stack*top)
{
	struct stack*ptr;
	if(top==NULL)
	{
		printf("stack empty\n");
	}
	else
	{
		ptr=top;
		top=top->link;
		printf("%d popped out\n",ptr->data);
		free(ptr);
	}
	return top;
}
struct stack*display(struct stack*top)
{
	printf("stack is below\n");
	struct stack*ptr;
	if(top==NULL)
	{
		printf("stack empty\n");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
	return top;
}
