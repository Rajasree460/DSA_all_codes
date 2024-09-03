#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*link;
};
while(1)
{
	struct node*start=NULL;
	struct node*create_all(struct node*);
	struct node*traversal(struct node*);
	int main(argc,char*arcv[])
	{
		int option;
		printf("** main manue**");
		printf("1.create a list\n");
		printf("2.traversal(display) the list\n");
		printf("3.exit\n");
		printf("choose a option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:start=create_all(strat);
			break;
			case 2:start=traversal(start);
			break;
			case 3:exit(0);
			default:
				printf("invalid choice\n");
		}
		return 0;
	}
}
struct node*create_all(struct node*start)
{
	struct node*new_node,*ptr;
	int num;
	printf("enter -1 to end\n");
	printf("enter the data:  ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
	
	}
	if(start==NULL)
	{
		new_node->link=NULL;
		start=new_node;
	}
	else

{
	ptr=start;
	while(ptr->link!=NULL)
	ptr=ptr->link;
	ptr->link=new_node;
}
return start;
}
struct node*traversal(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	return start;
}

