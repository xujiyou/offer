#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <malloc.h>

int main(int argc, char **argv){
		int c;
		int flags = O_RDONLY;
		while((c = getopt(argc, argv, "n")) != -1){
				switch(c){
						case 'n':
								flags |= O_NONBLOCK;
								break;
				}
		}
		if (optind != argc - 1){
				printf("参数错误");
		}
		struct mq_attr attr;
		mqd_t mqd = mq_open(argv[optind], flags);
		mq_getattr(mqd,&attr);
		char *buff = (char *)malloc(attr.mq_msgsize);
		unsigned int prio;
		ssize_t n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);
		printf("read %ld bytes, priotiry = %u\n", (long)n, prio);
		printf("%s\n",buff);
		return 0;
}

