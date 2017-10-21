#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
		if (argc != 2){
				printf("请输入信号量名字");
				return 0;
		}
		sem_t *sem = sem_open(argv[1], 0);
		sem_wait(sem);
		int val;
		sem_getvalue(sem, &val);
		printf("pid %ld has semaphore, value = %d\n", (long) getpid(), val);
		return 0;
}
