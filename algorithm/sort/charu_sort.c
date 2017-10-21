#include <stdio.h>

#define length 6

/*
 *从大到小，插入排序，和摸扑克牌一样
 * */

void charu_sort(int arr[], int n){
		for (int i = 1; i < n; i++){
				int j;
				for(j = 0 ; j < i; j++){
						if (arr[j] < arr[i]){
								break;
						}
				}
				int temp = arr[i];
				for(int k = i;k > j; k--){
					arr[k] = arr[k-1];
				}
				arr[j] = temp;
		}
}

int main(){
		int arr[length] = {1,2,3,4,5,6};
		charu_sort(arr,length);
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
