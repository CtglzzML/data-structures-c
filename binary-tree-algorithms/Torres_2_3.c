#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_from_list.c"

// Typedef for readability
typedef Node BinaryTree;

// Functions
// Returns 1 if both trees have the same structure otherwise returns 0
int struc_check(BinaryTree T1, BinaryTree T2){
    if(T1==NULL && T2 == NULL){
        return 1;
    }
    else if((T1== NULL && T2 !=NULL) ||(T1!= NULL && T2 ==NULL) ){
        return 0;
    }
    return (struc_check(T1->Left, T2->Left) && struc_check(T1->Right, T2->Right));
}

// Returns 1 if both trees have the same structure and the same values otherwise returns 0
int struc_and_value_check(BinaryTree T1, BinaryTree T2){
    if(T1==NULL && T2 == NULL){
        return 1;
    }
    else if((T1== NULL && T2 !=NULL) ||(T1!= NULL && T2 ==NULL) ){
        return 0;
    }

    if(T1->Element != T2->Element){
        return 0;
    }else{
        int left_subtree = struc_and_value_check(T1->Left, T2->Left);
        int right_subtree = struc_and_value_check(T1->Right, T2->Right);
        return left_subtree && right_subtree;
    }
}

int main()
{   
    // Creating the first tree
    int n1;
    printf("Enter the number of data elements in the first tree: ");
    scanf ("%d", &n1);
    int *arr1 = (int *) malloc(sizeof(int)*n1); // Creating dynamic array to store elements
    printf("Enter the tree data elements (space separated integers representing a complete binary tree): ");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    
    BinaryTree r1 = makeTree(n1, arr1);
    r1 = removeNullNodes(r1);

    //Second tree
    int n2;
    printf("Enter the number of data elements in the second tree: ");
    scanf ("%d", &n2);
    int *arr2 = (int *) malloc(sizeof(int)*n2); // Creating dynamic array to store elements
    printf("Enter the tree data elements (space separated integers representing a complete binary tree): ");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    
    BinaryTree r2 = makeTree(n2, arr2);
    r2 = removeNullNodes(r2);

    // Enter the function calls to the code for the 
    // different questions for Assignment 2 below this line

    int choice=0;
    do {
        printf("\nEnter a choice:\n");
        printf("[1] Structure Identical Check\n");
        printf("[2] Structure and Value Identical Check\n");
        printf("[3] Exit\n");
        printf("Type here: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:{
            // Converting the returns into "True or False"
            int result = struc_check(r1, r2); 
            if(result == 1){
                printf("True.\n");
            } else {
                printf("False.\n");
            }
            break;
        }
        case 2: {
            // Converting the returns into "True or False"
            int result2 = struc_and_value_check(r1, r2);
            if(result2 == 1){
                printf("True.\n");
            } else {
                printf("False.\n");
            }
            break;
        }
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Choice must be between 1 to 3!\n");
            break;
        }
    } while (choice !=3);

    // Cleaning and liberating space
    MakeEmpty(r1);
    MakeEmpty(r2);
    free(arr1);
    free(arr2);

    // End of the program
    return 0;
}