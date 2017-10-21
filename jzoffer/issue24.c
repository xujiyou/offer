#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*面试题24:二茬搜索树的后续遍历*/

#define true 1
#define false 0

int judge(int *arr,int head_index, int tail_index) {
		if (tail_index == head_index) {
				return true;
		}
		int tail = arr[tail_index];
		int mid;
		for (mid = head_index; mid < tail_index; mid++) {
				if (arr[mid] > tail){
						break;		
				}
		}
		for (int i = mid; i < tail_index; i++){
				if (arr[i] < tail){
						return false;
				}
		}
		return judge(arr, head_index, mid-1) && judge(arr, mid, tail_index-1);
}

int main(){
		int arr[] = {7,4,5,6};
		int result = judge(arr, 0, 3);
		printf(" %d \n", result);
}

