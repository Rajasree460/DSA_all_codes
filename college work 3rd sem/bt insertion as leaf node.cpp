/*insertion in a b.t as leaf node*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};
struct node*new_root;
struct node*create_newnode(struct node*);
struct node*insert_left(struct  node*);
struct node*display_left(struct node*);
struct node*insert_right(struct node*);
struct node*display_right(struct node*);
//creating root node
	struct node*create_newnode(struct node*new_root){
		int value;
		new_root= (struct node*)malloc(sizeof(struct node));
		printf("enter your data of root: \n");
		scanf("%d",&value);
        new_root->data = value;
        new_root->left = NULL;
        new_root->right = NULL;
        return new_root;
	}
int main(){
	int op;
	create_newnode(new_root);  //calling the creating func of root node
	while(op!=5){	
	printf("MAIN MENU\n");
	printf("choose in where you want to insert a leaf node\n");
	printf("1.insert at left\n2.display tree with left child\n3.insert at right\n4.display tree with right child\n5.exit\n");
	printf("enter your option: \n");
	scanf("%d",&op);
	switch(op){
		 case 1:new_root=insert_left(new_root);
		 break;
		 case 2:new_root=display_left(new_root);
		 break;
		 case 3:new_root=insert_right(new_root);
		 break;
		 case 4:new_root=display_right(new_root);
		 break;
		 case 5:exit(0);
		 default:
		 	printf("invalid choice\n");
	}
}	
}
//inserting node at left
struct node*insert_left(struct node*new_root){
	int item;
	struct node*ptr,*new_leaf;
	new_leaf=(struct node*)malloc(sizeof(struct node));
	printf("enter your data which you want to insert at left: \n");
	scanf("%d",&item);
	ptr=new_root;
	if(ptr->left==NULL){
		new_leaf->data=item;
		new_root->left=new_leaf;
		new_leaf->left=NULL;
		new_leaf->right=NULL;	
		ptr=new_leaf;
	}
	printf("node inserted as leaf node at left of root\n");
	return new_root;
}
//displaying the tree after adding a leaf node at left
struct node*display_left(struct node*new_root){
	printf("the tree is below\n");
	struct node*ptr;
	ptr=new_root;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->left;
	}
	return new_root;
}
//inserting node at right
struct node*insert_right(struct node*new_root){
	int item;
	struct node*ptr,*new_leaf;
	new_leaf=(struct node*)malloc(sizeof(struct node));
	printf("enter your data which you want to insert at left: \n");
	scanf("%d",&item);
	ptr=new_root;
	if(ptr->right==NULL){
		new_leaf->data=item;
		new_root->right=new_leaf;
		new_leaf->left=NULL;
		new_leaf->right=NULL;	
		ptr=new_leaf;
	}
	printf("node inserted as leaf node at right of root\n");
	return new_root;
}
//displaying the tree after adding a leaf node at right
struct node*display_right(struct node*new_root){
	printf("the tree is below\n");
	struct node*ptr;
	ptr=new_root;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->right;
	}
	return new_root;
}
