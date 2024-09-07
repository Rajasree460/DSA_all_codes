/*node count,min element in sll*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*header;
struct node*create_sll(struct node*);
struct node*display(struct node*);
void node_count(struct node*);
void min_element(struct node*);
int main()
{
	int ch;
	while(ch!=5)
	{
		printf("main menu\n");
		printf("1.create list\n2.display\n3.node count\n4.minimum element\n5.exit\n");
		printf("enter your ch:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_sll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:node_count(header);
			break;
			case 4:min_element(header);
			break;
			case 5:exit(0);
			default:
				printf("invalid ch\n");
		}
	}
}
struct node*create_sll(struct node*header)
{
	int item;
	struct node*new_node,*ptr;
	printf("enter -1 to end\n");
	printf("enter the data to be inserted:\n");
	scanf("%d",&item);
	while(item!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		if(header==NULL)
		{
			new_node->link=NULL;
			header=new_node;
		}
		else
		{
			ptr=header;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;
			}
			ptr->link=new_node;
			new_node->link=NULL;
		}
		printf("enter the data to be inserted:\n");
	scanf("%d",&item);
	}
	printf("list created\n");
	return header;
}
struct node*display(struct node*header)
{
	struct node*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("the list is below\n");
		ptr=header;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
	return header;
}
void node_count(struct node*header)
{
	int count=0;
	struct node*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr=header;
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->link;
		}
	}
	printf("the no of nodes in this list:%d\n",count);
}
void min_element(struct node*header)
{
	int min;
	struct node*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr=header;
		min=ptr->data;
		ptr=ptr->link;
		while(ptr!=NULL)
		{
			if(ptr->data<min)
			{
				min=ptr->data;
			}
			
			else
			{
				ptr=ptr->link;
			}
		}
	}
	printf("min element is:%d\n",min);
}
