#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TreeNode{
    ElementType Element;
    struct TreeNode *Left;
    struct TreeNode *Right;
    int Npl;
};

typedef struct TreeNode *PriorityQueue;

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

void SwapChildren(PriorityQueue H)
{
    PriorityQueue temp = H->Left;
    H->Left = H->Right;
    H->Right = temp;
}

PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL) {
        H1->Left = H2;
    } else {
        H1->Right = Merge(H1->Right, H2);
        if ( H1->Left->Npl < H1->Right->Npl ) {
            SwapChildren( H1 );
        }
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if ( H1 == NULL ){
        return H2;
    } else if ( H2 == NULL ) {
        return H1;
    }
    if ( H1->Element < H2->Element ) {
        return Merge1( H1, H2 );
    } else {
        return Merge1( H2, H1 );
    }
}

PriorityQueue Insert( ElementType X, PriorityQueue H )
{
    PriorityQueue SingleNode;
    SingleNode = (PriorityQueue)malloc( sizeof( struct TreeNode ) );
    SingleNode->Element = X;
    SingleNode->Npl = 0;
    SingleNode->Left = SingleNode->Right = NULL;
    H = Merge(SingleNode, H);
    return H;
}

void print(PriorityQueue H){
    if (H != NULL) {
        printf( " %d ", H->Element );
        print(H->Left);
        print(H->Right);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);
    PriorityQueue H = NULL;
    for (int i = 0; i < len; i++ ) {
        H = Insert(arr[i], H);
    }
    print( H );
    printf(" \n");
}
