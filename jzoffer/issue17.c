#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*面试题17:按照顺序合并已排序的链表*/

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

Node *merge(Node *root1, Node *root2) {
		if (root1 == NULL) {
				return NULL;
		}
		if (root2 == NULL) {
				return NULL;
		}
		Node *head = NULL;
		if (root1->key < root2->key) {
				head = root1;
				head->next = merge(root1->next, root2);
		} else {
				head = root2;
				head->next = merge(root1, root2->next);
		}
		return head;
}

int main(){
		Node *root = NULL;
		int arr[] = {1,3,5,7};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		print_link(root);
		printf("\n");
		Node *root2 = NULL;
		int arr2[] = {2,4,6,8};
		int len2 = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len2; i++) {
				insert_node(&root2, arr2[i]);
		}
		print_link(root2);
		printf("\n");
		Node *root3 = merge(root, root2);
		print_link(root3);
		printf("\n");

}
