#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define HEIGHT(p) ( (p==NULL) ? 0 : (((Node *)p)->height) )
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )

typedef int TYPE;

int errno = 0;

//AVL树节点的结构，及指向树节点的指针
typedef struct AVLTreeNode{
		TYPE key;
		int height;
		struct AVLTreeNode *left;
		struct AVLTreeNode *right;
} Node, *AVLTree;

//创建一个节点
Node *avltree_create_node(TYPE key, Node *left, Node *right){
		Node *node = (Node *)malloc(sizeof(Node));
		node->key = key;
		node->height = 0;
		node->left = left;
		node->right = right;
		return node;
}

//获取树的高度
int avltree_height(AVLTree tree){
		return HEIGHT(tree);
}
/*旋转的返回值皆为旋转后的根节点*/

//LL旋转，LL旋转是围绕“失去平衡的AVL的根节点”进行的，由于树左左，所以是根节点与左节点旋转
Node *left_left_rotation(AVLTree root){
		AVLTree leftNode = root->left;
		root->left = leftNode->right;
		leftNode->right = root;

		root->height = MAX( HEIGHT(root->left), HEIGHT(root->right) ) + 1;
		leftNode->height = MAX( HEIGHT(leftNode->left), root->height ) + 1;
		return leftNode;
}

//RR旋转，与LL旋转差不多，不过是根节点与右节点的旋转
Node *right_right_rotation(AVLTree root){
		AVLTree rightNode = root->right;
		root->right = rightNode->left;
		rightNode->left = root;

		root->height = MAX( HEIGHT(root->left), HEIGHT(root->right) ) + 1;
		rightNode->height = MAX( HEIGHT(rightNode->right), root->height ) + 1;
		return rightNode;
}

//LR旋转,先对根节点的左节点进行一次RR旋转，再对根节点进行一次LL旋转
Node *left_right_rotation(AVLTree root){
		root->left = right_right_rotation(root->left);
		return left_left_rotation(root);
}

//RL旋转，先对根节点的右节点进行一次LL旋转，再对根节点进行一次RR旋转
Node *right_left_totation(AVLTree root){
		root->right = left_left_rotation(root->right);
		return right_right_rotation(root);
}

/*
 *插入AVL树
 *参数：root，AVL树的根节点，key，要插入的键值
 *返回值:新树的根节点
 * */
Node *avltree_insert(AVLTree root, TYPE key){
		if (root == NULL){
				root = avltree_create_node(key, NULL, NULL);
		} else if (key < root->key) {
				root->left = avltree_insert(root->left, key);
				int cha = HEIGHT(root->left) - HEIGHT(root->right);
				if ( cha == 2 || cha == -2) {
						if (key < root->left->key){
								root = left_left_rotation(root);
						} else {
								root = left_right_rotation(root);
						}
				}
		} else if (key > root->key) {
				root->right = avltree_insert(root->right, key);
				int cha = HEIGHT(root->left) - HEIGHT(root->right);
				if ( cha == 2 || cha == -2) {
						if (key > root->right->key) {
								root = right_right_rotation(root);
						} else {
								root = right_left_totation(root);
						}
				}
		} else { //key值已存在，不能再添加
				errno = -1;	
		}
		root->height = MAX( HEIGHT(root->left), HEIGHT(root->right) ) + 1;
		return root;
}

//获取子树中最大的节点,root为子树的根节点
Node *max_node(AVLTree root){
		if (root == NULL){
				return NULL;
		}
		while (root->right != NULL){
				root = root->right;
		}
		return root;
}

//获取子树中最小的节点,root为子树的根节点
Node *min_node(AVLTree root){
		if (root == NULL){
				return NULL;
		}
		while (root->left != NULL){
				root = root->left;
		}
		return root;
}

//递归前序遍历AVL树
void preorder_avltree(AVLTree root){
		if (root != NULL) {
				printf(" %d ", root->key);
				preorder_avltree(root->left);
				preorder_avltree(root->right);
		}
}

//递归中序遍历AVL树
void midorder_avltree(AVLTree root) {
		if (root != NULL) {
				midorder_avltree(root->left);
				printf(" %d ", root->key);
				midorder_avltree(root->right);
		}
}

//递归后续遍历AVL树
void aftorder_avltree(AVLTree root){
		if (root != NULL){
				aftorder_avltree(root->left);
				aftorder_avltree(root->right);
				printf(" %d ",root->key);
		}
}

//递归实现从AVL树中查找一个元素
Node *avltree_search(AVLTree node, TYPE key){
		if (node == NULL || node->key == key){
				return node;
		}
		if (key < node->key){
				return avltree_search(node->left, key);
		} else {
				return avltree_search(node->right, key);
		}
}

//非递归实现，查找元素
Node *iterative_avltree_search(AVLTree node, TYPE key){
		while (node == NULL && node->key == key){
				if (key < node->key){
						node = node->left;
				} else {
						node = node->right;
				}
		}
		return node;
}

//删除avl树中的节点
//root为avl树的根节点，node为要删除的节点，返回新avl树的根节点
Node *delete_node(AVLTree root, Node *node){
		if (root == NULL || node == NULL){
				return NULL;
		}
		if (node->key < root->key) { //需要删除左子树的节点
				root->left = delete_node(root->left, node);
				if (HEIGHT(root->right) - HEIGHT(root->left) == 2) { //因为删除了左子树的节点，所以右子树可能的高度高于左子树的高度
						Node *rightNode = root->right;
						if ( HEIGHT(rightNode->left) > HEIGHT(rightNode->right) ) { //判断右子树中哪个方向的高度的大
								root = right_left_totation(root);
						} else {
								root = right_right_rotation(root);
						}
				}
		} else if (node->key > root->key){ //需要删除右子树的节点
				root->right = delete_node(root->right, node);
				if ( HEIGHT(root->left) - HEIGHT(root->right) == 2 ){
						Node *leftNode = root->left;
						if ( HEIGHT(leftNode->left) < HEIGHT(leftNode->right) ) {
								root = left_right_rotation(root);
						} else {
								root = left_left_rotation(root);
						}
				}

		} else { //root是需要删除的节点
				if (root->left != NULL && root->right != NULL) {
						//思想是：先找到替代要删除的节点，然后将当前节点的值更换为替换节点的值，然后将替代节点删除
						if ( HEIGHT(root->left) > HEIGHT(root->right) ) { //如果左子树高度大，则从左子树中找最大的值替代当前节点，
								Node *max = max_node(root->left);
								root->key = max->key;
								delete_node(root->left, max);
						} else {										//如果右子树高度大，则从右子树找到最小的节点替代当前节点
								Node *min = min_node(root->right);
								root->key = min->key;
								delete_node(root->right, min);
						}
				} else {
						root = root->left==NULL ? root->right : root->left;
				}
		}
		return root;
}

Node *delete_key(AVLTree root, TYPE key){
		Node *node;
		if ( (node = avltree_search(root,key)) != NULL ) {
				root = delete_node(root, node);
		}
		return root;
}

int main(){
		int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
		AVLTree root = NULL;
		int len = sizeof(arr) / sizeof(arr[0]);
		printf("原数组  ：");
		for (int i = 0; i < len; i++){
				printf(" %d ", arr[i]);
				root = avltree_insert(root, arr[i]);
		}
		printf("\n");
		printf("前序遍历：");
		preorder_avltree(root);	
		printf("\n");
		printf("中序遍历：");
		midorder_avltree(root);	
		printf("\n");
		printf("后序遍历：");
		aftorder_avltree(root);	
		printf("\n");
		printf("查找元素7，查看元素7的高度：");
		Node *node = iterative_avltree_search(root, 7);
		printf(" %d \n", node->height);
		TYPE i = 7;
		printf("删除根节点:%d\n", i);
		delete_key(root, i);
		printf("前序遍历：");
		preorder_avltree(root);	
		printf("\n");

}



