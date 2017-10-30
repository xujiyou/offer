#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

/*面试题21:实现一个栈，是这个栈能查找栈中的最小值，且push，pop和min的时间复杂度都为O(1)*/

#define size 20
#define false 0
#define true 1

typedef struct Stack_t{
		int top;
		int arr[size];
} Stack;

int is_empty(Stack *stack){
		if (stack->top == 0) {
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

int push(Stack *stack, int key){
		if (!is_full(stack)) {
				stack->arr[stack->top] = key;
				stack->top++;
				return key;
		}
		return -1;
}

int pop(Stack *stack){
		if (!is_empty(stack)) {
				stack->top--;
				return stack->arr[stack->top];
		}
		return -1;
}

int push_1(Stack *stack, int key, Stack *min_stack){
		if (is_empty(stack)) {
				push(stack, key);
				push(min_stack, key);
				return key;
		}
		push(stack, key);
		int min = pop(min_stack);
		if (key < min){
				push(min_stack,min);
				push(min_stack,key);			
		} else {
				push(min_stack,min);
		}
		return key;
}

int pop_1(Stack *stack, Stack *min_stack){
		int min = pop(min_stack);
		int key = pop(stack);
		if (min != key){
				push(min_stack, min);
		}
		return min;
}

int get_min(Stack *min_stack){
		return pop(min_stack);
}

int main(){
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		Stack *min_stack = (Stack *)malloc(sizeof(Stack));
		stack->top = min_stack->top = 0;
		int arr[] = {3,2,1,4,5,6};
		int len = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < len; i++) {
				push_1(stack, arr[i], min_stack);
		}
		printf("%d \n",get_min(min_stack));
		printf("%d \n",get_min(min_stack));
		printf("%d \n",get_min(min_stack));
}
