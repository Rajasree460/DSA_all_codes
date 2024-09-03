/*stack using link list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*ptr;
}*top,*top1,*temp;
int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
int count=0;
int main()
{
	int no,ch,e;
	printf("1.push\n2.pop\n3.top\n4.empty\n5.exit\n6.display\n7.stack count\n8.destroy\n");
	create();
	while(1)
	{
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:int no;
			printf("enter data: ");
			scanf("%d",&no);
			push(no);
			break;
			case 2:pop();
			break;
			case 3:if(top==NULL)
			printf("no elements in stack\n");
			else
			{
				e=topelement();
				printf("top element:%d",e);
			}
			break;
			case 4:empty();
			break;
			case 5:exit(0);
			case 6:display();
			break;
			case 7:stack_count();
			break;
			case 8:destroy();
			break;
			default:
				printf("invalid choice\n");
				break;
		}
	}
}
/*create empty stack*/
void create()
{
	top=NULL;
}
/*count stack elements*/
void stack_count()
{
	printf("no of elements in stack:%d",count);
}
/*push data into stack*/
void push(int data)
{
	if (top==NULL)
	{
		top=(struct node*)malloc(1*sizeof(struct node));
		top->ptr=NULL;
		top->info=data;
	}
	else
	{
		temp=(struct node*)malloc(1*sizeof(struct node));
		top->ptr=top;
		top->info=data;
		top=temp;
	}
	
}
/*display stack elements*/
void display()
{
	top1=top;
	if(top1==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	while(top1!=NULL)
	{
		printf("%d",top1->info);
		top1=top1->ptr;
	}
}
/*pop operation on stack*/
void pop()
{
	top1=top;
	if(top1==NULL)
	{
		printf("error:trying to pop from empty stack\n");
	}
	else
	top1=top->ptr;
	printf("poped value:%d",top->info);	
	free(top);
	top=top1;
	count--;
}
/*return top element*/
int topelement()
{
	return(top->info);
}
/*check if stack is empty or not*/
void empty()
{
	if(top==NULL)
	printf("stack is empty\n");
	else
	printf("stack is not empty with %d elements\n",count);
}
/*destroy stack*/
void destroy()
{
	top1=top;
	while(top1!=NULL)
	{
		top1=top->ptr;
		free(top);
		top=top1;
		top1=top1->ptr;
	}
	free(top1);
	top=NULL;
	printf("all stack elements destroyed\n");
	count=0;
}
