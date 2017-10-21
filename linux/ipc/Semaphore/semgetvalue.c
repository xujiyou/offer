#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
		if (argc != 2){
				printf("请输入信号量名");
				return 0;
		}
		sem_t *sem = sem_open(argv[1], 0);
		int val;
		sem_getvalue(sem, &val);
		printf("value = %d\n", val);
		return 0;
}
