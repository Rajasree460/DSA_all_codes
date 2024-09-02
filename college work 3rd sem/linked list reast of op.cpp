/*linked list random insertion,random deletion*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head;
void beginsert();
void randominsert();
void randomdelete();
void display();
int main()
{
	int ch=0;
	while(ch!=5)
	{
	printf("*main menu*\n");
	printf("choose one option from the following list...\n");
	printf("1.begin_insert\n2.random_insertion\n3.random_deletion\n4.display\n5.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:beginsert();
		break;
		case 2:randominsert();
		break;
		case 3:randomdelete();
		break;
		case 4:display();
		break;
		case 5:exit(0);
		break;
		default:
			printf("invalid choice\n");
		}
	}
}
void beginsert()
{
	struct node*ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		printf("enter value\n");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("node inserted\n");
	}
}
void randominsert() //after a given value
{
	int i=0,item,key,found=0;
	struct node*ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		printf("enter the value after which the node has to be inserted\n");
		scanf("%d",&key);
		temp=head;
		ptr=head;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				found=1;
			}
			else
			{
				found=0;
			}
			++i;
			temp=temp->next;
			if(found==0)
			{
				printf("insertion not possible as search is unccessful\n");
			}
			else
			{
				printf("enter the value\n");
				scanf("%d",&item);
				ptr->data=item;
				ptr->next=temp->next;
				temp=ptr->next;
				printf("node inserted\n");
			}
		}
	}
	printf("node inserted\n");
}
void randomdelete() //after a given value
{
	struct node*ptr,*ptr1;
	int key;
	printf("enter the value after which the node has to be deleted\n");
	scanf("%d",&key);
	ptr=head->next;
	ptr1=ptr;
	if(ptr=NULL)
	{
		printf("deletion not possoible\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data!=key)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			else
			{
				ptr1->next=ptr->next;
			}
			
		}
	}
	printf("node deleted\n");
}
void display()
{
	struct node*ptr;
	ptr=head;
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
			ptr=ptr->next;
		}
	}
}

