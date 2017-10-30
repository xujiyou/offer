#include <stdio.h>
#include <string.h>

/*int get_arr_length(int arr[]){
		return sizeof(arr);
}

int get_length(){
		int arr[] = {1,2,3,4,5};
		printf(" %d ",sizeof(arr));
		int *a1 = arr;
		printf(" %d ",sizeof(a1));
		printf(" %d ",get_arr_length(arr));
		printf("\n");
}*/

#define row_d 4
#define col_d 4

int strtoint(char *str){
	int num = 0;
	int fu = 1;
	int begen = 0;
	for(size_t i = 0; i < strlen(str);i++) { //strlen计算字符串的实际长度，不算结尾的\0
			if ( str[i] > 48 && str[i] < 58 ) {
				num = num * 10 + str[i] - '0'; 
				if (begen == 0) {
					begen = 1;
				}
			} else {
				if (begen == 0 && str[i] == '-') {
					fu = -1;
				}
			}
	}
	num = num * fu;
	return(num);
}

int twoarr_select(int arr[4][4], int row, int col, int data){
		int i = 0;
		int j = col;
		while (i <= row && j >= 0){
				if (arr[i][j] == data){
					return 1;
				} else if (arr[i][j] > data){
					j--;
				} else{
					i++;
				}
		}
		return 0;
}

int main(int argc, char *argv[]){
	//	get_length();
		int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
		int result = twoarr_select(arr, 3, 3, strtoint(argv[1]));	
		if (result){
				printf("存在\n");
		} else {
				printf("不存在\n");
		}
}
