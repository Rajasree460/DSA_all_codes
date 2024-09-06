/*stack using linked list*/
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack*link;
};
struct stack*top;   //stack_head=top
struct stack*push(struct stack*,int);
struct stack*pop(struct stack*);
struct stack*display(struct stack*);
int main(){
	int item,ch;
	while(1){
		printf("MAIN MENU\n");
		printf("1-push\n");
		printf("2-pop\n");
		printf("3-display\n");
		printf("4-exit\n");
		printf("enter your choice: \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("enter the data to be pushed: \n");
			scanf("%d",&item);
			top=push(top,item);
			break;
			case 2:top=pop(top);
			break;
			case 3:top=display(top);
			break;
			case 4:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
struct stack*push(struct stack*top,int item){
	struct stack*new_node;
	new_node=(struct stack*)malloc(sizeof(struct stack*));
	new_node->data=item;
	if(top==NULL){
		new_node->link=NULL;
		top=new_node;
	}
	else{
		top->link=new_node;
		top=new_node;
	}
	printf("the node contains item is pushed\n");
	return top;
}
struct stack*pop(struct stack*top){
	struct stack*ptr;
	if(top==NULL){
		printf("stack is empty\n");
	}
	else{
		ptr=top;
		top=top->link;
		printf("the popped item is:%d\n",ptr->data);
		free(ptr);
	}
	return top;
}
struct stack*display(struct stack*top){
	struct stack*ptr;
	if(top==NULL){
		printf("stack is empty\n");
	}
	else{
		printf("the stack is below\n");
		ptr=top;
		while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	}
	return top;
}
