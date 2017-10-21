#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define size 31
#define true 1
#define false 0

typedef struct stack_t{
		int top;
		int arr[size];
}Stack;

int is_empty(Stack *stack){
		if (stack->top == 0){
				return true;
		}
		return false;
}

int is_full(Stack *stack){
		if (stack->top == size){
				return true;
		}
		return false;
}

void push(Stack *stack, int key){
		if (!is_full(stack)){
				stack->arr[stack->top] = key;
				stack->top++;
		}
}

int pop(Stack *stack){
		if (!is_empty(stack)){
				stack->top--;
				return stack->arr[stack->top];
		}
		return 0;
}

int make_magic1(int n){
		return (n-1) / 2;
}

int make_magic2(int n){
		return (n - 2) / 2;
}

void make(int n, Stack *stack){
		if (n == 0) {
				return ;
		}
		if (n % 2 == 0){
				n = make_magic2(n);
				push(stack, 2);
		} else {
				n = make_magic1(n);
				push(stack, 1);
		}
		make(n, stack);
}

int main(int argc, char *argv[]){
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		stack->top = 0;
		memset(stack->arr, 0, size);
		int n = 0;
		scanf("%d",&n);
		make(n, stack);
		int len = stack->top;
		for (int i = 0; i < len; i++){
				printf("%d", pop(stack));
		}
		printf("\n");
}
