#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>   
#include <fcntl.h>

int main(int argc, char *argv[]){
		int flags = O_RDWR | O_CREAT;
	    int c;
		int value;
		while  ( (c = getopt(argc, argv, "ei:")) != -1){
				switch(c){
						case 'e':
								flags |= O_EXCL;
								break;
						case 'i':
								value = atoi(optarg);
								break;
				}
		}
		if (optind != argc - 1){
				printf("请选信号量；");
				return 0;
		}
		sem_t *sem = sem_open(argv[optind], flags, S_IRUSR|S_IWUSR, value);
		sem_close(sem);
		return 0;
}
