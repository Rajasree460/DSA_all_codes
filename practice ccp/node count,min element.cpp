/*node count,min element on sll*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
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
		printf("MAIN MENU\n");
		printf("1.create sll\n2.display\n3.count the total no of nodes in that list\n4.minimum element of the list\n5.exit\n");
		printf("enter your option: \n");
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
				printf("invalid choice\n");
		}
	}
}
struct node*create_sll(struct node*header)
{
	struct node*new_node,*ptr;
	int item;
	printf("enter -1 to end\n");
	printf("enter the data: \n");
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
	printf("enter the data: \n");
	scanf("%d",&item);
  }
  printf("the ll created\n");
  return header;
}
struct node*display(struct node*header)
{
	printf("the ll is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return header;
}
void node_count(struct node*header)
{
	struct node*ptr;
	int count=0;
	ptr=header;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("the total no of nodes in the ll: %d \n",count);
}
void min_element(struct node*header)
{
	struct node*ptr;
	int min;
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
  printf("the minimum element of the ll is: %d\n",min);
}
