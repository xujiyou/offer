#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
 *二叉搜索树，根据其前序与中序遍历结果重建二叉搜索树，未完成
 * */

struct node_t{
		int key;
		struct node_t *left;
		struct node_t *right;
		struct node_t *top;
};

struct tree_t{
		int num;
		struct node_t *head;
};

//创建一个只有键值的节点
struct node_t *create_node(int key){
		struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->top = NULL;
		return node;
}

//将节点插入到二叉搜索树，下用循环找出需要插入的位置，
//然后判断插入到右边还是左边
void insert_into(struct tree_t *tree, int key){
		struct node_t *node = create_node(key);
		if (tree->head == NULL){
				tree->head = node;
				return ;
		}
		struct node_t *curr_node = tree->head;
		struct node_t *father_node;
		while (curr_node != NULL){
				father_node = curr_node;
				if (curr_node->key > key){
						curr_node = curr_node->left;
				} else {
						curr_node = curr_node->right;
				}
		}
		node->top = father_node;
		if (father_node->key > key){
				father_node->left = node;
		} else {
				father_node->right = node;
		}
		tree->num++;
}

//递归遍历打印
void recursion(struct node_t *node){
		if (node){
				printf(" %d ", node->key);
				recursion(node->right);
				recursion(node->left);
		}
}

/*栈，用于前序，中序，后续遍历*/

#define size 30

struct stack_t{
		int top;
		struct node_t *nodes[size];
};

int stack_empty(struct stack_t *stack){
		if (stack->top == 0){
				return 1;
		}
		return 0;
}

int stack_full(struct stack_t * stack){
		if (stack->top == size + 1) {
				return 1;
		}
		return 0;
}

struct node_t *push(struct stack_t *stack, struct node_t *node){
		if (!stack_full(stack)){
				stack->nodes[stack->top] = node;
				stack->top++;
				return node;
		}
		return NULL;
}

struct node_t *pop(struct stack_t *stack){
		if (!stack_empty(stack)){
				stack->top--;
				return stack->nodes[stack->top];
		}
		return NULL;
}
/**/

//前序遍历
void ergodic_front(struct tree_t *tree,int *arr){
		int i = 0;
		struct stack_t *stack = (struct stack_t *)malloc(sizeof(struct stack_t));
		stack->top = 0;
		struct node_t *node = tree->head;
		while(node || !stack_empty(stack)){
				while(node){
						push(stack,node);
						arr[i++] = node->key;\
						node = node->left;
				}
				node = pop(stack);
				node = node->right;
		}
}

//中序遍历
void ergodic_center(struct tree_t *tree, int *arr){
		int i = 0;
		struct stack_t *stack = (struct stack_t *)malloc(sizeof(struct stack_t));
		stack->top = 0;
		struct node_t *node = tree->head;
		while(node || !stack_empty(stack)){
				while(node){
						push(stack,node);
						node = node->left;
				}
				node = pop(stack);
				arr[i++] = node->key;
				node = node->right;
		}
}

//添加左节点
void insert_left(struct node_t *parent_node, struct node_t *son_node){
		son_node->top = parent_node;
		parent_node->left = son_node;
}

//添加左节点
void insert_right(struct node_t *parent_node, struct node_t *son_node){
		son_node->top = parent_node;
		parent_node->right = son_node;
}

#define left 1
#define right 2

void rebuild(struct tree_t *newtree,struct node_t *parent_node, int *arr_center,int center_index, int *arr_front,int i,int j, int weizhi){
		int head = arr_front[center_index];
		struct node_t *node = create_node(head);
		if (newtree->head == NULL){
				newtree->head = node;
		} else {
				if (weizhi == left){
						insert_left(parent_node, node);
				} else {
						insert_right(parent_node, node);
				}
		}
		int k = i;
		while (head != arr_center[k]) {
				k++;
		}
		center_index++;
		rebuild(newtree, node, arr_center, center_index, arr_front, i, k-1, left);
		rebuild(newtree, node, arr_center, center_index, arr_front, k+1, j, right);
		return ;
}

int main(){
		struct tree_t *tree = (struct tree_t *)malloc(sizeof(struct tree_t));
		insert_into(tree, 10);
		insert_into(tree, 5);
		insert_into(tree, 7);
		insert_into(tree, 4);
		insert_into(tree, 11);
		insert_into(tree, 12);
		int arr_center[size];
		ergodic_center(tree,arr_center);
		for(int i = 0; i < tree->num; i++){
				printf(" %d ",arr_center[i]);
		}
		printf("\n");
		int arr_front[size];
		ergodic_front(tree,arr_front);
		for(int i = 0; i < tree->num; i++){
				printf(" %d ",arr_front[i]);
		}
		printf("\n");
		struct tree_t *newtree = (struct tree_t *)malloc(sizeof(struct tree_t));
		rebuild(newtree, NULL, arr_center, 0, arr_front, 0,tree->num-1, 0);
}
