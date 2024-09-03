/*insertion in b t */
#include<stdio.h>
#include<stdlib.h> 
 struct node 
 { 
 int data; 
 struct node *left, *right; 
 };
 struct node* create(); 
 void display(struct node *ptr,int level);
 int main() 
 { 
 struct node *root; 
 root = create(); 
 } 
struct node *create() 
{ 
 struct node *temp; 
 int data,choice; 
 temp = (struct node *)malloc(sizeof(struct node)); 
 printf("Press 0 to exit"); 
 printf("\nPress 1 for new node");
 printf("\nPress 2 for display"); 
 printf("Enter your choice : \n"); 
 scanf("%d", &choice); 
 if(choice==0) 
{ 
return 0; 
} 
else 
{ 
 printf("Enter the data:"); 
 scanf("%d", &data); 
 temp->data = data; 
 printf("Enter the left child of %d", data); 
 temp->left = create(); 
printf("Enter the right child of %d", data); 
temp->right = create(); 
return temp; 
} 
}
void display(struct node *ptr,int level)
{
 int i;
 if(ptr == NULL )/*Base Case*/
 return;
 else
 {
 display(ptr->right, level+1);
 printf("\n");
 for (i=0; i<level; i++)
 printf(" ");
 printf("%d", ptr->data);
 display(ptr->left, level+1);
 }
}

