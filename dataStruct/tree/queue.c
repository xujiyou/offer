#include <stdio.h>

#define MAX 10

struct queue{
		int head;
		int tail;
		int num[10];
};

int jj = 0;

int is_empty(struct queue *qu){
		if (qu->head == qu->tail){
				return 1;
		} else {
				return 0;
		}
}

int is_full(struct queue *qu){
		if (qu->tail == MAX && qu->head == 0){
				return 1;
		} else if (qu->head - qu->tail == 1){
				jj = 1;
				return 0;
		} else if (jj == 1){
				return 1;
		}  else {
				return 0;
		}
}

int enqueue(struct queue *qu, int var){
		if ( !is_full(qu) ){
				if ( qu->tail == MAX ){
						qu->tail = 0;
				}
				qu->num[qu->tail] = var;
				if (qu->tail < MAX){
					qu->tail++;
				}
				return var;
		}
		return -1;
}

int dequeue(struct queue *qu){
		if (!is_empty(qu) || jj == 1){
				int var = qu->num[qu->head];
				if (qu->head < MAX) {
						qu->head++;
				} else {
						qu->head = 0;
				}
				jj = 0;
				return var;
		}
		return -1;
}

int main(){
		struct queue qu;
		qu.head = qu.tail = 0;
		enqueue(&qu, 10);
		enqueue(&qu, 11);
		enqueue(&qu, 12);
		enqueue(&qu, 13);
		enqueue(&qu, 14);
		enqueue(&qu, 15);
		enqueue(&qu, 16);
		enqueue(&qu, 17);
		enqueue(&qu, 18);
		enqueue(&qu, 19);
		enqueue(&qu, 20);
		enqueue(&qu, 21);
		enqueue(&qu, 22);
		for (int i = qu.head; i < qu.tail; i++){
				printf("%d   ",qu.num[i]);
		}
		printf("\n");
		dequeue(&qu);
		dequeue(&qu);
		dequeue(&qu);
		for (int i = qu.head; i < qu.tail; i++){
				printf("%d   ",qu.num[i]);
		}
		printf("\n");
		enqueue(&qu, 1);
		enqueue(&qu, 2);
		enqueue(&qu, 3);
		dequeue(&qu);
		dequeue(&qu);
		dequeue(&qu);
		printf("%d\n",qu.head);
		enqueue(&qu, 4);
		enqueue(&qu, 3);
		for (int i = 0; i < MAX; i++){
				printf("%d   ",qu.num[i]);
		}
		printf("\n");
}
