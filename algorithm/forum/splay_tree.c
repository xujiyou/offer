#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*伸展树，即将最新插入的值放到根节点，节省查找最新节点的时间*/

typedef int TYPE;

typedef struct SplayTreeNode {
		TYPE key;
		struct SplayTreeNode *left;
		struct SplayTreeNode *right;
} Node, *SplayTree;

Node *splaytree_splay(SplayTree root, TYPE key){
		if (root == NULL) {
				return root;
		}
		Node node, *right, *left;
		node.left = node.right = NULL;
		left = right = &node;
		for (;;){
				if (key < root->key) {
						if (root->left == NULL) {
								break;
						}
						if (key < root->left->key) {
								Node *next_root = root->left;	//右旋转
								root->left = next_root->right;
								next_root->right = root;
								root = next_root;
								if (root->left == NULL){
										break;
								}
						}
						right->left = root;						//右链接
						right = root;
						root = root->left;
				} else if (key > root->key) {
						if (root->right == NULL) {
								break;
						}
						if (key > root->right->key) {
								Node *next_root = root->right;	//左旋转
								root->right = next_root->left;
								next_root->left = root;
								root = next_root;
								if (root->right == NULL) {
										break;
								}
						}
						left->right = root;						//左链接
						left = root;
						root = root->right;
				} else {
						break;
				}
		}
		left->right = root->left;								//组合
		right->left = root->right;
		root->left = node.right;
		root->right = node.left;

		return root;
}

//创建伸展树节点
Node *create_splaytree_node(TYPE key, Node *left, Node *right) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->left = left;
		node->right = right;
		return node;
}

Node *insert_node(SplayTree root, Node *node){
		Node *curr_node = root;
		Node *father = NULL;
		while ( curr_node != NULL ) {
				father = curr_node;
				if (node->key < curr_node->key) {
						curr_node = curr_node->left;
				} else if (node->key > curr_node->key) {
						curr_node = curr_node->right;
				} else {
						printf("不允许插入相同的节点值\n");
						return root;
				}
		}
		if (father == NULL){
				root = node;
		} else if (node->key < father->key){
				father->left = node;
		} else {
				father->right = node;
		}
		return root;

}

Node *insert_splaytree(SplayTree root, TYPE key){
		Node *node = create_splaytree_node(key, NULL, NULL);
		root = insert_node(root, node);
		root = splaytree_splay(root, key);
		return root;
}

//递归前序遍历伸展树
void preorder_splaytree(SplayTree root){
		if (root != NULL) {
				printf(" %d ", root->key);
				preorder_splaytree(root->left);
				preorder_splaytree(root->right);
		}
}

int main(){
		int arr[]= {1,2,3,4,5,6,7,8,4};
		SplayTree root = NULL;
		int len = sizeof(arr) / sizeof(arr[0]);
		printf("原数组  ：");
		for (int i = 0; i < len; i++){
				printf(" %d ", arr[i]);
				root = insert_splaytree(root, arr[i]);
		}
		printf("\n");
		printf("前序遍历：");
		preorder_splaytree(root);	
		printf("\n");
}
