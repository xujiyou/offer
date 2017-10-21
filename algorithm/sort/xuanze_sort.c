#include <stdio.h>

#define length 10

void xuanze_sort(int arr[], int n){
		int max;
		for(int i = 0 ; i < n; i++){
				max = i;
				for(int j = i; j < n; j++){
						if (arr[j] > arr[max]){
								max = j;
						}
				}
				if (max != i){
						int temp = arr[max];
						arr[max] = arr[i];
						arr[i] = temp;
				}
		}
}

int main(){
		int arr[length] = {1,2,3,4,5,60,7,8,9,0};
		xuanze_sort(arr,length);
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
