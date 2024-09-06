/*merging of 2 sll*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*header1;
struct node*header2;
struct node*headermerge;
struct node*headercon;
struct node*create_sll(struct node*);
struct node*display(struct node*);
struct node*merging(struct node*);
struct node*concatination(struct node*,struct node*,struct node*);
int main(){
	int ch;
	while(ch!=7){
		printf("MAIN MENU\n");
		printf("1.create 1st list\n2.display 1st list\n3.create 2nd list\n4.display 2nd list\n5.merge 2 lists\n6.display merged list\n7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:header1=create_sll(header1);
			break;
			case 2:header1=display(header1);
			break;
			case 3:header2=create_sll(header2);
			break;
			case 4:header2=display(header2);
			break;
			case 5:headermerge=merging(headermerge);
			break;
			case 6:headermerge=display(headermerge);
			break;
			case 7:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
struct node*create_sll(struct node*header){
	int item;
	struct node*new_node,*ptr;
	printf("enter -1 for end\n");
	printf("enter your data: \n");
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
			while(ptr->link!=NULL){
				ptr=ptr->link;
			}
			ptr->link=new_node;
			new_node->link=NULL;
		}
		printf("enter your data: \n");
	    scanf("%d",&item);
	}
	printf("list created\n");
	return header;
}
struct node*display(struct node*header){
	printf("the list is below\n");
	struct node*ptr;
	ptr=header;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return header;
}
struct node*merging(struct node*headermerge){
	int temp;
	struct node*ptr1,*ptr2;
	headermerge=concatination(header1,header2,headercon);
	ptr1=headermerge;
	while(ptr1->link!=NULL){
		ptr2=ptr1->link;
		while(ptr2!=NULL){
			if(ptr1->data>ptr2->data){
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->link;
		}
	ptr1=ptr1->link;	
	}
	printf("2 sll are merged\n");
	return headermerge;
}
struct node*concatination(struct node*header1,struct node*header2,struct node*headercon){
	struct node*ptr1;
	ptr1=header1;
	while(ptr1->link!=NULL){
		ptr1=ptr1->link;
	}
	ptr1->link=header2;
	headercon=header1;
	return headercon;
}
