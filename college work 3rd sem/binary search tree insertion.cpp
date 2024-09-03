/*binary search tree-insertion*/
#include<stdio.h>  
#include<stdlib.h>  
Void insert(int);  
Struct node  
{  
    Int data;  
    Struct node *left;   
    Struct node *right;   
};  
Struct node *root;  
Void main ()  
{  
    Int choice,item;  
    Do   
    {  
        Printf("\nEnter the item which you want to insert?\n");  
        Scanf("%d",&item);  
        Insert(item);  
        Printf("\nPress 0 to insert more ?\n");  
        Scanf("%d",&choice);  
    }while(choice == 0);  
}  
Void insert(int item)  
{  
    Struct node *ptr, *parentptr , *nodeptr;  
    Ptr = (struct node *) malloc(sizeof (struct node));  
    If(ptr == NULL)  
    {  
        Printf("can't insert");  
    }  
    Else   
    {  
    Ptr -> data = item;  
    Ptr -> left = NULL;  
    Ptr -> right = NULL;   
    If(root == NULL)  
    {  
        Root = ptr;  
        Root -> left = NULL;  
        Root -> right = NULL;  
    }  
    Else   
    {  
        Parentptr = NULL;  
        Nodeptr = root;   
        While(nodeptr != NULL)  
        {  
            Parentptr = nodeptr;   
            If(item < nodeptr->data)  
            {  
                Nodeptr = nodeptr -> left;   
            }   
            Else   
            {  
                Nodeptr = nodeptr -> right;  
            }  
        }  
        If(item < parentptr -> data)  
        {  
            Parentptr -> left = ptr;   
        }  
        Else   
        {  
            Parentptr -> right = ptr;   
        }  
    }  
    Printf("Node Inserted");  
    }  
}  





