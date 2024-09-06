/*stack using array*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=0,stack[MAX];
void push();
void pop();
void display();
int main(){
	int ch;
	while(1){
		printf("MAIN MENU\n");
		printf("press 1 for push\n");
		printf("press 2 for pop\n");
		printf("press 3 for display\n");
		printf("press 4 for exit\n");
		printf("enter your choice: \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
void push(){
	int item;
	if(top==MAX){
		printf("stack full\n");
	}
	else{
		printf("enter the value what you want to push: \n");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
	printf("item inserted\n");
}
void pop(){
	int x;
	if(top<1){
		printf("stack empty\n");
	}
	else{
		x=stack[top];
		printf("the popped item is: %d\n",x);
		top--;
	}
	printf("the item popped out\n");
}
void display(){
	int i;
	if(top<1){
		printf("stack empty\n");
	}
	else{
	printf("the stack is below:\n");	
	for(i=top;i>=1;i--){
		printf("%d\n",stack[i]);
	}
}
}
