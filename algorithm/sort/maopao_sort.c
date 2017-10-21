#include <stdio.h>

#define length 10

/*
 *冒泡排序，时间复杂度为n的2次方
 * */

void maopao_sort(int arr[], int n){
		for (int i = 0; i < n; i++){
				for (int j = n-1; j > i; j--){
						if (arr[j] > arr[j-1]){
							int temp = arr[j];
							arr[j] = arr[j-1];
						    arr[j-1] = temp;	
						}
				}
		}
}

//高效版本，如果上次没有得到转换，则不进行下次的排序
void maopao_sort2(int arr[],int n){
		int flag;
		for (int i = 0; i < n-1; i++){
				flag = 0;
				for (int j = n-1; j > i; j--){
						if (arr[j] > arr[j-1]){
							int temp = arr[j];
							arr[j] = arr[j-1];
						    arr[j-1] = temp;	
							flag = 1;
						}
				}
				if (flag == 0){
						printf("跳出位置：%d\n",i);
						break;
				}
		}

}

int main(){
		int arr[length] = {5,4,3,2,6,1,7,8,9,10};
		printf("按照从大到小排序，未排序前：\n");
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
		maopao_sort2(arr,length);
		printf("冒泡排序后\n");
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
		return 0;
}
