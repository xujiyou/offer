#include <stdio.h>
#include <malloc.h>

/*面试题13：删除链表中的节点，使用替代删除法，注意传递地址的问题*/

typedef struct node_t{
		int key;
		struct node_t *next;
} Node;

Node *create_node(int key) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->next = NULL;
		return node;
}

void insert_node(Node **root, int key){
		Node *curr = *root;
		Node *node = create_node(key);
		Node *father = NULL;
		while (curr != NULL) {
				father = curr;
				curr = curr->next;
		}
		if (father == NULL) {
				*root = node;
		} else {
				father->next = node;
		}
}

Node *select_node(Node *root, int key){
		while (root != NULL) {
				if (root->key == key){
						return root;
				}
				root = root->next;
		}
		return NULL;
}

void delete_1(Node **root, Node *node){
		if (node == NULL || root == NULL){
				return;
		}
		if (node->next != NULL){
				Node *next_node = node->next;
				node->key = next_node->key;
				node->next = next_node->next;
				free(next_node);
				next_node = NULL;
		} else if (*root == node){
				free(node);
				node = NULL;
				*root = NULL;
		} else {
				Node *pnode = *root;
				while (pnode != node) {
						pnode = pnode->next;
				}
				pnode->next = NULL;
				free(node);
				node = NULL;
		}
}

void print_link(Node *root){
		while (root != NULL) {
				printf(" %d ", root->key);
				root = root->next;
		}
}

int  main(){
		Node *root = NULL;
		int arr[] = {1};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		print_link(root);
		printf(" \n");
		Node *node = select_node(root,1 );
		printf(" %d \n", node->key);
		delete_1(&root, node);
		print_link(root);
		printf("\n");
}
