#include <stdlib.h>
#include <stdio.h>

//冒泡排序
void sort(int *arr, int len){
	if (arr == NULL){
		return ;
	}
	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
		
}


int get_sort_k(int *arr, int len, int k){
	sort(arr, len);
	return arr[k-1];
}

//先将前k个排序，然后读入接下来的元素，若小于第k的就忽略，否则就放到该放的位置上，同时将第k个挤出
int get_k(int *arr,int len, int k){
	sort(arr, k);
	k = k - 1;
	for (int i = k + 1; i < len; i++) {
		if (arr[i] > arr[k]) {
			for (int j = 0; j <= k; j++) {
				if (arr[i] > arr[j]) {
					int temp = arr[j];
					arr[j] = arr[i];
					for (int yi = k; yi > j+1; yi--) {
							arr[yi] = arr[yi-1];
					}
					arr[j+1] = temp;
					break;
				}
			}			
		}
	}
	return arr[k];
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = get_k(arr, len, 5);
	printf("%d\n", result);
	for (int i = 0; i < len; i++) {
			printf(" %d ", arr[i]);
	}
	printf("%d\n", result);
	return 0;
}
