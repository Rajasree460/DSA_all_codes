/*circular link list*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
int info;
struct Node *next;
}node;
node *front=NULL,*rear=NULL,*temp;
void create();
void del();
void display();
int main()
{
int ch;
while(1)
{
printf("1 to create the element : \n");
printf("2 to delete the element : \n");
printf("3 to display the queue : \n");
printf("4 to exit from main : \n");
printf("Enter your choice : \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
del();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice :\n");
}
}
return 0;
}
void create()
{
node *newnode;
newnode=(node*)malloc(sizeof(node));
printf("Enter the node value : \n");
scanf("%d",&newnode->info);
newnode->next=NULL;
if(rear==NULL)
front=rear=newnode;
else
{
rear->next=newnode;
rear=newnode;
}
rear->next=front;
}
void del()
{
temp=front;
if(front==NULL)
printf("Underflow :\n");
else
{
if(front==rear)
{
printf("%d\n",front->info);
front=rear=NULL;
}
else
{
printf("%d\n",front->info);
front=front->next;
rear->next=front;
}
temp->next=NULL;
free(temp);
}
}
void display()
{
temp=front;
if(front==NULL)
printf("Empty\n");
else
{
printf("\n");
for(;temp!=rear;temp=temp->next)
printf("%d\n",temp->info);

}
}
