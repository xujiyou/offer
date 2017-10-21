#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define false 0
#define true 1
#define size 20

/*面试题25:二茬树中和为某一值的路径*/

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

//栈及其方法
typedef struct Stack_t{
		int top;
		Node *arr[size];
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

Node *push(Stack *stack, Node *node){
		if (!is_full(stack)) {
				stack->arr[stack->top] = node;
				stack->top++;
				return node;
		}
		return NULL;
}

Node *pop(Stack *stack){
		if (!is_empty(stack)) {
				stack->top--;
				return stack->arr[stack->top];
		}
		return NULL;
}

int add_stack(Stack *stack){
		int result = 0;
		for (int i = stack->top - 1; i >= 0; i--) {
				result += stack->arr[i]->key;
		}
		return result;
}

void print_stack(Stack *stack){
		for (int i = 0; i < stack->top; i++) {
				printf(" %d ", stack->arr[i]->key);
		}
		printf("\n");
}

//二叉树的前序遍历
void preorder(Node *root, int he){
		Stack *result_stack = (Stack *)malloc(sizeof(Stack));
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		stack->top = result_stack->top = 0;
		Node *node = root;
		Node *temp = NULL;
		while (node != NULL || !is_empty(stack)){
				while (node != NULL){
						push(stack, node);
						push(result_stack, node);
						if (he == add_stack(result_stack)) {
								print_stack(result_stack);
								pop(result_stack);
						}
						node = node->left;
				}
				node = pop(stack);
				temp = pop(result_stack);
				node = node->right;
				if (node != NULL){
						push(result_stack, temp);
				}
		}
}

int main(){
		Node *root = NULL;
		int arr[] = {5,2,1,4,6};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				insert_node(&root, arr[i]);
		}
		preorder(root, 11);
}

