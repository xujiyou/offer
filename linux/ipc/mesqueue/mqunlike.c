#include <stdio.h>
#include <mqueue.h>

int main(int argc, char **argv){
		if( argc != 2 ){
				printf("参数需要为2");
		}
		mq_unlink(argv[1]);
		printf("删除%s\n",argv[1]);
		return 0;
}
