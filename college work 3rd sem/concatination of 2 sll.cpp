/*concatination of two single linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*header1;
struct node*header2;
struct node*headerconcatinate;
struct node*create_ll(struct node*);
struct node*display(struct node*);
struct node*concatination(struct node*,struct node*,struct node*);
int main()
{
	int choice=0;
	while(choice!=7)
	{
		printf("**main menu**\n");
		printf("1.create 1st list\n2.display 1st list\n3.create 2nd list\n4.display 2nd list\n5.concatinate 2 lists\n6.display the result of concatination\n7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:header1=create_ll(header1);
			break;
			case 2:header1=display(header1);
			break;
			case 3:header2=create_ll(header2);
			break;
			case 4:header2=display(header2);
			break;
			case 5:headerconcatinate=concatination(header1,header2,headerconcatinate);
			break;
			case 6:headerconcatinate=display(headerconcatinate);
			break;
			case 7:exit(0);
			default:
				printf("invalid choice\n");
	    }
    }
}
struct node*create_ll(struct node*header)
{
	struct node*new_node,*ptr;
	int item;
	printf("enter -1 to end\n");
	printf("enter the data: \n");
	scanf("%d",&item);
	while(item!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node*));
		new_node->data=item;
		if(header==NULL)        //list is empty
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
	printf("link list is created\n");
	return header;
}
struct node*display(struct node*header)
{
	printf("the linked list is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL)         //list is not empty
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
    }
    return header;
}
struct node*concatination(struct node*header1,struct node*header2,struct node*headerconcatinate)
{
	struct node*ptr;
	ptr=header1;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=header2;
	headerconcatinate=header1;
	printf("2 lists are concatinated\n");
	return headerconcatinate;
}
