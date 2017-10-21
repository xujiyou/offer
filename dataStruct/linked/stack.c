#include <stdio.h>

#define MAX 10

struct stack{
	int top;
	int sum[MAX];
};

int is_empty(struct stack *arr){
		if (arr->top == 0){
			return 1;
		}
		return 0;
}

int push(struct stack *arr,int var){
		if (arr->top < MAX){
			arr->sum[arr->top] = var;
			arr->top += 1;
		} else {
			return -1;
		}
	return var;
}

int pop(struct stack *arr){
		int var = 0;
		if (!is_empty(arr)){
			var =  arr->sum[arr->top];
			arr->top -= 1;
		} else {
			return -1;
		}
		return var;
}


int main(){
	struct stack arr;
	arr.top  = 0;
	push(&arr,10);
	push(&arr,11);
	push(&arr,12);
	push(&arr,13);
	push(&arr,14);
	push(&arr,15);
	push(&arr,16);
	push(&arr,17);
	push(&arr,18);
	push(&arr,19);
	push(&arr,20);
	push(&arr,21);
	push(&arr,22);
	for (int i = 0; i < arr.top; i++) {
		printf("%d  ", arr.sum[i]);
	}
	printf("\n");
	pop(&arr);
	pop(&arr);
	pop(&arr);
	pop(&arr);
	pop(&arr);
	for (int i = 0; i < arr.top; i++) {
		printf("%d  ", arr.sum[i]);
	}
	printf("\n");
}
