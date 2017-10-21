#include <stdio.h>
#include <stdlib.h>

#define length 10

void guibing(int arr[], int start, int end, int mid){
		int *temp = (int *)malloc((end-start+1)*sizeof(int));
		int i = start;		//数组上半部分的下标
		int j = mid + 1;	//数组下半部分的下标
		int k = 0;			//temp的下标
		while(i <= mid && j <= end){
				if (arr[i] < arr[j]){
						temp[k++] = arr[j++];
				} else {
						temp[k++] = arr[i++];
				}
		}
		while(i <= mid){
				temp[k++] = arr[i++];
		}
		while(j <= end){
				temp[k++] = arr[j++];
		}
		for (int i = 0; i < k; i++){
				arr[start+i] = temp[i];
		}
		free(temp);
}

void guibing_uptodown(int arr[], int start, int end){
		if (arr == NULL || end <= start){
				return;
		}
		int mid = (end+start)/2;
		guibing_uptodown(arr,start,mid);
		guibing_uptodown(arr,mid+1,end);
		guibing(arr,start,end,mid);
}

int main(){
		int arr[length] = {1,2,3,4,5,6,7,8,9,0};
		guibing_uptodown(arr,0,length-1);
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
