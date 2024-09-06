/*linked list copy,rev*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*header1;
struct node*headercopy;
struct node*create_sll(struct node*);
struct node*display(struct node*);
struct node*copy(struct node*,struct node*);
struct node*reversal(struct node*);
int main()
{
	int ch;
	while(ch!=6)
	{
		printf("MAIN MENU\n");
		printf("1.create a list\n2.display\n3.copy the list in another list\n4.display copied list\n5.reverse the list\n6.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header1=create_sll(header1);
			break;
			case 2:header1=display(header1);
			break;
			case 3:headercopy=copy(header1,headercopy);
			break;
			case 4:headercopy=display(headercopy);
			break;
			case 5:header1=reversal(header1);
			break;
			case 6:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
struct node*create_sll(struct node*header1)
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
		if(header1==NULL)
		{
			new_node->link=NULL;
			header1=new_node;
		}
		else
		{
			ptr=header1;
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
	return header1;
} 
struct node*display(struct node*header)
{
	printf("the list is below\n");
	struct node*ptr;
	if(header==NULL)
	{
		printf("list empty\n");
	}
	else
	{
		ptr=header;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
}
	return header;
}
struct node*copy(struct node*header1,struct node*headercopy)
{
	struct node*new_node,*ptr,*ptr1;
	new_node=(struct node*)malloc(sizeof(struct node));
	ptr=header1;
	if(header1==NULL)
	{
		new_node->data=ptr->data;
		new_node->link=NULL;
		headercopy=new_node;
		ptr=ptr->link;
	}
	else
	{
		ptr1=headercopy;
		while(ptr!=NULL)
		{
		new_node->data=ptr->data;
		ptr->link=new_node;
		ptr1=new_node;
		ptr=ptr->link;
	    }
	}
	printf("list copied\n");
	return headercopy;
}
struct node*reversal(struct node*header1)
{
	struct node*r,*s;    //here,header=q
	r=NULL;
	s=NULL;
	if(header1!=NULL)
	{
		r=header1;
		s=header1->link;
		header1=header1->link;
		r->link=NULL;
	}                            //to make 1st node the last node
	while(header1!=NULL)
	{
		header1=header1->link;
		s->link=r;
		r=s;
		s=header1;	
	}
	header1=r;     //to lonking out the last node
	printf("list reversed\n");
	return header1;
}          
