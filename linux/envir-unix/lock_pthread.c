#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>

struct foo{
		int f_count;
		int f_id;
		pthread_mutex_t f_lock;
};

struct foo *foo_alloc(int id){
		struct foo *fp;
		if ((fp = (struct foo *)malloc(sizeof(struct foo))) != NULL) {
				fp->f_count = 1;
				fp->f_id = id;
				if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
						free(fp);
						return NULL;
				}
		}
		return fp;
}

void foo_hold(struct foo *fp){
		pthread_mutex_lock(&fp->f_lock);
		fp->f_count++;
		sleep(1);
		printf(" %d \n", fp->f_count);
		pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp){
		pthread_mutex_lock(&fp->f_lock);
		if (--fp->f_count == 0){
				pthread_mutex_unlock(&fp->f_lock);
				pthread_mutex_destroy(&fp->f_lock);
				free(fp);
		} else {
				pthread_mutex_unlock(&fp->f_lock);
		}
}

struct foo *fp;

void *thr_fn1(void *arg){
		foo_hold(fp);
//		foo_rele(fp);
		return (void *)0;
}

int main(){
		fp = foo_alloc(10);
		pthread_t tid1,tid2, tid3, tid4, tid5, tid6;
		pthread_create(&tid1, NULL, thr_fn1, NULL);
		pthread_create(&tid2, NULL, thr_fn1, NULL);
		pthread_create(&tid3, NULL, thr_fn1, NULL);
		pthread_create(&tid4, NULL, thr_fn1, NULL);
		pthread_create(&tid5, NULL, thr_fn1, NULL);
		pthread_create(&tid6, NULL, thr_fn1, NULL);
		foo_hold(fp);
		sleep(2);
}
