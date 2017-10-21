#include "table.h"

int hash_func(int key){
		return key % MAX;
}

int install(hash_table *table, hash_node *node){
		int addr = hash_func(node->key);
		while (table->num[addr] != 0){
				addr = (addr + 1) % MAX;
		} 
		table->num[addr] = node;
		return addr;
}

int search(hash_table *table, hash_node *node, int *addr){
		*addr = hash_func(node->key);
		while (table->num[*addr]->key != node->key){
				*addr = (*addr+1) % MAX;
				if (table->num[*addr] == 0 || *addr == hash_func(node->key)){
						return 0;
				}
		}
		return 1;
}

int main(){
		hash_table *table = (hash_table *)malloc(sizeof(hash_table));
		hash_node *node1 = (hash_node *)malloc(sizeof(hash_node));
		node1->key = 1;
		node1->value = "WE";
		install(table, node1);
		hash_node *node2 = (hash_node *)malloc(sizeof(hash_node));
		node2->key = 14;
		node2->value = "RNG";
		install(table, node2);
		hash_node *node3 = (hash_node *)malloc(sizeof(hash_node));
		node3->key = 27;
		node3->value = "EDG";
		install(table, node3);
		int *addr = (int *)malloc(sizeof(int));
		search(table, node3, addr);
		printf("%s  \n", table->num[*addr]->value);

}
