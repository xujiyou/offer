#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv){
		if (argc != 4){
				printf("参数应为：name bytes priority");
				return 0;
		}
		//int len = atoi(argv[2]);
		unsigned int prio = atoi(argv[3]);
		mqd_t mqd = mq_open(argv[1],O_WRONLY);
		char *ptr = "rinima";
		mq_send(mqd, ptr, sizeof(ptr), prio);
		return 0;
}
