#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*面试题16:反转链表*/

typedef struct node_t{
		int key;
		struct node_t *next;
} Node;

Node *create_node(int key){
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->next = NULL;
		return node;
}

Node *insert_node(Node **root, int key){
		Node *node = create_node(key);
		if (*root == NULL) {
				*root = node;
				return node;
		}
		Node *curr = *root;
		Node *father = NULL;
		while (curr != NULL) {
				father = curr;
				curr = curr->next;
		}
		father->next = node;
		return node;
}

void print_link(Node *root){
		while (root != NULL) {
				printf(" %d ", root->key);
				root = root->next;
		}
}

//反转
Node *reversal(Node *root){
		Node *curr = root;
		Node *prev = NULL;
		Node *result = NULL;
		while (curr != NULL) {
				Node *pnext = curr->next;
				if (pnext != NULL){
						result = pnext;
				}
				curr->next = prev;
				prev = curr;
				curr = pnext;
		}
		return result;
}

//递归反转
Node *reversal_digui(Node *curr, Node *prev){
		Node *pnext = curr->next;
		curr->next = prev;
		if (pnext == NULL) {
				return curr;
		}
		prev = curr;
		curr = pnext;
		return reversal_digui(curr, prev);
}

int main(){
		Node *root = NULL;
		int arr[] = {1,2,3,4,5,6,7,8,9};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		print_link(root);
		printf("\n");
		Node *newRoot = reversal_digui(root, NULL);
		print_link(newRoot);
		printf("\n");
}
