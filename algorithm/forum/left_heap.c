#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LeftHeapNode{
		int key;
		int npl;
		struct LeftHeapNode *left;
		struct LeftHeapNode *right;
} Node;

Node *create_node(int key){
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->npl = 0;
		node->left = node->right = NULL;
		return node;
}

Node *merge_leftheap(Node *heap, Node *node){
		if (heap ==NULL) {
				return node;
		} else if (node == NULL) {
				return heap;
		}

}

//插入到左倾堆，参数为左倾堆根节点与要插入的键值，输出新左倾堆的节点
Node *insert_heap_node(Node *heap, int key){
		Node *node = create_node(key);
		return merge_leftheap(heap, node);	
}
