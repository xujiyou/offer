#include <stdio.h>
#include <malloc.h>

/*面试题7扩展--使用两个队列实现一个栈*/

#define size 20

typedef struct {
		int head;
		int tail;
		int count;
		int num[size];
} queue_t;

typedef struct {
		int count;
		queue_t *queue1;
		queue_t *queue2;
}stack_t;

/*队列的方法*/
int queue_empty(queue_t *queue){
		if (queue->count == 0){
				return 1;
		}
		return 0;
}

int queue_full(queue_t *queue){
		if (queue->count == size){
				return 1;
		}
		return 0;
}

int append_queue(queue_t *queue, int key){
		if (!queue_full(queue)) {
				queue->num[queue->tail] = key;
				if (queue->tail == size-1){
						queue->tail = 0;
				} else {
						queue->tail++;
				}
				queue->count++;
				return key;	
		}
		return -1;
}

int delete_queue(queue_t *queue){
		if (!queue_empty(queue)){
				int key = queue->num[queue->head];
				queue->num[queue->head] = 0;
				if (queue->head == size-1){
						queue->head = 0;
				} else {
						queue->head++;
				}
				queue->count--;
				return key;
		}
		return -1;
}

/*栈的方法*/
int stack_empty(stack_t *stack){
		if (stack->count == 0){
				return 1;
		}
		return 0;
}

int stack_full(stack_t *stack){
		if (stack->count == size){
				return 0;
		}
		return 0;
}

int push(stack_t *stack, int key){
		if (!stack_full(stack)) {
				append_queue(stack->queue1, key);
				stack->count = stack->queue1->count + stack->queue2->count;
				return key;
		}
		return -1;
}

int pop(stack_t *stack){
		if (!stack_empty(stack)) {
				int delete1_count = stack->queue1->count;
				for (int i = 0; i < delete1_count -1; i++){
						append_queue(stack->queue2, delete_queue(stack->queue1));
				}
				int key = delete_queue(stack->queue1);
				int delete2_count = stack->queue2->count;
				for (int i = 0; i < delete2_count; i++){
						append_queue(stack->queue1, delete_queue(stack->queue2));
				}
				stack->count = stack->queue1->count + stack->queue2->count;
				return key;
		}
		return -1;
}

int main(){
		queue_t *queue1 = (queue_t *)malloc(sizeof(queue_t));
		queue_t *queue2 = (queue_t *)malloc(sizeof(queue_t));
		queue1->head = queue2->head = 0;
		queue1->tail = queue2->tail = 0;
		queue1->count = queue2->count = 0;
		stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
		stack->count = 0;
		stack->queue1 = queue1;
		stack->queue2 = queue2;
		push(stack, 1);
		push(stack, 2);
		push(stack, 3);
		push(stack, 4);
		push(stack, 17);
		push(stack, 18);
		push(stack, 19);
		push(stack, 10);
		int count = stack->count;
		for (int i = 0; i < count; i++){
				printf(" %d ", pop(stack));
		} 
		printf("\n");
}
