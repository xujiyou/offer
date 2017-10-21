#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thr_fn(void *arg){
		printf("thread 1 returned\n");
		return (void *)1;
}

void *thr_fn2(void *arg){
		printf("thread 2 exit\n");
		pthread_exit((void *)2);
}

int main(){
		pthread_t tid1, tid2;
		pthread_create(&tid1, NULL, thr_fn, NULL);
		pthread_create(&tid2, NULL, thr_fn2, NULL);
		void *tret;
		pthread_join(tid1, &tret);
		printf("thread 1 exit code is:%ld \n", (long)tret);
		pthread_join(tid2, &tret);
		printf("thread 2 exit code is:%ld \n", (long)tret);
		return 0;
}
