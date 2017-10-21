#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void printid(const char *str){
		pid_t pid = getpid();
		pthread_t tid = pthread_self();
		printf("%s pid %lu, tid %lu (0x%lx)\n", str, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void *thread_fn(void *arg){
		printid("new thread:");
		return (void *)0;
}

int main(){
		pthread_t ntid;
		int err = pthread_create(&ntid, NULL, thread_fn, NULL);
		if (err != 0){
				printf("创建线程出错");
				return 0;
		}
		printid("main thread:");
		void *arg = 0;
		thread_fn(arg);
		sleep(1);
		return 0;
}
