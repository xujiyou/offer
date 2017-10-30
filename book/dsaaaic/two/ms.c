#include <stdio.h>
#include <stdlib.h>

/*题目：求最大子序列*/

//第一种方式，列出全部解,时间复杂度为n的三次方
int max_sequence(int *arr, int len){
	int result = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			int temp = 0;
			for (int k = i; k < j; k++) {
				temp += arr[k];
			}	
            if (temp > result) {
                result = temp;
            }
		}
	}
    return result;
}

//第二种方式，去掉一层循环，时间复杂度为n的平方
int max_sequence_2(int *arr, int len){
    int result = 0;
    for (int i = 0; i < len; i++) {
        int temp = 0;
        for (int j = i; j < len; j++) {
            temp += arr[j];
            if (temp > result) {
                result = temp;
            }
        }
    }
    return result;
}

int max(int a, int b, int c){
    if (a > b && a > c) {
        return a;
    } else if (b > a && b > c) {
        return b;
    } else {
        return c;
    }
}

//第三种方式，使用分治法，采用递归的方式
int max_sequence_3(int *arr, int head, int tail){
    if (head == tail){
        if (arr[head] > 0){
            return arr[head];
        } else {
            return 0;
        }
    }
    
    int mid = (head + tail) / 2;
    int left_max = max_sequence_3(arr, head, mid);
    int right_max = max_sequence_3(arr, mid + 1, tail);
    
    int left_border_max = 0, left_border_max_temp = 0;
    for (int i = mid; i >= head; i--) {
        left_border_max_temp += arr[i];
        if (left_border_max_temp > left_border_max) {
            left_border_max = left_border_max_temp;
        }
    }

    int right_border_max = 0, right_border_max_temp = 0;
    for (int i = mid + 1; i <= tail; i++) {
        right_border_max_temp += arr[i];
        if (right_border_max_temp > right_border_max) {
            right_border_max = right_border_max_temp;
        }
    }

    return max(left_max, right_max, left_border_max + right_border_max);
}

//第四种方式，最快的方式？
int max_sequence_4(int *arr, int len){
    int result = 0, temp = 0;
    for (int i = 0; i < len; i++) {
        temp += arr[i];
        if (temp > result) {
            result = temp;
        } else if (temp < 0) {
            temp = 0;
        }
    }
    return result;
}

int main(){
    int arr[] = {3,-3,5,-2,-1,2,6,-2};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf(" %d \n", max_sequence(arr, len));
    printf(" %d \n", max_sequence_2(arr, len));
    printf(" %d \n", max_sequence_3(arr, 0, len-1));
    printf(" %d \n", max_sequence_4(arr, len));
}
