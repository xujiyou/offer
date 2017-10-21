#include <stdio.h>
#include <malloc.h>

#define MAX 20

typedef struct {
		int index;
		char *str;
} dtable;

int install_table(dtable *tables[], dtable *table){
		if (table->index < MAX) {
				tables[table->index] = table;
				return table->index;
		}
		return -1;
}

int delete_table(dtable *tables[], int index){
		if (index < MAX && index >= 0) {
				tables[index] = 0;
				return index;
		}
		return -1;
}

char *search(dtable *tables[], int index){
		if (index < MAX && index >= 0) {
				return tables[index]->str;
		}
		return 0;
}

void get_index(dtable *tables[], int arr[MAX]){
		for(int i = 0; i < MAX; i++){
				if (tables[i] != 0){
						arr[i] = tables[i]->index;
				} else {
						arr[i] = -1;
				}
		}
}


int main(){
		dtable *tables[MAX] = {0};
		dtable *table1 = (dtable *)malloc(sizeof(dtable));
		table1->index = 0;
		table1->str = "WE";
		install_table(tables, table1);
		dtable *table2 = (dtable *)malloc(sizeof(dtable));
		table2->index = 1;
		table2->str = "RNG";
		install_table(tables, table2);
		dtable *table3 = (dtable *)malloc(sizeof(dtable));
		table3->index = 2;
		table3->str = "EDG";
		install_table(tables, table3);
		int arr[MAX] ={0};
		get_index(tables, arr);
		for(int i = 0; i < MAX; i++){
				if (arr[i] != -1){
						printf("%s  ",search(tables,arr[i]));
				}
		}
		printf("\n");
}
