/*link list concatination*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node*header;
struct node*header1;
struct node*header2;
void beginsert1();
void beginsert2();
void display1();
void display2();
void concatination();
void display();
int main()
{
    int ch=0;
	while(1)
	{
		printf("**main menu**\n");
		printf("choose one option from the following list...\n");
		printf("1.insert value to the 1st list\n2.insert value to the 2nd list\n3.display the 1st list\n4.display the 2nd list\n5.concatination of 2 link list\n6.display the merged list\n7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:beginsert1();
			break;
			case 2:beginsert2();
			break;
			case 3:display1();
			break;
			case 4:display2();
			break;
			case 5:concatination();
			break;
			case 6:display();
			break;
			case 7:exit(0);
			default:
				printf("invalid choice\n");
		}
	}	
}
void beginsert1()
{
	struct node*ptr;
	int item1;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		printf("enter value\n");
		scanf("%d",&item1);
		ptr->data=item1;
		ptr->next=header1;
		header1=ptr;
		printf("node inserted in 1st list\n");
	}
}
void beginsert2()
{
	struct node*ptr1;
	int item2;
	ptr1=(struct node*)malloc(sizeof(struct node*));
	if(ptr1==NULL)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		printf("enter value\n");
		scanf("%d",&item2);
		ptr1->data=item2;
		ptr1->next=header2;
		header2=ptr1;
		printf("node inserted in 2nd list\n");
	}
}
void display1() //traversal
{
	struct node*ptr;
	ptr=header1;
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
void display2() //traversal
{
	struct node*ptr1;
	ptr1=header2;
	if(ptr1==NULL)
	{
		printf("nothing to print\n");
	}
	else
	{
		printf("printing values...\n");
		while(ptr1!=NULL)
		{
			printf("%d\n",ptr1->data);
			ptr1=ptr1->next;
		}
	}
}
void concatination()
{
	struct node*ptr;
	//ptr=header1->next;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=header2->next;
	ptr=header1->next;
	header=header1;
	printf("2 link list are merged\n");
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
			ptr=ptr->next;
		}
	}
}

