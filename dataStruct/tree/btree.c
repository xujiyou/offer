#include <stdio.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct _btree_node{
		int num;
		int *key;
		struct _btree_node **child;
		struct _btree_node *parent;
}btree_node_t;

typedef struct {
		int max;
		int min;
		int sidx;
		btree_node_t * head;
}btree_t;

btree_node_t *btree_node_create(btree_t *btree){
		btree_node_t *btree_node = (btree_node_t *)calloc(1, sizeof(btree_node_t));
		btree_node->key = (int *)calloc(btree->max+1,sizeof(int));
		btree_node->child = (btree_node_t **)calloc(btree->max+1, sizeof(btree_node_t *));
		return btree_node;
}

btree_t *btree_create(int t){
		btree_t * btree = (btree_t *)calloc(1,sizeof(btree_t));
		btree->max = 2*t-1;
		btree->min = t-1;
		btree->sidx = t;
		btree->head = 0;	
		return btree;
}

int tree_split(btree_t *btree, btree_node_t *node){
		int total; //当前节点的关键字总数
		btree_node_t *node2;//新建立的节点
		int sidx = btree->sidx;//B树中节点断裂的位置，中间位置
		btree_node_t *parent;//新节点与旧节点的父节点
		int idx;//记录新关键字应该插入的节点
		while (node->num > btree->max){
			total = node->num;
			node2 = btree_node_create(btree);
			memcpy(node2->key, node->key+sidx+1, (total-sidx-1)*sizeof(int));
			for (int i = sidx+1,j = 0; i < total-sidx; i++,j++ ){
				if (node->child[i] != NULL){
					node2->child[j] = node->child[i];
				}
			}
			//memcpy(node2->child, node->child+sidx+1,(total-sidx)*sizeof(btree_node_t));
			node2->num = total-sidx-1;
			node2->parent = node->parent;
			node->num = sidx;
			parent = node->parent;
			if (parent == NULL){
				parent = btree_node_create(btree);
				btree->head = parent;
				parent->child[0] = node;
				node->parent = parent;
				node2->parent = parent;
				parent->key[0] = node->key[sidx];
				parent->child[1] = node2;
				parent->num++;
			} else {
				for (idx = parent->num; idx > 0; idx--){
					if (node->key[sidx] < parent->key[idx-1]){
						parent->key[idx] = parent->key[idx-1];
						parent->child[idx+1] = parent->child[idx];
						continue;
					}
					break;
				}
				parent->key[idx] = node->key[sidx];
				parent->child[idx+1] = node2;
				node2->parent = parent;
				parent->num++;
			}
			memset(node->key+sidx,0,(total-sidx)*sizeof(int));
			/*for(int i = sidx+1; i <= total-sidx; i++){
					free(node->child[i]);
			}*/
			memset(node->child+sidx+1,0,(total-sidx)*sizeof(btree_node_t *));
			for (int i = 0; i < node2->num; i++){
				if(node2->child[i] != NULL){
					node2->child[i]->parent = node2;
				}
			}
			node = parent;
		}
		return 0;	
}

int install_key(btree_t *btree, btree_node_t *node, int idx, int key){
		for(int i = node->num; i > idx; i--){
			node->key[i] = node->key[i-1];
		}	
		node->key[idx] = key;
		node->num++;
		if (node->num > btree->max){
			return tree_split(btree, node);
		}
		return 0;
}

int add_key(btree_t *btree, int key){
		btree_node_t *node = btree->head;
		int idx;
		if (node == NULL){
			node = btree_node_create(btree);
			node->num = 1;
			node->key[0] = key;
			btree->head = node;
			return 1;		
		}
		while(node != NULL){
			for(idx = 0; idx < node->num; idx++){
				if (key == node->key[idx]){
					printf("key:%d 已存在\n",key);
					return 0;
				} else if(key < node->key[idx]){
					break;
				}
			}
			if (node->child[idx] != NULL){
				node = node->child[idx];
			} else {
				break;
			}
		}
		return install_key(btree,node,idx,key);
}

//递归遍历
void vlictor(btree_node_t *node){
		if(node != 0){
			printf("%d|",node->num);
			for(int i = 0; i < node->num; i++){
				printf(" %d ",node->key[i]);
			}
			printf("\n");
			for(int i = 0; i <= node->num; i++){
				vlictor(node->child[i]);
			}
		}	
}

int main(){
		btree_t *btree = btree_create(2);
		add_key(btree,45);
		add_key(btree,24);
		add_key(btree,53);
		add_key(btree,48);
		add_key(btree,49);
		add_key(btree,15);
		add_key(btree,18);
		add_key(btree,19);
		add_key(btree,46);
		add_key(btree,50);
		add_key(btree,51);
		add_key(btree,52);
		add_key(btree,90);
		add_key(btree,100);
		add_key(btree,110);
		add_key(btree,120);
		add_key(btree,130);
		vlictor(btree->head);
		printf("结束\n");
}
