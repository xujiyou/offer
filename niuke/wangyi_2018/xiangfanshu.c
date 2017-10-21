#include <stdlib.h>
#include <stdio.h>
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

int xiangfan(int n){
		int prev = n;
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		stack->top = 0;
		memset(stack->arr, 0, size);
		int position = 1;
		while ((n / position) >= 10) {
				position *= 10;
		}
		int order = position;
		while (position >= 1) {
				push(stack, n/position);
				n %= position;
				position /= 10;
		}
		int xiangfanshu = 0;
		int len = stack->top;
		for (int i = 0; i < len; i++){
				xiangfanshu += pop(stack) * order;
				order /= 10;
		}
		xiangfanshu += prev;
		return xiangfanshu;
}

int main(){
		int n = 0;
		scanf("%d", &n);
		int xiangfanshu = xiangfan(n);
		printf("%d\n",xiangfanshu);
}
