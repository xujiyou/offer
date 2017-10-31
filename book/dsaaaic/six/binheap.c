#include "BinHeap.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct HeapStruct 
{
    int Capacity;//容量
    int Size;
    ElementType *Elements;
};

PriorityQueue Initialize( int MaxElements )
{
    PriorityQueue H;
    H = (PriorityQueue)malloc( sizeof(struct HeapStruct) );
    H->Elements = (ElementType *)malloc( (MaxElements + 1) * sizeof(ElementType) );
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[ 0 ] = 0;
    return H;
}

int IsFull(PriorityQueue H)
{
    if (H->Size >= H->Capacity){
        return true;
    }
    return false;
}

int IsEmpty(PriorityQueue H)
{
    if (H->Size == 0) {
        return true;
    }
    return false;
}

void Insert(ElementType X, PriorityQueue H)
{
    if ( IsFull(H) ) {
        return;
    }
    int i;
    for (i = ++H->Size; H->Elements[ i/2 ] > X; i /= 2) {
        H->Elements[ i ] = H->Elements[ i/2 ];
    }
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
    if ( IsEmpty(H) ) {
        return -1;
    }
    int MinElement = H->Elements[ 1 ];
    int LastElement = H->Elements[ H->Size-- ];
    int i, Child;
    for (i = 1; i * 2 < H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child] > H->Elements[Child + 1]) {
            Child++;
        }
        if (LastElement > H->Elements[Child]) {
            H->Elements[i] = H->Elements[Child];
        } else {
            break;
        }
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int main()
{
    PriorityQueue H = Initialize(16);
    int arr[] = {13,21,16,24,31,19,68,65,26,32};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        Insert(arr[i], H);
    }
    Insert(14, H);
    for (int i = 0; i <= H->Size; i++) {
        printf( " %d ", H->Elements[i] );
    }
    int min = DeleteMin(H);
    printf("\n min:%d \n", min);
    for (int i = 0; i <= H->Size; i++) {
        printf( " %d ", H->Elements[i] );
    }
    printf("\n");
}
