
struct ListNode;//声明每个散列表中的链表,链表节点
typedef struct ListNode *Position;//定义链表的指针,指向链表的节点
struct HashTb1;//声明散列表
typedef struct HashTb1 *HashTable;

typedef int ElementType;

HashTable InitializeTable( int TableSize );//初始散列表
void DestroyTable( HashTable H );//销毁散列表
Position Find( ElementType key, HashTable H );//查找散列表中的元素
void Insert(ElementType key, HashTable H);//往散列表中插入元素
