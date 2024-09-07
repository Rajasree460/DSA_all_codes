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
void node_count();
void min_element();
int main()
{
	int ch;
	while(ch!=5)
	{
		printf("main menu\n");
		printf("1.create list\n2.display\n3.count no of nodes in the sll\n4.minimum element of the sll\n5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_sll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:node_count();
			break;
			case 4:min_element();
			break;
			case 5:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
struct node*create_sll(struct node*header)
{
	int item;
	struct node*new_node,*ptr;
	printf("enter -1 to end\n");
	printf("enter your data:\n");
	scanf("%d",&item);
	while(item!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node*));
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
		printf("enter your data:\n");
	scanf("%d",&item);
	}
	printf("list created\n");
	return header;
}
struct node*display(struct node*header)
{
	printf("the list is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return header;
}
void node_count()
{
	int count=0;
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		++count;
		ptr=ptr->link;
	}
	printf("the no of nodes i that sll:%d\n",count);
}
void min_element()
{
	int min;
	struct node*ptr;
	ptr=header;
	min=ptr->data;
	ptr=ptr->link;
	while(ptr!=NULL)
	{
		if(ptr->data<min)
		{
			min=ptr->data;
		}
		ptr=ptr->link;
	}
	printf("the minimum element of that sll is:%d\n",min);
}
