#include <stdio.h>
#include <string.h>

#define length 10

/*
 *从大到小，标记排序，计数排序（网上的盗版桶排序），必须指出数组中的最大值，默认最小为0。
 * */

void tong_sort(int arr[], int n, int max){
		int tong[max];
		memset(tong,0,max*sizeof(int));
		for(int i = 0; i < n; i++){
			tong[arr[i]]++;
		}
		for(int i = max-1,j = 0; i > 0; i--){
				while(tong[i] > 0){
						tong[i]--;
						arr[j] = i;
						j++;
				}
		}
}

int main(){
		int arr[length] = {1,3,4,5,6,7,8,9,12,20};
		tong_sort(arr,length,21);
		for(int i = 0; i < 10; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}

