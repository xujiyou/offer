#include <stdio.h>
#include <malloc.h>

#define MAX 13

typedef struct {
		int key;
		char *value;
}hash_node;

typedef struct {
		hash_node *num[MAX];
}hash_table;
