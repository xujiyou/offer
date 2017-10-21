#include <stdio.h>
#include <mqueue.h>
#include <malloc.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

mqd_t mqd;
char *buff;
struct sigevent sigev;
struct mq_attr attr;

void sig_user1(int sig){
		mq_notify(mqd, &sigev);
		ssize_t n = mq_receive(mqd, buff, attr.mq_msgsize,NULL);
	
		printf("SIGUSR1 received , read %ld bytes\n",(long)n);
		printf("%s\n",buff);
		return;
}

int main( int argc, char **argv){
		mqd = mq_open(argv[1], O_RDONLY);
		mq_getattr(mqd, &attr);
		buff = (char *)malloc(attr.mq_msgsize);
		signal(SIGUSR1, sig_user1);
		sigev.sigev_notify = SIGEV_SIGNAL;
		sigev.sigev_signo = SIGUSR1;
		mq_notify(mqd, &sigev);
		for(;;){
				printf("哈哈");
				pause();
		}
		return 0;
}
