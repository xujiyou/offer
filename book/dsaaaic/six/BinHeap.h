struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

typedef int ElementType;

PriorityQueue Initialize( int MaxElements );
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
