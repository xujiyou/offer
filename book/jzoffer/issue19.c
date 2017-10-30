#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

/*面试题19:求二叉树的镜像，画图容易理解*/

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

//将二叉树变为镜像二叉树
void get_mirror(Node *root){
		if (root != NULL){
				Node *temp = root->right;
				root->right = root->left;
				root->left = temp;
				get_mirror(root->left);
				get_mirror(root->right);
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
		int arr[] = {10,8,6,9,12,11,15};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		preorder(root);
		printf("\n");
		get_mirror(root);
		preorder(root);
		printf("\n");
}

