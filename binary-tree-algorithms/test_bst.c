#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main() // I've modified the original main and implemented the menu driven interface
{
    SearchTree t =NULL; // Creating the tree 
    int choice; // To store user choice
    int node_count =0; // Counter of nodes (used in LevelOrder function)
    do {
        //User Menu
        printf("\nEnter a choice:\n");
        printf("[1] Insert\n");
        printf("[2] findMin_K\n");
        printf("[3] numLeafNodes\n");
        printf("[4] LevelOrder\n");
        printf("[5] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) //Switch to handle different user choices
        {

        case 1: {
            int x;
            printf("Enter element to insert to the tree: ");
            scanf("%d", &x);

            // Check if the element is already on the tree
            if(Find(x, t)==NULL){
                t = Insert(x, t);
                node_count++; // Increment node count if Insert is successfull
            } else {
                printf("Value is already on the tree!\n");
            }
            break;
        }

        case 2: {
            int k;
            printf("Enter kth: ");
            scanf("%d", &k);
            Position p = findMin_K(t, k);
            if(p != NULL) // Checking k is valid
                printf("Result: %d\n", Retrieve(p)); // Using retrieve function to print
            else
                printf("Not found!\n");
            break;
        }

        case 3:
            printf("Number of leaf nodes: %d\n", numLeafNodes(t)); // numLeafNodes returns number of nodes
            break;

        case 4: {
            ElementType * p = LevelOrder(t); // p is a pointer to the array
            if(p!=NULL){
                printf("Level order: ");
                for(int i = 0; i<node_count; i++){ // Using a for loop to print the array
                    printf("%d ",p[i]);
                }
                printf("\n");
                free(p);

            }else{
                printf("Tree is empty.\n"); // When p == NULL, means the tree is empty
            }
            break;
        }

        case 5:
            printf("Exiting...\n"); // MEssage to exit the program
            break;

        default:
            printf("Invalid choice\n"); // Handling invalid choices
            break;
        }

    } while(choice != 5);

    MakeEmpty(t); // Free space

    // End of the program
    return 0;
    
}
