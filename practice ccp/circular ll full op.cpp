/*circular ll full op*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*header;
struct node*create_cll(struct node*);
struct node*display(struct node*);
struct node*insert_beg(struct node*);
struct node*insert_end(struct node*);
struct node*insert_any(struct node*);
struct node*delete_beg(struct node*);
struct node*delete_end(struct node*);
struct node*delete_any(struct node*);
void search(struct node*);
struct node*sort_list(struct node*);
int main(){
	int ch;
	while(ch!=11){
	printf("MAIN MENU\n");
	printf("1.create list\n2.display\n3.insert_beg\n4.insert_end\n5.insert_any\n6.delete_beg\n7.delete_end\n8.delete_any\n9.search\n10.sort_list\n11.exit\n");
   printf("enter your choice: \n");
   scanf("%d",&ch);
   switch(ch){
   	case 1:header=create_cll(header);
   	break;
   	case 2:header=display(header);
   	break;
   	case 3:header=insert_beg(header);
   	break;
   	case 4:header=insert_end(header);
   	break;
   	case 5:header=insert_any(header);
   	break;
   	case 6:header=delete_beg(header);
   	break;
   	case 7:header=delete_end(header);
   	break;
   	case 8:header=delete_any(header);
   	break;
   	case 9:search();
   	break;
   	case 10:header=sort_list(header);
   	break;
   	case 11:exit(0);
    default:
    	printf("invalid choice\n");
   }
 }
}
struct node*create_cll(struct node*header){
	int item;
	struct node*new_node,*ptr;
	printf("enter -1 to end\n");
	printf("enter the data: \n");
	scanf("%d",&item);
	while(item!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=item;
		if(header==NULL){
			new_node->link=NULL;
			header=new_node;
		}
		else{
			ptr=header;
			while(ptr->link!=header){
				ptr=ptr->link;
			}
			new_node->link=header;
			ptr->link=new_node;
		}
		printf("enter the data: \n");
	    scanf("%d",&item);
	}
	printf("list created\n");
	return header;
}
struct node*display(struct node*header){
	printf("the list is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr->link!=header){
		printf("%d",ptr->data);
		ptr=ptr->link;
	}
	return header;
}
struct node*insert_beg(struct node*header){
	int item;
	struct node*new_node,*ptr;
	if(header==NULL){
		printf("overflow,insertion not possible\n");
	}
	else{
		printf("enter the data to be inserted: \n");
 scanf("%d",&item);
new_node=(struct node*)malloc(sizeof(struct node*));
new_node->data=item;
ptr=header;
while(ptr->link!=header)
{
ptr=ptr->link;
}
ptr->link=new_node;
new_node->link=header;
header=new_node;
printf("node inserted at the end\n");
return header;
}
}
struct node*insert_end(struct node*header)
{
struct node*new_node,*ptr;
int item;
if(header==NULL)
{
printf("overflow:insertion not possible\n"); //memory bank returns NULL
}
else
{
printf("enter the data to be inserted: \n");
 scanf("%d",&item);
new_node=(struct node*)malloc(sizeof(struct node*));
new_node->data=item;
ptr=header;
while(ptr->link!=header)
{
ptr=ptr->link;
}
ptr->link=new_node;
new_node->link=header;
printf("node inserted at the end\n");
return header;
}
}
struct node*insert_any(struct node*header)
{
struct node*new_node,*ptr;
int loc,i,item;
if(header==NULL)
{
printf("overflow:insertion not possible\n"); //memory bank returns NULL
}
else
{
printf("enter the location at which the node has to be inserted\n");
 scanf("%d",&loc);
 printf("enter the data to be inserted: \n");
 scanf("%d",&item);
new_node=(struct node*)malloc(sizeof(struct node*));
new_node->data=item;
ptr=header;
for(i=0;i<loc-1;i++) //the linked list is started from 0th index here
{
ptr=ptr->link;
}
new_node->link=ptr->link;
ptr->link=new_node;
printf("node inserted at specific position\n");
return header;
}
}
struct node*delete_beg(struct node*header)
{
struct node*ptr;
if(header==NULL)
{
printf("deletion not possible\n"); //list is empty
}
else
{
ptr=header;
while(ptr->link!=header)
{
ptr=ptr->link;
 }
 ptr->link=header->link;
 free(header);
 header=ptr->link;
 printf("node is deleted from the begining\n");
 return header;
}
/*other process to do this else part
{
ptr=header;
 header=header->link;
free(ptr);
printf("node is deleted from the begining\n");
return header;
 }
 */
}
struct node*delete_end(struct node*header)
{
struct node*ptr,*ptr1;
if(header==NULL)
{
printf("deletion not possible\n"); //list is empty
}
else
{
ptr=header;
while(ptr->link!=header)
{
ptr1=ptr;
ptr=ptr->link;
}
ptr1->link=header;
free(ptr);
printf("node is deleted from the end\n");
return header;
 }
}
struct node*delete_any(struct node*header)
{
struct node*ptr,*ptr1;
int i,loc,item;
if(header==NULL)
{
printf("deletion not possible\n"); //list is empty
}
else
{
printf("enter the location after which the node has to be deleted\n");
 scanf("%d",&loc);
ptr=header;
for(i=0;i<=loc;i++) //the linked list is started from 0th index here
 {
ptr1=ptr;
ptr=ptr->link;
 }
ptr1->link=ptr->link;
free(ptr);
printf("node deleyed from specific position\n");
return header;
}
}
void search()
{
	struct node*ptr;
	int item,flag=0,loc,i=0;
	if(header==NULL)   
	{
		printf("list is empty\n");
	}
	else
	{
		printf("enter the data to be searched: \n");
		scanf("%d",&item);
		ptr=header;
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				flag=1;
				loc=i+1;
				break;
			}
			else
			{
				flag=0;
			}
			++i;
			ptr=ptr->link;
		}
		if(flag==0)
		{
			printf("search item not found\n");
		}
		else
		{
			printf("item found at location:%d\n",loc);
		}
	}	
} 
struct node*sort_list(struct node*header)
{
struct node*ptr1,*ptr2;
int temp;
ptr1=header;
while(ptr1->link!=header)
{
ptr2=ptr1->link;
while(ptr2!=header) //there are atleast 2 nodes in the list
{
if(ptr1->data>ptr2->data)
{
temp=ptr1->data;
ptr1->data=ptr2->data;
ptr2->data=temp;
}
ptr2=ptr2->link;
}
ptr1=ptr1->link;
}
printf("list sorted\n");
return header;
}
