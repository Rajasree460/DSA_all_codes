/*addition and subtraction polynomial*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int exp;
	struct node*link;
};
struct node*header1;
struct node*header2;
struct node*headeradd;
struct node*headersub;
struct node*create_poly(struct node*);
struct node*display_poly(struct node*);
struct node*add_poly(struct node*,struct node*,struct node*);
struct node*sub_poly(struct node*,struct node*,struct node*);
struct node*add_node(struct node*,int ,int);
int main()
{
	int choice;
	while(choice!=9)
	{
		printf("**main menu**\n");
		printf("1.enter the 1st poly\n2.display the 1st poly\n3.enter the 2nd poly\n4.display the 2nd poly\n5.add the polynomials\n6.display the result of addition\n7.subtraction of the polynomials\n8.display the result of subtraction\n9.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:header1=create_poly(header1);
			break;
			case 2:header1=display_poly(header1);
			break;
			case 3:header2=create_poly(header2);
			break;
			case 4:header2=display_poly(header2);
			break;
			case 5:headeradd=add_poly(header1,header2,headeradd);
			break;
			case 6:headeradd=display_poly(headeradd);
			break;
			case 7:headersub=sub_poly(header1,header2,headersub);
			break;
			case 8:headersub=display_poly(headersub);
			break;
			case 9:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
struct node*create_poly(struct node*header)
{
	struct node*new_node,*ptr;
	int e,c;
	printf("enter the exp num: \n");
	scanf("%d",&e);
	printf("enter its coefficient: \n");
	scanf("%d",&c);
	while(e!=-1)
	{
		if(header==NULL)
		{
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->exp=e;
			new_node->coeff=c;
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
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->exp=e;
			new_node->coeff=c;
			new_node->link=NULL;
			ptr->link=new_node;
		}
		printf("enter the no of exp: \n");
		scanf("%d",&e);
		if(e==-1)
		{
			break;
			printf("enter its coefficient: \n ");
			scanf("%d",&c);
		}
	}
	printf("polynomial is created\n");
	return header;
}
struct node*display_poly(struct node*header)
{
	printf("the polynomial is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%dx%d\t\n",ptr->coeff,ptr->exp);
		ptr=ptr->link;
	}
	return header;
}
struct node*add_poly(struct node*header1,struct node*header2,struct node*headeradd)
{
	struct node*ptr1,*ptr2;
	int sum_coeff;
	ptr1=header1;
	ptr2=header2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			sum_coeff=ptr1->coeff+ptr2->coeff;
			headeradd=add_node(headeradd,ptr1->exp,sum_coeff);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			headeradd=add_node(headeradd,ptr1->exp,ptr1->coeff);
			ptr1=ptr1->link;
		}
		else if(ptr1->exp<ptr2->exp)
		{
			headeradd=add_node(headeradd,ptr2->exp,ptr2->coeff);
			ptr2=ptr2->link;
		}
	}
	/*if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			headeradd=add_node(headeradd,ptr2->exp,ptr2->coeff);
			ptr2=ptr2->link;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			headeradd=add_node(headeradd,ptr1->exp,ptr1->coeff);
			ptr1=ptr1->link;
		}
	}*/
	printf("addition of polynomial is done\n");
	return headeradd;
}
struct node*sub_poly(struct node*header1,struct node*header2,struct node*headersub)
{
	struct node*ptr1,*ptr2;
	int sub_coeff;
	ptr1=header1;
	ptr2=header2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			sub_coeff=ptr1->coeff-ptr2->coeff;
			headersub=add_node(headersub,ptr1->exp,sub_coeff);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			headersub=add_node(headersub,ptr1->exp,ptr1->coeff);
			ptr1=ptr1->link;
		}
		else if(ptr1->exp<ptr2->exp)
		{
			headersub=add_node(headersub,ptr2->exp,ptr2->coeff);
			ptr2=ptr2->link;
		}
	}
	/*if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			headersub=add_node(headersub,ptr2->exp,ptr2->coeff);
			ptr2=ptr2->link;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			headersub=add_node(headersub,ptr1->exp,ptr1->coeff);
			ptr1=ptr1->link;
		}
	}*/
	printf("subtraction of polynomial is done\n");
	return headersub;
}
struct node*add_node(struct node*HEADER,int E,int C)
{
	struct node*NEW_NODE,*PTR;
	if(HEADER==NULL)
		{
			NEW_NODE=(struct node*)malloc(sizeof(struct node*));
			NEW_NODE->exp=E;
			NEW_NODE->coeff=C;
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
			NEW_NODE=(struct node*)malloc(sizeof(struct node*));
			NEW_NODE->exp=E;
			NEW_NODE->coeff=C;
			NEW_NODE->link=NULL;
			PTR->link=NEW_NODE;
		}
	return HEADER;
}
