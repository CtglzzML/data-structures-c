typedef int ElementType;


#ifndef _BST_H
#define _BST_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve( Position P );

void PrintTree(SearchTree T);

Position findMin_K(SearchTree T, int k);
int numLeafNodes(SearchTree T);
ElementType * LevelOrder(SearchTree T);



#endif  /* _BST_H */

