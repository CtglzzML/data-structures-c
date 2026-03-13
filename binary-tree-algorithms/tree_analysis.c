#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_from_list.c"

// Typedef
typedef Node BinaryTree; // For better readability 

// Functions
// Return counter which is just a counter, everytime we find a valid key, counter increments by 1
ElementType count_nodes(BinaryTree T){ // As Dr.Raj said, count_nodes function should return an int.
    if(T==NULL){
        return 0;
    }
    int count=1;
    count += count_nodes(T->Left);
    count += count_nodes(T->Right);

    return count;
}

// Same concept than count_nodes but here instead of add +1 to a counter, we add the key to the total variable
ElementType sum_keys(BinaryTree T){
    if (T==NULL){
        return 0;
    }
    int total = T->Element;
    total += sum_keys(T->Left);
    total += sum_keys(T->Right);

    return total;
}

// Compare the current key with the maximum key in the left and right subtrees
ElementType max_key(BinaryTree T){
    if ( T==NULL){
        return -1;
    }
    int max = T->Element;
    int max_l = max_key(T->Left);
    int max_r = max_key(T->Right);
    
    if(max_l > max){
        max=max_l;
    }
    if(max_r > max){
        max=max_r;
    }
    return max;
}

// Print all keys in the tree that are smaller than v
void print_below(BinaryTree T, ElementType v){
    if(T==NULL){
        return;
    }
    if (T->Element < v){
        printf("%d ", T->Element);   
    }
    print_below(T->Left, v);
    print_below(T->Right, v);    
}

// Main program
int main()
{   // User inputs
    int n;
    printf("Enter the number of data elements in the tree: ");
    scanf ("%d", &n);
    int *arr = (int *) malloc(sizeof(int)*n);
    printf("Enter the tree data elements (space separated integers representing a complete binary tree): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    Node r = makeTree(n, arr);
    r = removeNullNodes(r);

    printf("Inorder traversal: ");
    PrintTree(r);
    printf("\n");

    // Enter the function calls to the code for the 
    // different questions for Assignment 2 below this line

    // Variable to store value for funtion print_below
    ElementType v;

    // Creating the user menu interface
    int choice = 0;
    do {
        printf("\nEnter a choice: \n");
        printf("[1] Count Nodes\n");
        printf("[2] Sum Keys\n");
        printf("[3] Max Key\n");
        printf("[4] Print Below\n");
        printf("[5] Exit\n");
        printf("Enter choice here: ");
        scanf("%d", &choice);

        switch (choice) // switch to handle all cases
        {
        case 1:
            // Count nodes function
            printf("Number of items: %d\n", count_nodes(r));
            break;
        case 2:
            // Sum Keys function
            printf("Total sum of all keys: %d\n", sum_keys(r));
            break;
        case 3:
            // Max Key function
            printf("The maximum value of all keys on the tree is: %d\n", max_key(r));
            break;
        case 4:
            //User input
            printf("Enter the threshold value: ");
            scanf("%d", &v);
            // Print Below function
            printf("Printing all values under %d value: \n", v);
            print_below(r, v);
            printf("\n");
            break;
        case 5:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice, must be a number between 1 and 5!\n");
            break;
        }
    } while (choice != 5);

    // Cleaning and liberating space
    MakeEmpty(r);
    free(arr);

    // End of the program
    return 0;
}
