#include <stdio.h>

/*二分查找*/

//非递归方式
int binary_chop(int *arr, int length, int key){
		int center;
		int head = 0;
		int tail = length - 1;
		while (head <= tail){
				printf(" - ");
				if (arr[head] == key){
						return head;
				} else if (arr[tail] == key){
						return tail;
				} else if (arr[head] > key){
						break;
				} else if (arr[tail] < key){
						break;
				}
				center = (head + tail)/2;
				if (arr[center] == key){
						return center;
				} else if (arr[center] < key){
						head = center + 1;
				} else {
						tail = center - 1;
				}

		}
		return -1;
}

//递归方式
int binary_chop_recursion(int *arr, int head, int tail, int key){
		if (head <= tail){
				printf(" - ");
				if (arr[head] == key){
						return head;
				} else if (arr[tail] == key){
						return tail;
				} else if (arr[head] > key){
						return -1;
				} else if (arr[tail] < key){
						return -1;
				}
				int center = (head + tail)/2;
				if (arr[center] == key){
						return center;
				} else if (arr[center] < key){
						return binary_chop_recursion(arr, center+1, tail, key);
				} else {
						return binary_chop_recursion(arr, head, center-1, key);
				}

		}
		return -1;
}

int main(){
		int arr[10] = {0,1,2,3,4,5,6,7,8,9};
		int index = binary_chop_recursion(arr,0,9,1);
		printf("\n");
		printf(" %d \n",index);
}
