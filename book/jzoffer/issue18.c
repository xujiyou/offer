#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

/*面试题18:判断二茬树B是不是A的子结构, 递归判断*/

typedef struct TreeNode{
		int key;
		struct TreeNode *left;
		struct TreeNode *right;
} Node;

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

Node *search_node(Node *root, int key){
		if (root != NULL){
				if (root->key == key){
						return root;
				} else if (root->key < key) {
						return  search_node(root->right, key);
				} else {
						return search_node(root->left, key);
				}
		}
		return NULL;
}

int has_tree(Node *head, Node *root2){
		if (root2 == NULL) {
				return true;
		} 
		if (head == NULL) {
				return false;
		}
		if (head->key != root2->key){
				return false;
		}
		return has_tree(head->left, root2->left) && has_tree(head->right, root2->right);
}

//判断是不是为子结构
int is_son(Node *root1, Node *root2){
		Node *node = search_node(root1, root2->key);
		if (node == NULL){
				return false;
		} else {
				return has_tree(node, root2);
		}
}

//前序遍历
void preorder(Node *root){
		if (root){
				printf(" %d ",root->key);
				preorder(root->left);
				preorder(root->right);
		}
}

int main(){
		Node *root = NULL;
		int arr[] = {10,8,6,5,7,9,12,11,15};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		preorder(root);
		printf("\n");
		Node *root2 = NULL;
		int arr2[] = {8,6,9};
		int len2 = sizeof(arr2) / sizeof(arr2[0]);
		for (int i = 0; i < len2; i++) {
				insert_node(&root2, arr2[i]);
		}
		preorder(root2);
		printf("\n");
		int result = is_son(root, root2);
		if (result){
				printf("是子树\n");
		} else {
				printf("不是子树\n");
		}
}

