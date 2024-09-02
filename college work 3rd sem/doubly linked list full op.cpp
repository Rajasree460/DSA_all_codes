/*doubly linked list full operation*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *rnext;
	struct node *lnext;
};
struct node*header;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();
int main()
{
	int choice=0;
	while(choice!=9)
	{
		printf("**main menu**\n");
		printf("choose one option from the following list...\n");
		printf("1.insert in begining\n2.insert at last\n3.insert at any random location\n4.delete from the begining\n5.delete from the last\n6.delete node after specefide location\n7.search for an element\n8.show\n9.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:beginsert();
			break;
			case 2:lastinsert();
			break;
			case 3:randominsert();
			break;
			case 4:begin_delete();
			break;
			case 5:last_delete();
			break;
			case 6:random_delete();
			break;
			case 7:search();
			break;
			case 8:display();
			break;
			case 9:exit(0);
			break;
			default:
				printf("invalid choice\n");
		}
	}
}
void beginsert()
{
	struct node*ptr;
	struct node*new_node;   //new_node=GETNODE
	int item;
	//ptr=(struct node*)malloc(sizeof(struct node*));
	new_node=(struct node*)malloc(sizeof(struct node*));
	if(new_node==NULL)                //memory bank returns NULL
	{
		printf("memory full:no insertion possible\n");
	}
	else
	{
		ptr=header->rnext;;
		new_node->rnext=ptr;
		new_node->lnext=header;
		header->rnext=new_node;
		ptr->lnext=new_node;
		printf("enter value\n");
		scanf("%d",&item);
		new_node->data=item;
		printf("node inserted\n");
	}
}
void lastinsert()
{
	struct node*ptr;
	struct node*new_node;   //new_node=GETNODE
	int item;
	//ptr=(struct node*)malloc(sizeof(struct node*));
	new_node=(struct node*)malloc(sizeof(struct node*));
	if(new_node==NULL)                //memory bank returns NULL
	{
		printf("memory full:no insertion possible\n");
	}
	else
	{
		ptr=header;
		while(ptr->rnext!=NULL)
		{
			ptr=ptr->rnext;
		}
		ptr->rnext=new_node;
		new_node->lnext=ptr;
		printf("enter value\n");
		scanf("%d",&item);
		new_node->data=item;
		printf("node inserted\n");
	}
}
void randominsert()
{
	int i,loc,item;
	struct node*ptr,*ptr1;
	struct node*new_node;   //new_node=GETNODE
	//ptr=(struct node*)malloc(sizeof(struct node*));
	new_node=(struct node*)malloc(sizeof(struct node*));
	if(new_node==NULL)                //memory bank returns NULL
	{
		printf("memory full:no insertion possible\n");
	}
	else
	{
		printf("enter element value\n");
		scanf("%d",&item);
		ptr->data=item;
		printf("enter the location after which you want to insert\n");
		scanf("%d",&loc);
		ptr=header;
		for(i=1;i<loc-1;i++)
		{
			ptr=ptr->rnext;
		}
		ptr1=ptr->rnext;
		new_node->rnext=ptr1;
		new_node->lnext=ptr;
		ptr1->lnext=new_node;
		ptr->rnext=new_node;
		printf("node inserted\n");
	}
}
void begin_delete()
{
	struct node*ptr,*ptr1;
	ptr=header->rnext;
	if(ptr==NULL)
	{
		printf("deletion not possible\n");
	}
	else
	{
		ptr1=ptr->rnext;
		header->rnext=ptr1;
		ptr1->lnext=header;
		free(ptr);
		printf("node deleted from the begining\n");
	}
}
void last_delete()
{
	struct node*ptr,*ptr1;
	ptr=header->rnext;
	if(ptr==NULL)
	{
		printf("deletion not possible\n");
	}
	while(ptr->rnext!=NULL)
	{
		ptr1=ptr; //trailing
		ptr=ptr->rnext;
	}
	ptr1->rnext=NULL;
	free(ptr);
    printf("deleted node from the last\n");	
}
void random_delete()
{
	struct node*ptr,*ptr1;
	int loc,i=0;
	printf("enter the location of the node after which you want to perform deletion\n");
	scanf("%d",&loc);
	ptr=header->rnext;
	if(ptr==NULL)
	{
		printf("deletion not posible\n");
	}
	while(i<loc && ptr!=NULL)
	{
		ptr1=ptr;
		i++;
		ptr=ptr->rnext;
	}
	ptr->lnext=ptr1->rnext;
	free(ptr);
	printf("node deleted\n");
}
void search()
{
	struct node*ptr;
	int item,i=0,flag=0,loc;
	ptr=header;
	if(ptr==NULL)
	{
		printf("empty list\n");
		
	}
	else
	{
		printf("enter item which you want to search\n");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->data==item)
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
			ptr=ptr->rnext;
		}
		if(flag==0)
		{
			printf("item not found\n");
		}
		else
		{
			printf("item found at location %d\n",loc);
		}
	}
}
void display() //traversal
{
	struct node*ptr;
	ptr=header;
	if(ptr==NULL)
	{
		printf("nothing to print\n");
	}
	else
	{
		printf("printing values...\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->rnext;
		}
	}
}
