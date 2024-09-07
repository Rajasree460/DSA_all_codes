/*doubly ll copy*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*rlink;
	struct node*llink;
};
struct node*header;
struct node*header1;
struct node*create_dll(struct node*);
struct node*display(struct node*);
struct node*copy(struct node*,struct node*);
int main()
{
	int ch;
	while(ch!=4)
	{
		printf("main menu\n");
		printf("1.create list\n2.display\n3.copy the list to another list\n4.exit\n");
		printf("enter your ch:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_dll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:header1=copy(header1,header);
			break;
			case 4:exit(0);
			default:
				printf("invalid ch\n");
		}
	}
}
struct node*create_dll(struct node*header)
{
	int item;
	struct node*new_node,*ptr;
	printf("enter -1 to end\n");
	printf("enter your data\n");
	scanf("%d",&item);
	while(item!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		if(header==NULL)
		{
			new_node->rlink=NULL;
			new_node->llink=NULL;
			header=new_node;
		}
		else
		{
			ptr=header;
			while(ptr->rlink!=NULL)
			{
				ptr=ptr->rlink;
			}
			ptr->rlink=new_node;
			new_node->llink=ptr;
			new_node->rlink=NULL;
		}
		printf("enter your data\n");
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
		printf("list is below\n");
		ptr=header;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->rlink;
		}
	}
	return header;
}
struct node*copy(struct node*header1,struct node*header)
{
	struct node*new_node,*ptr,*ptr1;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->rlink=NULL;
		new_node->llink=NULL;
		header1=new_node;
		ptr1=header1;
		ptr=header;
		while(ptr!=NULL)
		{
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=ptr->data;
			ptr1->rlink=new_node;
			ptr1=new_node;
			ptr=ptr->rlink;
		}
	}
	printf("list copied\n");
	return header1;
}
