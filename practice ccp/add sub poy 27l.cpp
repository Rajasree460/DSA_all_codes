/*add sub poly*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int exp;
	int coff;
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
struct node*add_node(struct node*,int,int);
int main()
{
	int ch;
	while(ch!=9)
	{
		printf("main menu\n");
		printf("1.create 1st poly\n2.display 1st poly\n3.create 2nd poly\n4.display 2nd poly\n5.add 2 poly\n6.display the result of add\n7.subtract 2 poly\n8.display the result of subtraction\n9.exit\n");
		printf("enter your ch:\n");
		scanf("%d",&ch);
		switch(ch)
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
				printf("invalid ch\n");
		}
	}
}
struct node*create_poly(struct node*header)
{
	int e,c;
	struct node*new_node,*ptr;
	printf("enter -1 in exp to end\n");
	printf("enter exp num:\n");
	scanf("%d",&e);
	printf("enter coff num:\n");
	scanf("%d",&c);
	while(e!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->exp=e;
		new_node->coff=c;
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
		printf("enter exp num:\n");
	scanf("%d",&e);
	if(e==-1)
	{
		break;
		printf("enter coff num:\n");
	scanf("%d",&c);
	}
	}
	printf("poly created\n");
	return header;
}
struct node*display_poly(struct node*header)
{
	struct node*ptr;
	
		printf("poly is below\n");
		ptr=header;
		while(ptr!=NULL)
		{
			printf("%dx^%d+",ptr->coff,ptr->exp);
			ptr=ptr->link;
		}
	return header;
}
struct node*add_poly(struct node*header1,struct node*header2,struct node*headeradd)
{
	int sum_coff;
	struct node*ptr1,*ptr2;
	ptr1=header1;
	ptr2=header2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			sum_coff=ptr1->coff+ptr2->coff;
			headeradd=add_node(headeradd,ptr1->exp,sum_coff);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			headeradd=add_node(headeradd,ptr1->exp,ptr1->coff);
			ptr1=ptr1->link;
		}
		else if(ptr1->exp<ptr2->exp)
		{
			headeradd=add_node(headeradd,ptr2->exp,ptr2->coff);
			ptr2=ptr2->link;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			headeradd=add_node(headeradd,ptr2->exp,ptr2->coff);
			ptr2=ptr2->link;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			headeradd=add_node(headeradd,ptr1->exp,ptr1->coff);
			ptr1=ptr1->link;
		}
	}
	printf("addition done\n");
	return headeradd;
}
struct node*sub_poly(struct node*header1,struct node*header2,struct node*headersub)
{
	int sub_coff;
	struct node*ptr1,*ptr2;
	ptr1=header1;
	ptr2=header2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			sub_coff=ptr1->coff-ptr2->coff;
			headersub=add_node(headersub,ptr1->exp,sub_coff);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			headersub=add_node(headersub,ptr1->exp,ptr1->coff);
			ptr1=ptr1->link;
		}
		else if(ptr1->exp<ptr2->exp)
		{
			headersub=add_node(headersub,ptr2->exp,ptr2->coff);
			ptr2=ptr2->link;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			headersub=add_node(headersub,ptr2->exp,ptr2->coff);
			ptr2=ptr2->link;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			headersub=add_node(headersub,ptr1->exp,ptr1->coff);
			ptr1=ptr1->link;
		}
	}
	printf("subtraction done\n");
	return headersub;
}
struct node*add_node(struct node*HEADER,int E,int C)
{
	struct node*NEW_NODE,*PTR;
	NEW_NODE=(struct node*)malloc(sizeof(struct node));
		NEW_NODE->exp=E;
		NEW_NODE->coff=C;
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
