#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*面试题15:求链表中的倒数第n个节点，考虑健壮性，过滤不合理的输入，考虑n为负数*/

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

Node *search_fall(Node *root, int n){
		if (root == NULL || n == 0) {
				return NULL;
		}
		if (n > 0){
				int curr_node = 1;
				Node *fall = root;
				Node *father = NULL;
				while (root != NULL) {
						root = root->next;
						if (curr_node > n - 1){
								father = fall;
								fall = fall->next;
						}
						curr_node++;
				}
				if (father == NULL) {
						return NULL;
				}
				return father;
		} else {
				n = ~n + 1;
				int curr_node = 1;
				while (root != NULL && curr_node < n) {
						root = root->next;
						curr_node++;
				}
				if (curr_node != n){
						return NULL;
				}
				return root;
		}
		return NULL;
}

/*面试题15扩展一:求链表的中间节点*/

Node *get_mid(Node *root){
		Node *fall = root;
		Node *father = NULL;
		while (root != NULL) {
				root = root->next;
				if (root == NULL){
						break;
				}
				root = root->next;
				father = fall;
				fall = fall->next;
		}
		if (father == NULL) {
				return NULL;
		}
		return father;
}

/*面试题15扩展2:判断链表是不是环形结构*/

int is_round(Node *root){
		Node *fall = root;
		Node *father = NULL;
		while (root != NULL && root != father) {
				root = root->next;
				if (root == NULL){
						break;
				}
				root = root->next;
				father = fall;
				fall = fall->next;
		}
		if (root == NULL){
				return 0;
		}
		return 1;

}

void print_link(Node *root){
		while (root != NULL) {
				printf(" %d ", root->key);
				root = root->next;
		}
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

		//寻找倒数第n个节点
		int n = 4;
		Node *node = search_fall(root, n);
		if (node != NULL){
				printf(" 倒数第%d个节点的值 : %d\n",n, node->key);
		} else {
				printf(" 倒数第%d个节点的值 : 不存在\n",n);
		}

		//找出链表的中间节点
		Node *mid = get_mid(root);
		if (mid != NULL){
				printf(" 中间节点的值 : %d\n", mid->key);
		} else {
				printf(" 中间节点的值：不存在\n");
		}

		//构造环形链表，并判断
		Node *last = insert_node(&root, 10);
		last->next = root;
		int result = is_round(root);
		if (result == 0){
				printf(" %s \n","不是环形链表");
		} else {
				printf(" %s \n","是环形链表");
		}
}
