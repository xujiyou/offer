#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define false 0
#define true 1
#define size 20

typedef struct tree_node{
    int key;
    struct tree_node *left;
    struct tree_node *right;
}TreeNode;

TreeNode *create_node(int key){
		TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		return node;
}

void insert_node(TreeNode **root, int key){
		TreeNode *node = create_node(key);
		TreeNode *father = NULL;
		TreeNode *curr = *root;
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

//栈及其方法
typedef struct Stack_t{
		int top;
		TreeNode *arr[size];
} Stack;

int is_empty(Stack *stack){
		if (stack->top == 0) {
				return true;
		}
		return false;
}

int is_full(Stack *stack){
		if (stack->top == size){
				return true;
		}
		return false;
}

TreeNode *push(Stack *stack, TreeNode *node){
		if (!is_full(stack)) {
				stack->arr[stack->top] = node;
				stack->top++;
				return node;
		}
		return NULL;
}

TreeNode *pop(Stack *stack){
		if (!is_empty(stack)) {
				stack->top--;
				return stack->arr[stack->top];
		}
		return NULL;
}

//中序遍历
void midorder(TreeNode *treeNode){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    TreeNode *curr = treeNode;
    while (curr != NULL || !is_empty(stack)) {
        while (curr != NULL) {
            push(stack, curr);
            curr = curr->left;
        }
        curr = pop(stack);
        printf(" %d ", curr->key);
        curr = curr->right;
    }
}

//将二叉树转换为双向链表，不另创建结构
void covent(TreeNode *treeNode, TreeNode **linkNode) {
    if (treeNode == NULL) {
        return;
    }
    TreeNode *currNode = treeNode;
    if (currNode->left != NULL) {
        covent(currNode->left, linkNode);
    }
    currNode->left = *linkNode;
    if (*linkNode != NULL) {
        (*linkNode)->right = currNode;
    }
    *linkNode = currNode;
    if (currNode->right != NULL) {
        covent(currNode->right, linkNode);
    }
}

//打印生成的双向链表
void print_link(TreeNode *linkNode){
    while (linkNode != NULL) {
        printf(" %d ", linkNode->key);
        linkNode = linkNode->left;
    }
}

int main(){
    TreeNode *root = NULL;
    int arr[] = {10,6,8,4,14,12,16};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        insert_node(&root, arr[i]);
    }
    midorder(root);
    printf("\n");
    TreeNode *linkNode = NULL;
    covent(root,&linkNode);
    print_link(linkNode);
    printf("\n");
}
