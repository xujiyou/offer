#include <stdio.h>
#include <stdlib.h>

/*
 *面试题8：求旋转数组的最小数字----二分查找的变形
 * */

int get_min(int *arr, int length){
		int head = 0;
		int tail = length - 1;
		while (head < tail){
				int mid = (head + tail)/2;
				if (arr[head] < arr[mid] && arr[mid] > arr[tail]) {
						head = mid;
				} else if (arr[head] > arr[mid] && arr[mid] < arr[tail]) {
						tail = mid;
				}
				if (arr[tail] < arr[tail-1]) {
						return arr[tail];
				} else if (arr[head] > arr[head+1]){
						return arr[head+1];
				}
		}
		return -1;
}

int main(){
		int arr[10] = {5,6,7,8,9,10,11,1,2,3};
		int min = get_min(arr, 10);
		printf(" %d \n", min);
}
