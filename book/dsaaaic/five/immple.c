#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

struct ListNode//链表节点类型
{
    ElementType Element;//链表中的储存的值
    Position Next;//指向下一个链表节点
};

typedef Position ListHead;//定义表头

struct HashTb1//散列表类型
{
    int TableSize;//散列表的长度
    ListHead *TheList;//储存各个表头，表头数组
};

int Hash(ElementType key, int size) {
    return key % size;
}

HashTable InitializeTable( int TableSize )
{
    HashTable H;
    H = (HashTable)malloc(sizeof(struct HashTb1));
    H->TableSize = TableSize;
    H->TheList = (ListHead *)malloc(sizeof(ListHead) * H->TableSize);
    ListHead temp = (ListHead)malloc(H->TableSize * sizeof(struct ListNode));//妙，妙
    for (int i = 0; i < H->TableSize; i++) {
       // H->TheList[i] = (ListHead)malloc(sizeof(struct ListNode));
        H->TheList[i] = temp++;
        H->TheList[i]->Next = NULL;
    }
    return H;
}

Position Find(ElementType key, HashTable H) {
    Position P;
    ListHead L;
    L = H->TheList[ Hash(key, H->TableSize) ];
    P = L->Next;
    while (P != NULL && P->Element != key) {
        P = P->Next;
    }
    return P;
}

void insert(ElementType key, HashTable H) {
   Position P = Find(key, H); 
   Position NewNode;
   ListHead L;
   if (P == NULL) {
        NewNode = (Position)malloc(sizeof(struct ListNode));
        L = H->TheList[ Hash(key, H->TableSize) ];
        NewNode->Next = L->Next;
        NewNode->Element = key;
        L->Next = NewNode;
   }
}

int main()
{
    HashTable H = InitializeTable(10);
    for (int i = 0; i < 10; i++) {
        insert(i*i, H);
    }
    Position P = Find(81, H);
    printf(" %d \n", P->Element);
    return 0;
}
