#include <stdlib.h>
#include <stdio.h>

/*面试题22:栈的压入，弹出系列,判断一个队列能不能是另外一个队列的弹出队列*/

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

int is_equals(int *arr1, int *arr2, int length){
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		Stack *jilu = (Stack *)malloc(sizeof(Stack));
		stack->top = jilu->top = 0;
		int tag = 0;
		for (int i = 0; i < length; i++) {
				push(stack, arr1[i]);
				//如果压入的数字和需要弹出的队列中的当前数字一致，则将其弹出并压入到辅助队列
				if (arr1[i] == arr2[tag]) {
						push(jilu,pop(stack));
						tag++;
						//循环再判读栈中的剩余数字是不是和队列当前数字一直
						int prev = 0;
						while ( (prev = pop(stack)) == arr2[tag] ) {
								push(jilu, prev);
								tag++;
						}			
						push(stack, prev);
				}
		}
		//判断队列和辅助栈是否一致，若有一不一致，则不对
		for (int i = length - 1; i >= 0; i--) {
				if (pop(jilu) != arr2[i]) {
						return false;
				}
		}
		return true;
}

int main(){
		int arr1[] = {1,2,3,4,5};
		int arr2[] = {3,2,5,4,1};
		int result = is_equals(arr1, arr2, 5);
		printf("%d\n", result);
}
