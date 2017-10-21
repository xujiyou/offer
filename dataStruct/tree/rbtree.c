#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define RED 1
#define BLANK 2

#define MAX 20

struct tree_node{
		int color;
		int key;
		struct tree_node *top;
		struct tree_node *left;
		struct tree_node *right;
};

struct rbtree{
		struct tree_node *head;
};

struct tree_node NIL = {
		 BLANK,0,0,0,0
};

/*队列，用于层次遍历*/
struct queue{
		int head;
		int tail;
		struct tree_node *num[MAX];
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

struct tree_node *enqueue(struct queue *qu, struct tree_node *var){
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

struct tree_node *dequeue(struct queue *qu){
		if (!queue_is_empty(qu) || jj == 1){
				struct tree_node *var = qu->num[qu->head];
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
//以上为队列的方法

struct tree_node *make_node(int key){
		struct tree_node *node = (struct tree_node *)malloc(sizeof(struct tree_node));
		node->color = RED;
		node->key = key;
		node->top = 0;
		node->left = &NIL;
		node->right = &NIL;
		return node;
}

//左旋，左旋转与右旋转都分三步，下->上->中
void left_rotate(struct rbtree *tree, struct tree_node *x){
		struct tree_node *y = x->right; //y为x的右节点
		x->right = y->left;
	    x->right->top = x;		//将y的左儿子付给x的右儿子

		y->top = x->top;		
		if (y->top == 0) {
				tree->head = y;
		} else {
				if (x->top->left == x){
						x->top->left = y;
				} else {
						x->top->right = y;
				}
		}						//将y换到x的位置

		y->left = x;
		x->top = y;
}

//右旋
void right_rotate(struct rbtree *tree, struct tree_node *y){
		struct tree_node *x = y->left;	//x为y的左儿子
		y->left = x->right;
		y->left->top = y;				//x的右儿子付给y的左儿子

		x->top = y->top;
		if (x->top == 0){
				tree->head = x;
		} else {
				if (y->top->left == y){
						y->top->left = x;
				} else {
						y->top->right = x;
				}
		}								//将y的顶点的儿子换位

		x->right = y;
		y->top = x;						//将x与y换位
}

//添加到二叉树后，红黑树会失去其特点，通过修改将其改成红黑树
void install_fixup(struct rbtree *tree, struct tree_node *z){
		while(z->color == RED && z->top != 0){
				if(z->top->top != 0){
					struct tree_node *fa = z->top;
					struct tree_node *gfa = fa->top;
					if (fa == gfa->left){				//大情况一：z的爸爸是左节点
							struct tree_node *shu = gfa->right;	//y为z的叔叔
							if (shu->color == RED) {					//一小情况1：叔叔的颜色为红色
								fa->color = BLANK;
								shu->color = BLANK;
								gfa->color = RED;
								z = gfa;
							} else if (z == fa->right){			//一小情况2：叔叔为黑色，z为右节点
								z = fa;
								left_rotate(tree, z);
							}		
							fa->color = BLANK;						//一小情况3：叔叔为黑色，z为左节点
							gfa->color = RED;
							right_rotate(tree, gfa);		
					} else {										//大情况二：z的爸爸为右节点			
							struct tree_node *shu = gfa->left;	//y为z的叔叔
							if (shu->color == RED) {					//二小情况1：叔叔的颜色为红色
								fa->color = BLANK;
								shu->color = BLANK;
								gfa->color = RED;
								z = gfa;
							} else if (z == fa->left){			//二小情况2：叔叔为黑色，z为右节点
								z = fa;
								right_rotate(tree, z);
							}		
							fa->color = BLANK;						//二小情况3：叔叔为黑色，z为左节点
							gfa->color = RED;
							left_rotate(tree, gfa);		
					}
				} else {
						break;
				}	
		}
		tree->head->color = BLANK;
}


int add(struct rbtree *tree, struct tree_node *node){
		if (tree->head == 0){
			node->color = BLANK;
			tree->head = node;
		} else {
				struct tree_node *fn;
				struct tree_node *next = tree->head;
				while(next->key != 0){
						fn = next;
						if (node->key < next->key){
								next = next->left;
						} else {
								next = next->right;
						}
				}			
				node->top = fn;
				if (node->key < fn->key){
						fn->left = node;
				} else {
						fn->right = node;
				}
				node->color = RED;
				install_fixup(tree, node);
		} 
		return 0;
}


//层次遍历，用到了队列
void cc_vactor(struct rbtree *L){
		struct tree_node *tn = L->head;
		struct queue * qu = (struct queue*)malloc(sizeof(struct queue));
		qu->head = 0;
		qu->tail = 0;
		enqueue(qu,tn);
		while(!is_full(qu)){
					tn = dequeue(qu);
					if(tn){
						printf("(%d,%d)  ",tn->key,tn->color);
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
//递归遍历
void digui(struct tree_node *tn) {
		if(tn && tn->key != 0){
				printf("(%d,%d)  ",tn->key,tn->color);
				digui(tn->left);
				digui(tn->right);
		}
}

int main(){
		struct rbtree * tree = (struct rbtree *)calloc(1,sizeof(struct rbtree));
		struct tree_node *node11 = make_node(11);
		struct tree_node *node2 = make_node(2);
		struct tree_node *node14 = make_node(14);
		struct tree_node *node1 = make_node(1);
		struct tree_node *node15 = make_node(15);
		struct tree_node *node7 = make_node(7);
		struct tree_node *node8 = make_node(8);
		struct tree_node *node5 = make_node(5);
		add(tree,node11);
		add(tree,node2);
		add(tree,node14);
		add(tree,node1);
		add(tree,node15);
		add(tree,node7);
		add(tree,node8);
		add(tree,node5);
		cc_vactor(tree);
		printf("\n");
}
