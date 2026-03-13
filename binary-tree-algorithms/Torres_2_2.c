#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_from_list.c"

// Typedef for readability
typedef Node BinaryTree;

// Defining functions
// Height return an int value with the longest path of the tree (by edges)
int height(BinaryTree T){
    if(T==NULL){
        return -1;
    }
    int left_h = height(T->Left);
    int right_h = height(T->Right);

    if (right_h > left_h){
        return 1 + right_h;
    } else {
        return 1 + left_h;
    }
}

// path_cost returns an int value with the cost of the most expensive path
int path_cost(BinaryTree T){
    if (T==NULL){
        return 0;
    }

    int left_c = path_cost(T->Left);
    int right_c = path_cost(T->Right);

    if (right_c > left_c){
        return T->Element + right_c;
         
    } else {
        return T->Element + left_c;
    }
}

int main(){   

    // Variable to store number of data
    int n;
    printf("Enter the number of data elements in the tree: ");
    scanf ("%d", &n);
    int *arr = (int *) malloc(sizeof(int)*n); // Creating dynamic array to store elements
    printf("Enter the tree data elements (space separated integers representing a complete binary tree): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    BinaryTree r = makeTree(n, arr);
    r = removeNullNodes(r);

    printf("Inorder traversal: ");
    PrintTree(r);
    printf("\n");

    // Enter the function calls to the code for the 
    // different questions for Assignment 2 below this line

    // User choice
    int choice = 0;
    do {
        printf("\nEnter a choice: \n");
        printf("[1] Tree Height\n");
        printf("[2] Max Path Cost\n");
        printf("[3] Exit\n");
        printf("Type here: ");
        scanf("%d", &choice);

        switch (choice) // switch to handle all cases
        {
        case 1:
            // Tree height
            printf("Tree height: %d\n", height(r));
            break;
        case 2:
            // Max Path cost function
            printf("Max path cost: %d\n", path_cost(r));
            break;
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice, must be a number between 1 and 3!\n");
            break;
        }
    } while (choice != 3);

    // Cleaning and liberating space
    MakeEmpty(r);
    free(arr);

    // End of the program
    return 0;
}