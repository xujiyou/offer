#include <stdio.h>
#include <malloc.h>

struct link{
		int key;
		struct link *next;
};

struct link *create_node(int key){
		struct link *node = (struct link *)malloc(sizeof(struct link));
		node->key = key;
		node->next = NULL;
		return node;
}

void add_node(struct link *head, int key){
		struct link *node = create_node(key);
		if(head == NULL){
				head = node;	
		} else {
				while (head->next != NULL){
						head = head->next;
				}
				head->next = node;
		}
}

void bianli(struct link *head){
		if (head == NULL){
				return;
		}
		bianli(head->next);
		printf(" %d ",head->key);

}

int main(){
		struct link *head = create_node(0);
		add_node(head,1);
		add_node(head,2);
		add_node(head,3);
		add_node(head,4);
		add_node(head,5);
		bianli(head);
		printf("\n");
}
