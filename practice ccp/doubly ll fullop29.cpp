/*doubly ll*/
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
struct node*insert_beg(struct node*);
struct node*insert_end(struct node*);
struct node*insert_any(struct node*);
struct node*delete_beg(struct node*);
struct node*delete_end(struct node*);
struct node*delete_any(struct node*);
void search(struct node*);
struct node*sort_list(struct node*);
int main()
{
	int ch;
	while(ch!=11)
	{
		printf("MAIN MENU\n");
		printf("1.create the list\n2.display the list\n3.insert at beg\n4.insert at end\n5.insert at any position\n6.delete at beg\n7.delete at end\n8.delete from any position\n9.search\n10.sort the list\n11.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_dll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:header=insert_beg(header);
			break;
			case 4:header=insert_end(header);
			break;
			case 5:header=insert_any(header);
			break;
			case 6:header=delete_beg(header);
			break;
			case 7:header=delete_end(header);
			break;
			case 8:header=delete_any(header);
			break;
			case 9:search(header);
			break;
			case 10:header=sort_list(header);
			break;
			case 11:exit(0);
			default:
				printf("invalid choice\n");
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
struct node*insert_beg(struct node*header)
{
	int item;
	struct node*new_node;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("enter the data to be inserted\n");
		scanf("%d",&item);
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		new_node->rlink=header;
		new_node->llink=NULL;
		header=new_node;
	}
	printf("node inserted at beg\n");
	return header;
}
struct node*insert_end(struct node*header)
{
	int item;
	struct node*new_node,*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("enter the data to be inserted\n");
		scanf("%d",&item);
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		ptr=header;
		while(ptr->rlink!=NULL)
		{
			ptr=ptr->rlink;
		}
		ptr->rlink=new_node;
		new_node->llink=ptr;
		new_node->rlink=NULL;
	}
	printf("node inserted at end\n");
	return header;
}
struct node*insert_any(struct node*header)
{
	int item,i,loc;
	struct node*new_node,*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("enter the loc at which you want to insert the node\n");
		scanf("%d",&loc);
		printf("enter the data to be inserted\n");
		scanf("%d",&item);
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		ptr=header;
		for(i=0;i<loc-1;i++)
		{
			ptr=ptr->rlink;
		}
		new_node->rlink=ptr->rlink;
		new_node->llink=ptr;
		ptr->rlink=new_node;
		ptr->rlink->llink=new_node;
	}
	printf("node inserted at specific position\n");
	return header;
}
struct node*delete_beg(struct node*header)
{
	struct node*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr=header;
		header=header->rlink;
		free(ptr);
	}
	printf("node deleted from the beg\n");
	return header;
}
struct node*delete_end(struct node*header)
{
	struct node*ptr,*ptr1;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr=header;
		while(ptr->rlink!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->rlink;
		}
		ptr1->rlink=NULL;
	}
	printf("node deleted from end\n");
	return header;
}
struct node*delete_any(struct node*header)
{
	int i,loc;
	struct node*ptr1,*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("enter the loc after which you want to delete the node\n");
		scanf("%d",&loc);
		ptr=header;
		for(i=0;i<=loc;i++)
		{
			ptr1=ptr;
			ptr=ptr->rlink;
		}
		ptr1->rlink=ptr->rlink;
		ptr->rlink->llink=ptr1;
		free(ptr);
	}
	printf("node deleted from specific pos\n");
	return header;
}
void search(struct node*header)
{
	int i=0,key,flag=0,loc;
	struct node*ptr;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("enter the data to be searched\n");
		scanf("%d",&key);
		ptr=header;
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				flag=1;
				loc=i+1;
				break;
			}
			else
			{
				flag=0;
			}
			++i;
			ptr=ptr->rlink;
		}
		if(flag==0)
		{
			printf("item not found\n");
		}
		else
		{
			printf("%d found at loc:%d\n",key,loc);
		}
	}
}
struct node*sort_list(struct node*header)
{
	int temp;
	struct node*ptr1,*ptr2;
	if(header==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr1=header;
		while(ptr1->rlink!=NULL)
		{
			ptr2=ptr1->rlink;
			while(ptr2!=NULL)
			{
				if(ptr1->data>ptr2->data)
				{
					temp=ptr1->data;
					ptr1->data=ptr2->data;
					ptr2->data=temp;
				}
				ptr2=ptr2->rlink;
			}
			ptr1=ptr1->rlink;
		}
	}
	printf("list sorted\n");
	return header;
}
