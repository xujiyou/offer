#include <stdio.h>

#define n 10

struct twlinked{
		int top1;
		int top2;
		int num[n];
};

int is_full(struct twlinked *tw){
		if (tw->top1 == tw->top2) {
			return 1;
		}
		return 0;
}

int push1(struct twlinked *tw, int var){
		if (!is_full(tw)) {
				tw->num[tw->top1] = var;
				tw->top1++;
				return var;
		}
		return -1;
}

int push2(struct twlinked *tw, int var){
		if (!is_full(tw)){
				tw->num[tw->top2] = var;
				tw->top2--;
				return var;
		}
		return -1;
}

int main(){
		struct twlinked tw;
		tw.top1 = 0;
		tw.top2 = n-1;
		push1(&tw, 0);
		push2(&tw, 9);
		push1(&tw, 2);
		push2(&tw, 8);
		push1(&tw, 3);
		push2(&tw, 5);
		for (int i = 0; i < n;i++){
				printf("%d  ", tw.num[i]);
		}
		printf("\n");
}
