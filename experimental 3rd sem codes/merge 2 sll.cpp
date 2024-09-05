/*merge 2 sll*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*header1;
struct node*header2;
struct node*headermerge;
struct node*create_sll(struct node*);
struct node*display(struct node*);
struct node*merging(struct node*,struct node*,struct node*);
struct node*add_node(struct node*,int);
int main()
{
	int ch;
	while(ch!=7)
	{
		printf("main menu\n");
		printf("1.create 1st list\n2.display 1st list\n3.create 2nd list\n4.display 2nd list\n5.merge 2 lists\n6.display merged list\n7.exit\n");
		printf("enter your ch:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:header1=create_sll(header1);
			break;
			case 2:header1=display(header1);
			break;
			case 3:header2=create_sll(header2);
			break;
			case 4:header2=display(header2);
			break;
			case 5:headermerge=merging(header1,header2,headermerge);
			break;
			case 6:headermerge=display(headermerge);
			break;
			case 7:exit(0);
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
	printf("enter the data to be inserted\n");
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
	printf("enter the data to be inserted\n");
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
		printf("list empty\n");
	}
	else
	{
		printf("list is below\n");
		ptr=header;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
	return header;
}
struct node*merging(struct node*header1,struct node*header2,struct node*headermerge)
{
	struct node*ptr1,*ptr2;
	ptr1=header1;
	ptr2=header2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->data==ptr2->data)
		{
			headermerge=add_node(headermerge,ptr1->data);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->data>ptr2->data)
		{
			headermerge=add_node(headermerge,ptr1->data);
			ptr1=ptr1->link;
		}
		else if(ptr1->data<ptr2->data)
		{
			headermerge=add_node(headermerge,ptr2->data);
			ptr2=ptr2->link;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			headermerge=add_node(headermerge,ptr2->data);
			ptr2=ptr2->link;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			headermerge=add_node(headermerge,ptr1->data);
			ptr1=ptr1->link;
		}
	}
	printf("lists merged\n");
	return headermerge;
}
struct node*add_node(struct node*HEADER,int D)
{
	struct node*NEW_NODE,*PTR;
	NEW_NODE=(struct node*)malloc(sizeof(struct node));
	NEW_NODE->data=D;
	if(HEADER==NULL)
	{
		NEW_NODE->link=NULL;
		HEADER=NEW_NODE;
	}
	else
	{
		PTR=HEADER;
		while(PTR->link!=NULL)
		{
			PTR=PTR->link;
		}
		PTR->link=NEW_NODE;
		NEW_NODE->link=NULL;
	}
	return HEADER;
}
