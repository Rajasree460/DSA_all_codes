/*linked list copy,rev*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
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
		printf("MAIN MENU\n");
		printf("1.create a list\n2.display\n3.copy the list in another list\n4.reverse the list\n5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header=create_sll(header);
			break;
			case 2:header=display(header);
			break;
			case 3:header1=copy(header,header1);
			break;
			case 4:header=reversal(header);
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
struct node*copy(struct node*header,struct node*header1)
{
	struct node*new_node,*ptr,*ptr1;
	new_node=(struct node*)malloc(sizeof(struct node));
	ptr=header;
	if(header1==NULL)
	{
		new_node->data=ptr->data;
		new_node->link=NULL;
		header1=new_node;
		ptr=ptr->link;
	}
	else
	{
		ptr1=header1;
		while(ptr!=NULL)
		{
		new_node->data=ptr->data;
		ptr->link=new_node;
		ptr1=new_node;
		ptr=ptr->link;
	    }
	}
	printf("list copied\n");
	return header1;
}
struct node*reversal(struct node*header)
{
	struct node*r,*s;    //here,header=q
	r=NULL;
	s=NULL;
	if(header!=NULL)
	{
		r=header;
		s=header->link;
		header=header->link;
		r->link=NULL;
	}                            //to make 1st node the last node
	while(header!=NULL)
	{
		header=header->link;
		s->link=r;
		r=s;
		s=header;	
	}
	header=r;     //to lonking out the last node
	printf("list reversed\n");
	return header;
}          
