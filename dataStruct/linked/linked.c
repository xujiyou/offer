#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
		int n;
		struct node *next;
		struct node *prev;
};

struct link{
		struct node *head;
		struct node *tail;
		int num;
};

struct node *create_node(int var){
		struct node *pnode = (struct node *)malloc(sizeof(struct node));
		pnode->n = var;
		pnode->next = 0;
		pnode->prev = 0;
		return pnode;
}

struct link *init_link(){
		struct link *L = (struct link *)malloc(sizeof(struct link));
		struct node *head_node = create_node(0);
		L->head = head_node;
		L->tail = head_node;
		L->num = 1;
		return L;
}

struct node *insterNodeOnFirst(struct link *L, struct node *pnode){
		struct node *head_node = L->head;
		head_node->next = pnode;
		pnode->prev = head_node;
		L->tail = pnode;
		L->num++;
		return pnode;
}

struct node *getNodeByIndex(struct link *L, int index){
		if (index < L->num){
				struct node *head = L->head;
				int i = 0;
				while(i != index){
					head = head->next;
					i++;	
				}
				return head;
		}
		return 0;
}

struct node *addNext(struct link *L, struct node *position, struct node *pnode){
		if (position->next != 0){
				pnode->next = position->next;
				position->next->prev = pnode;
		}
		position->next = pnode;
		pnode->prev = position;
		L->num++;
		return pnode;
}

struct node *deletenode(struct link *L, struct node *pnode){
		if (pnode->prev != 0){
				pnode->prev->next = pnode->next;
		}
		if (pnode->next != 0){
				pnode->next->prev = pnode->prev;
		}
		L->num--;
		free(pnode);
		return pnode;
}

int main(){
		struct link *L = init_link();
		struct node *pnode = create_node(2);
		insterNodeOnFirst(L, pnode);
		struct node *pnode1 = create_node(3);
		struct node *pnode2 = create_node(4);
		struct node *pnode3 = create_node(5);
		addNext(L, getNodeByIndex(L, 1), pnode1);
		addNext(L, getNodeByIndex(L, 2), pnode2);
		deletenode(L,pnode1);
		addNext(L, getNodeByIndex(L, 1), pnode3);
		struct node *head = L->head;
		while(head){
				printf("%d   ",head->n);
				head = head->next;
				if (head == 0){
						break;
				}
		}
		printf("\n");
}

