#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define size 20

/*面试题23:层级遍历二叉树，使用到了队列*/

typedef struct TreeNode{
		int key;
		struct TreeNode *left;
		struct TreeNode *right;
} Node;

//队列及其方法
typedef struct queue_t{
		int head;
		int tail;
		Node *arr[size];
} Queue;

int is_empty(Queue *queue){
		if (queue->head == queue->tail){
				return true;
		}
		return false;
}

int is_full(Queue *queue){
		if (queue->head == 0 && queue->tail == size) {
				return true;
		}
		return false;
}

Node *enqueue(Queue *queue, Node *key){
		if (!is_full(queue)) {
			queue->arr[queue->tail] = key;
			if (queue->tail == size){
					queue->tail = 0;
			} else {
					queue->tail++;
			}
			return key;
		}
		return NULL;
}

Node *dequeue(Queue *queue){
		if (!is_empty(queue)) {
				Node *result = queue->arr[queue->head];
				if (queue->head == size){
						queue->head = 0;
				} else {
						queue->head++;
				}
				return result;
		}
		return NULL;
}
/**/

Node *create_node(int key){
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		return node;
}

void insert_node(Node **root, int key){
		Node *node = create_node(key);
		Node *father = NULL;
		Node *curr = *root;
		while (curr != NULL) {
				father = curr;
				if (key < curr->key){
						curr = curr->left;
				} else {
						curr = curr->right;
				}
		}
		if (father == NULL) {
				*root = node;
				return;
		}
		if (key < father->key) {
				father->left = node;
		} else {
				father->right = node;
		}
}

void cc_ergodic(Node *root){
		Node *node = root;
		Queue *queue = (Queue *)malloc(sizeof(Queue));
		queue->head = queue->tail = 0;
		enqueue(queue, node);
		while (!is_full(queue)) {
				node = dequeue(queue);
				if (node == NULL) {
						break;
				} else {
						printf(" %d ", node->key);
						if (node->left) {
								enqueue(queue, node->left);
						}
						if (node->right) {
								enqueue(queue, node->right);
						}
				}
		}
}

int main(){
		Node *root = NULL;
		int arr[] = {5,4,1,2,3,8,6,7,9};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		cc_ergodic(root);
		printf("\n");
}

