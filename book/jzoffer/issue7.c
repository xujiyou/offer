#include <stdio.h>
#include <malloc.h>

/*用两个栈实现一个队列*/

#define size 20

/*队列及栈的定义*/
typedef struct {
		int top;
		int num[size];
} stack_t;

typedef struct {
		int count;
		stack_t *stack1;
		stack_t *stack2;
}queue_t;

/*栈方法*/
int stack_empty (stack_t *stack){
		if (stack->top == 0){
				return 1;
		}
		return 0;
}

int stack_full(stack_t *stack){
		if (stack->top == size + 1){
				return 1;
		}
		return 0;
}

int push(stack_t *stack, int key){
		if (!stack_full(stack))	{
				stack->num[stack->top] = key;
				stack->top++;
				return key;
		}
		return -1;
}

int pop(stack_t * stack){
		if (!stack_empty(stack)){
				stack->top--;
				return stack->num[stack->top];
		}
		return -1;
}

/*队列方法*/
int queue_empty(queue_t *queue){
		if (queue->count == 0){
				return 1;
		}
		return 0;
}

int queue_full(queue_t *queue){
		if ( queue->count >= size ){
				return 1;
		}
		return 0;
}

int appendTail(queue_t *queue, int key){
		if (!queue_full(queue)){
				int pop_count = queue->stack2->top;
				for (int i = 0; i < pop_count; i++){
						push(queue->stack1, pop(queue->stack2));
				}
				push(queue->stack1,key);
				queue->count = queue->stack1->top + queue->stack2->top;
				return key;
		}
		return -1;
}

int deleteHead(queue_t *queue){
		if (!queue_empty(queue)){
				int pop_count = queue->stack1->top;
				for (int i = 0; i < pop_count-1; i++){
						push(queue->stack2, pop(queue->stack1));
				}
				int key = 0;
				if (pop_count > 0){
						key = pop(queue->stack1);
				} else {
						key = pop(queue->stack2);
				}
				queue->count = queue->stack1->top + queue->stack2->top;
				return key;
		}
		return -1;
}

void vocate(queue_t *queue){
		for (int i = 0; i < queue->stack1->top; i++){
				printf(" %d ", queue->stack1->num[i]);
		}
		for (int i = queue->stack2->top-1; i >= 0; i--){
				printf(" %d ", queue->stack2->num[i]);
		}
}

int main(){
		stack_t *stack1 = (stack_t *)malloc(sizeof(stack_t));
		stack_t *stack2 = (stack_t *)malloc(sizeof(stack_t));
		stack1->top = stack2->top = 0;
		queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
		queue->count = stack1->top + stack2->top;
		queue->stack1 = stack1;
		queue->stack2 = stack2;
		appendTail(queue, 1);
		appendTail(queue, 2);
		appendTail(queue, 3);
		deleteHead(queue);
		appendTail(queue, 4);
		appendTail(queue, 5);
		appendTail(queue, 6);
		appendTail(queue, 7);
		deleteHead(queue);
		deleteHead(queue);
		appendTail(queue, 19);
		appendTail(queue, 10);
		int delete_count = queue->count;
		for(int i = 0; i < delete_count; i++){
				printf(" %d ",deleteHead(queue));
		}
		//vocate(queue);
		
		printf("\n");
}
