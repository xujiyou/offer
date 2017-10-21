#include "table.h"

struct link_node{
		hash_node *hn;
		struct link_node *next;
		struct link_node *prev;
};

typedef struct link_node linkNode;

struct linked{
		linkNode *head;
		int count;
};

typedef struct linked link;

typedef struct {
		link *links[MAX];
}link_table;

int table_func(int key){
		return key % MAX;
}

int install(link_table *table, hash_node* hn){
		int addr = table_func(hn->key);
		linkNode *ln = (linkNode *)malloc(sizeof(linkNode));
		ln->hn = hn;
		ln->next = 0;
		ln->prev = 0;
		if (table->links[addr] == 0){
				link *firstLink = (link *)malloc(sizeof(link));
				firstLink->head = 0;
				firstLink->count = 0;
				table->links[addr] = firstLink;
		}
		if (table->links[addr]->head == 0){
				table->links[addr]->head = ln;
		} else {
				linkNode *nextNode = table->links[addr]->head;
				while(nextNode->next){
						nextNode = nextNode->next;
				}
				nextNode->next = ln;
				ln->prev = nextNode;
		}
		table->links[addr]->count++;
		return hn->key;
}

int search(link_table *table, int key, char *value){
		int addr = table_func(key);
		if (table->links[addr] != 0){
				linkNode *nextNode = table->links[addr]->head;
				while(nextNode){
						if (nextNode->hn->key == key){
								char *r = (char *)malloc(MAX*sizeof(char));
								r =  nextNode->hn->value; 
								printf("%s \n",r);
								while((*value++ = *r++)!='\0');
								return 1;
						}
						nextNode = nextNode->next;
				}
		}
	   return 0;	
}

int main(){
		link_table *table = (link_table *)malloc(sizeof(link_table));
		hash_node *hn1 = (hash_node *)malloc(sizeof(hash_node));
		hn1->key = 1;
		hn1->value = "WE";
		install(table, hn1);
		hash_node *hn2 = (hash_node *)malloc(sizeof(hash_node));
		hn1->key = 14;
		hn1->value = "RNG";
		install(table, hn2);
		hash_node *hn3 = (hash_node *)malloc(sizeof(hash_node));
		hn3->key = 27;
		hn3->value = "EDG";
		install(table, hn3);
		char *value = (char *)malloc(MAX*sizeof(char));
		search(table, 27, value);
		printf("%s \n",value);
}


