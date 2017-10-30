#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define size 10

void merge(int *arr, int head, int tail, int mid){
		int count = tail-head;
		int temp[count];
		int tag = 0;
		int i = head;
		int j = mid+1;
		while (i <= mid && j <= tail) {
				if (arr[i] < arr[j]){
						temp[tag++] = arr[i++];
				} else {
						temp[tag++] = arr[j++];
				}
		}	
		while (i <= mid){
				temp[tag++] = arr[i++];
		}
		while( j <= tail ){
				temp[tag++] = arr[j++];
		}
		for (int k = 0; k < tag; k++){
				arr[head + k] = temp[k];
		}
}

void merge_recursion(int *arr, int head, int tail){
		if (head >= tail){
				return;
		}
		int mid = (head+tail)/2;
		merge_recursion(arr, head, mid);
		merge_recursion(arr, mid+1, tail);
		merge(arr, head, tail, mid);

}

int main(){
		int arr[size] = {9,8,7,6,5,4,3,2,1,0};
		merge_recursion(arr, 0, size-1);
		for (int i = 0; i < size; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
