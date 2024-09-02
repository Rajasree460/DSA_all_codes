/*insertion in binary tree as leaf node*/
#include<stdlib.h>
#include<stdio.h>

struct node {
int data;
struct node* right, * left;
};
struct node*tree;
void insert(struct node ** tree, int val)
{
    struct node *temp = NULL;
    if(!(*tree))
    {
        temp = (struct node *)malloc(sizeof(struct node*));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int main()
{
    node *root;
    node *tmp;
    //int I;

    root = NULL;
    /* Inserting nodes into tree */
    /*
    our tree after insertion
            9
          /   \
        4      15
      /   \   /   \
	 2     6 12   17
	 */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);    
    printf("the node containg the value 2 is a inserted leaf node\n");

}

