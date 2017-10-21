#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct foo_t{
		int a, b, c, d;
};

void printfoo(char *str, struct foo_t *fp){
		printf("%s\n",str);
		printf("foo.a = %d\n", fp->a);
		printf("foo.b = %d\n", fp->b);
		printf("foo.c = %d\n", fp->c);
		printf("foo.d = %d\n", fp->d);
}

void *thr_fn1(void *arg){
		struct foo_t foo = {1,2,3,4};
		char *str = "thread:1";
		printfoo(str, &foo);
		sleep(2);
		pthread_exit((void *)&foo);	
}

int main(){
		pthread_t tid1;
		struct foo_t *foo;
		pthread_create(&tid1, NULL, thr_fn1, NULL);
		pthread_join(tid1, (void *)&foo);
		printfoo("parent:",foo);

}
