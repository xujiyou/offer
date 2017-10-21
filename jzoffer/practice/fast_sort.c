#include <stdio.h>
#include <stdlib.h>

void fast_sort(int *arr, int head, int tail){
		if (head < tail){
				int i = head;
				int j = tail;
				int num = arr[head];
				while(i < j){
						while (i < j && arr[j] > num) {
								j--;
						}
						if (i < j){
								arr[i++] = arr[j];
						}
						while (i < j && arr[i] < num) {
								i++;
						}
						if (i < j) {
								arr[j] = arr[i];
						}
				}
				arr[i] = num;
				fast_sort(arr, head, i);
				fast_sort(arr, i+1, tail);
		}
}

int main(){
		int arr[10] = {3,9,4,5,8,7,6,2,1,0};
		fast_sort(arr, 0, 9);
		for (int i = 0; i < 10; i++){
			printf(" %d ",arr[i]);
		}
		printf("\n");
}
