#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <signal.h>

int main(int argc, char **argv){
		mqd_t mqd = mq_open(argv[1], O_RDONLY | O_NONBLOCK);
		struct mq_attr attr;
		mq_getattr(mqd, &attr);
		char *buff = (char *)malloc(attr.mq_msgsize);
		sigemptyset(&zeromask);
}
