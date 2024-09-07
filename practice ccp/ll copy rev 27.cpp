/*copy,revll into another ll*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*header;
struct node*header1;
struct node*create_sll(struct node*);
struct node*display(struct node*);
struct node*copy(struct node*,struct node*);
struct node*reversal(struct node*);
int main()
{
	int ch;
	while(ch!=5)
	{
		printf("main menu\n");
		printf("1.create list\n2.display\n3.copy the list to another list\n4.reversal\n5.exit\n");
		printf("enter your ch:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_sll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:header1=copy(header1,header);
			break;
			case 4:header=reversal(header);
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
		new_node->link=NULL;
		header1=new_node;
		ptr1=header1;
		ptr=header;
		while(ptr!=NULL)
		{
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=ptr->data;
			ptr1->link=new_node;
			ptr1=new_node;
			ptr=ptr->link;
		}
	}
	printf("list copied\n");
	return header1;
}
struct node*reversal(struct node*header)
{
	struct node*r,*s; //header=q,here
	r=NULL;
	s=NULL;
	if(header!=NULL)
	{
		r=header;
		s=header->link;
		header=header->link;
		r->link=NULL;
	}
	while(header!=NULL)
	{
		header=header->link;
		s->link=r;
		r=s;
		s=header;
	}
	header=r;
	printf("list reversed\n");
	return header;
}
