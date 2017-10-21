#include <stdio.h>
#include <mqueue.h>

int main(int argc, char **argv){
		if (argc != 2){
				printf("参数需要为2\n");
				return 0;
		}
		mqd_t mqd = mq_open(argv[1], O_RDONLY);
		struct mq_attr attr;
		mq_getattr(mqd, &attr);
		printf("max #msgs = %ld, max #bytes/mag = %ld,"
						"#currently on queue = %ld\n",attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
		mq_close(mqd);
		return 0;
}
