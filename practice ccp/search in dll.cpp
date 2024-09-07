/*search in dll*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*rlink;
	struct node*llink;
};
struct node*header;
struct node*create_dll(struct node*);
struct node*display(struct node*);
void search(struct node*);
int main()
{
	int ch;
	while(ch!=4)
	{
		printf("main menu\n");
		printf("1.create list\n2.display\n3.search\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_dll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:search(header);
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
	printf("enter the data:\n");
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
		printf("enter the data:\n");
	scanf("%d",&item);
	}
	printf("list created\n");
	return header;
}
struct node*display(struct node*header)
{
	printf("the list is below\n");
	struct node*ptr;
	if(header==NULL)
	{
		printf("emptylist\n");
	}
	else
	{
		ptr=header;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->rlink;
	}
	
}
return header;
}
void search(struct node*header)
{
	int item,i=0,flag=0,loc;
	struct node*ptr;
	printf("enter the item to be searched:\n");
	scanf("%d",&item);
	ptr=header;
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			flag=1;
			loc=i;
			break;
		}
		else
		{
			flag=0;
		}
		++i;
		ptr=ptr->rlink;
		if(flag==0)
		{
			printf("item not found\n");
		}
		else
		{
			printf("item found at loc:%d",loc);
		}
	}
}
