#include <stdio.h>
#include <malloc.h>

#define MAX 20

struct node {
		struct node *top;
		struct node *left;
		struct node *right;
		int item;
};

struct tree{
		struct node *head;
		int n;
};

/*栈，用于前序，中序，后续遍历*/
struct stack{
		int top;
		int sign[MAX];
		struct node *sum[MAX];
};

int is_empty(struct stack *arr){
		if (arr->top == 0){
				return 1;
		}
			return 0;
}

struct node *push(struct stack *arr,struct node *var){
		if (arr->top < MAX){
				arr->sum[arr->top] = var;
				arr->top += 1;
		} else {
				return 0;
		}
		return var;
}

struct node * pop(struct stack *arr){
		struct node *var = 0;
		if (!is_empty(arr)){
				arr->top -= 1;
				var =  arr->sum[arr->top];
		} else {
				return 0;
		}
		return var;
}
/*以上为栈及其方法*/

/*队列，用于层次遍历*/
struct queue{
		int head;
		int tail;
		struct node *num[MAX];
};

int jj = 0;

int queue_is_empty(struct queue *qu){
		if (qu->head == qu->tail){
				return 1;
		} else {
				return 0;
		}
}

int is_full(struct queue *qu){
		if (qu->tail == MAX && qu->head == 0){
				return 1;
		} else if (qu->head - qu->tail == 1){
				jj = 1;
			return 0;
		} else if (jj == 1){
				return 1;
		}  else {
				return 0;
		}
}

struct node *enqueue(struct queue *qu, struct node *var){
		if ( !is_full(qu) ){
				if ( qu->tail == MAX ){
						qu->tail = 0;
				}
				qu->num[qu->tail] = var;
				if (qu->tail < MAX){
					qu->tail++;
				}
				return var;
		}
		return 0;
}

struct node *dequeue(struct queue *qu){
		if (!queue_is_empty(qu) || jj == 1){
				struct node *var = qu->num[qu->head];
				if (qu->head < MAX) {
						qu->head++;
				} else {
						qu->head = 0;
				}
				jj = 0;
				return var;
		}
		return 0;
}
/*以上为队列及其方法*/

//创建一个二叉树节点
struct node *create_node(int item){
		struct node *treenode = (struct node *)malloc(sizeof(struct node));
		treenode->item = item;
		treenode->left = 0;
		treenode->right = 0;
		treenode->top = 0;
		return treenode;
}

//初始化一个二叉树
struct tree *init_tree(){
		struct tree *twotree = (struct tree *)malloc(sizeof(struct tree));
		struct node *treenode = create_node(8);
		twotree->head = treenode;
		twotree->n = 1;
		return twotree;
}

//加一个左节点
struct node *add_left(struct tree *twotree, struct node *fn, struct node *zn){
		if (fn->left == 0){
				fn->left = zn;
				zn->top = fn;
				twotree->n++;
				return zn;
		}
		return 0;
}

//加一个右节点
struct node *add_right(struct tree *twotree, struct node *fn, struct node *zn){
		if (fn->right == 0){
				fn->right = zn;
				zn->top = fn;
				twotree->n++;
				return zn;
		}
		return 0;
}

//因为二叉树是有顺序的，所以在添加时可以根据位置添加
//顺序为左节点 < 根节点 < 右节点
struct node *add(struct tree *twotree, struct node *zn){
		struct node *fn;
		struct node *next = twotree->head;
		while(next != 0){
				fn = next;
				if (zn->item < next->item){
						next = next->left;
				} else {
						next = next->right;
				}
		}
		zn->top = fn;
		if (fn->item > zn->item){
				fn->left = zn;
		} else {
				fn->right = zn;
		}
		return zn;
}

//根据item查找节点
struct node *search(struct tree *twotree, int key){
		struct node *fn = twotree->head;
		while (fn && key != fn->item){
				if (key < fn->item){
						fn = fn->left;
				} else {
						fn = fn->right;
				}
		}
		if (fn){
				return fn;
		}
		return 0;
}

//删除节点
struct node *delete(struct tree *twotree, struct node *zn){
		if (zn == 0) {
				return 0;
		}
		if(zn->left == 0 && zn->right == 0){
				if (zn->top == 0){
						twotree->head = 0;
				} else {
						if (zn->item < zn->top->item){
								zn->top->left = 0;
						} else {
								zn->top->right = 0;
						}
				}
		} else {
				if (zn->left == 0){
						if (zn->item < zn->top->item){
								zn->top->left = zn->right;
						} else {
								zn->top->right = zn->right;
						}
				} else if (zn->right == 0){
						if (zn->item < zn->top->item){
								zn->top->left = zn->left;
						} else {
								zn->top->right = zn->left;
						}
				} else {	
						if (zn->item < zn->top->item){
								zn->top->left = zn->right;
								add(twotree,zn->left);
						} else {
								zn->top->right = zn->right;
								add(twotree,zn->left);
						}
				}
		}
		return zn;
}

//前序遍历，中序遍历，区别在于printf的位置不同，相同点是printf的位置都在栈操作后
void vactor(struct tree *L){
		struct node *tn = L->head;
		struct stack *arr = (struct stack *)malloc(sizeof(struct stack));
		arr->top = 0;
		while (tn || arr->top != 0) {
				while (tn) {
					push(arr, tn);
					//printf("%d  ",tn->item); //printf在这个地方为中序遍历
					tn = tn->left;
				}
				tn = pop(arr);
				printf("%d  ",tn->item);	//printf在这个地方为前序遍历
				tn = tn->right;
		}		
}

//后续遍历，
void hou_vactor(struct tree *L){
		struct node *tn = L->head;
		struct stack *arr = (struct stack *)malloc(sizeof(struct stack));
		arr->top = 0;
		while (tn || arr->top != 0) {
				while (tn) {
					push(arr, tn);
					arr->sign[arr->top-1] = 0;
					tn = tn->left;
				}
				if (arr->sign[arr->top-1] == 0){
						tn = arr->sum[arr->top-1];
						arr->sign[arr->top-1] = 1;
						tn = tn->right;
				} else {
					while (arr->sign[arr->top-1] == 1){
							tn = pop(arr);
							printf("%d  ",tn->item);
					}
					tn = 0;
				}
		}			
}

//递归遍历
void digui(struct node *tn) {
		if(tn){
				printf("%d  ",tn->item);
				digui(tn->left);
				digui(tn->right);
		}
}

//层次遍历，用到了队列
void cc_vactor(struct tree *L){
		struct node *tn = L->head;
		struct queue * qu = (struct queue*)malloc(sizeof(struct queue));
		qu->head = 0;
		qu->tail = 0;
		enqueue(qu,tn);
		while(!is_full(qu)){
				tn = dequeue(qu);
				if(tn){
					printf("%d  ",tn->item);
					if (tn->left) {
						enqueue(qu, tn->left);
					}
					if (tn->right) {
						enqueue(qu, tn->right);
					}
				} else {
						break;
				}
		}
}

//计算节点数量
int count(struct node *tn) {
		if (tn){
				return (count(tn->left) + count(tn->right) + 1);
		}
		return 0;
}

int main(){
		struct tree *L = init_tree();
		struct node *node10 = create_node(10);
		struct node *node11 = create_node(4);
		struct node *node12 = create_node(5);
		struct node *node13 = create_node(6);
		struct node *node14 = create_node(1);
		struct node *node15 = create_node(15);
		struct node *node16 = create_node(13);
		struct node *node17 = create_node(3);
		add(L,node10);
		add(L,node11);
		add(L,node12);
		add(L,node13);
		add(L,node14);
		add(L,node15);
		add(L,node16);
		add(L,node17);
		delete(L, search(L,4));
		hou_vactor(L);
		printf("----后续遍历\n");
		digui(L->head);
		printf("----递归遍历\n");
		cc_vactor(L);
		printf("----层次遍历\n");
		printf("%d  ----数量\n",count(L->head));

}
