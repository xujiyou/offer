#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
		if (argc != 2){
				printf("请输入信号量名字！");
				return 0;
		}
		int result = sem_unlink(argv[1]);
		if (result == 0){
				printf("删除成功");
		} else if (result == -1){
				printf("错误");
		}
		return 0;
}
