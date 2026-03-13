#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};


SearchTree
MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position
Find( ElementType X, SearchTree T )
{
    if( T == NULL )
        return NULL;
    if( X < T->Element )
        return Find( X, T->Left );
    else
    if( X > T->Element )
        return Find( X, T->Right );
    else
        return T;
}

Position
FindMin( SearchTree T )
{
    if( T == NULL )
        return NULL;
    else
    if( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

Position
FindMax( SearchTree T )
{
    if( T != NULL )
        while( T->Right != NULL )
            T = T->Right;

    return T;
}

SearchTree
Insert( ElementType X, SearchTree T )
{
/* 1*/      if( T == NULL )
    {
        /* Create and return a one-node tree */
/* 2*/          T = malloc( sizeof( struct TreeNode ) );
/* 3*/          if( T == NULL )
        {
/* 4*/              printf( "Out of space!!!" );
            exit(1);
        }
        else
        {
/* 5*/              T->Element = X;
/* 6*/              T->Left = T->Right = NULL;
        }
    }
    else
/* 7*/      if( X < T->Element )
/* 8*/          T->Left = Insert( X, T->Left );
    else
/* 9*/      if( X > T->Element )
/*10*/          T->Right = Insert( X, T->Right );
    /* Else X is in the tree already; we'll do nothing */

/*11*/      return T;  /* Do not forget this line!! */
}

SearchTree
Delete( ElementType X, SearchTree T )
{
    Position TmpCell;

    if( T == NULL )
    {
        printf( "Out of space!!!" );
        exit(1);
    }
    else
    if( X < T->Element )  /* Go left */
        T->Left = Delete( X, T->Left );
    else
    if( X > T->Element )  /* Go right */
        T->Right = Delete( X, T->Right );
    else  /* Found element to be deleted */
    if( T->Left && T->Right )  /* Two children */
    {
        /* Replace with smallest in right subtree */
        TmpCell = FindMin( T->Right );
        T->Element = TmpCell->Element;
        T->Right = Delete( T->Element, T->Right );
    }
    else  /* One or zero children */
    {
        TmpCell = T;
        if( T->Left == NULL ) /* Also handles 0 children */
            T = T->Right;
        else if( T->Right == NULL )
            T = T->Left;
        free( TmpCell );
    }

    return T;
}


ElementType
Retrieve( Position P )
{
    return P->Element;
}

void PrintTree(SearchTree T)
{
    if ( T!= NULL )
    {
        PrintTree(T->Left);
        printf("%d ", Retrieve(T));
        PrintTree(T->Right);    }
}

// Functions from Question 4
// Helper function used internally by findMin_K
static Position helper(SearchTree T, int k, int * ptr){ 
    if(T==NULL || k <=0){ // Making sure the tree is not null and k is more than 0
        return NULL;
    }
    // Go to the left
    Position l = helper(T->Left, k, ptr); // Go to the left subtree

    // Node
    if (l != NULL){ // if the element is found, return l
        return l;
    }
    (*ptr)++; // adding +1 to the counter everytime we visit a node
    if(*ptr == k){ // if the counter = k -> element is found
        return T;
    }

    // Go to the right
    Position r = helper(T->Right, k, ptr); // Go to the right subtree and do the same
    return r;
            
}

Position findMin_K(SearchTree T, int k){
    int counter = 0; // Counter for k-element
    int * ptr_c = &counter; // Pointer to counter
    return helper(T, k, ptr_c); // Using helper function to find the kth smallest element
}

// Num_leaf_nodes returns the number of leaf nodes in a BST
int numLeafNodes(SearchTree T){
    if (T==NULL){ // Checking T is not null
        return 0;
    }
    if (T->Left == NULL && T->Right == NULL){ // If T does not have childrens means it is a leaf node
        return 1; 
    }
    int l=numLeafNodes(T->Left); // Go to the left
    int r=numLeafNodes(T->Right); // Go to the right
    return l+r; // Return sum of both subtrees
}

// count_nodes function is used internally by level order function
static int count_nodes(SearchTree T){ 
    if (T==NULL){
        return 0;
    } 

    int l = count_nodes(T->Left);
    int r = count_nodes(T->Right);
    int sum = 1 + l + r;
    return sum;
}

ElementType * LevelOrder(SearchTree T){
    if (T==NULL){
        return NULL;
    } 
    int nodes = count_nodes(T); // How many nodes are in T
    ElementType * arr = (ElementType*)malloc(sizeof(ElementType)*nodes); // Array to store the result
    Position * queue = (Position *)malloc(sizeof(Position)*nodes); // Queue for tree level hierarchy

    // Control variables
    int front=0;
    int rear=0;
    int i=0;

    queue[rear++]=T; // First element to the queue
    while (front<rear){ // Function to extract all nodes by level and adding them to the array
        Position current = queue[front++];
        arr[i++] = current->Element;
        if (current->Left != NULL){
            queue[rear++] = current->Left;
        }
        if (current->Right != NULL){
            queue[rear++] = current->Right;
        }
    }
    free(queue); // Liberating space
    return arr; // Return the result, a pointer to an array with all the nodes by level order
}












