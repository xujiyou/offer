#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

/*int main(int argc, char **argv){
		int flags = O_RDWR | O_CREAT;
		int c;
		while( (c = getopt(argc, argv, "e")) != -1 ){
				switch(c){
						case 'e':
								flags |= O_EXCL;
								break;
				}
		}
		mqd_t mqd = mq_open(argv[optind], flags, S_IRUSR|S_IWUSR, NULL);
		printf("%s\n",argv[optind]);
		mq_close(mqd);
		return 0;
}*/

int main (int argc, char ** argv){
		struct mq_attr attr;
		int flags = O_RDWR | O_CREAT;
		int c;
		while((c = getopt(argc,argv,"em:z:")) != -1){
				switch(c){
						case 'e':
								flags |= O_EXCL;
								break;
						case 'm':
								attr.mq_maxmsg = atol(optarg);
								break;
						case 'z':
								attr.mq_msgsize = atol(optarg);
								break;
				}
		}
		if (optind != argc -1){
				printf("参数不对\n");
				return 0;
		}
		mqd_t mqd = mq_open(argv[optind], flags, S_IRUSR|S_IWUSR,(attr.mq_msgsize != 0)? &attr:NULL);
		printf("%s\n",argv[optind]);
		mq_close(mqd);
		return 0;
}
