#include <stdio.h>

#define length 30

int heap[30];

int size;

int get_index(int data){
		for(int i = 0; i < size; i++){
				if (heap[i] == data){
						return i;
				}
		}
		return -1;
}

void heap_filterdown(int start, int end){
		int current = start;
		int left = 2*current + 1;
		int tmp = heap[current];
		while(left <= end){
				if (left < end && heap[left] < heap[left+1]){
						left++;
				}
				if (heap[left] < tmp){
						break;
				} else {
						heap[current] = heap[left];
						current = left;
						left = 2*left +1;
				}
		}
		heap[left] = tmp;
}

int heap_delete(int data){
		if (size == 0){
				return -1;
		}
		int index = get_index(data);
		if (index == -1){
				return -1;
		}
		heap[index] = heap[size-1];
		heap_filterdown(index, size-1);
		return 0;
}

void heap_filterup(int start){
		int current = start;
		int parent = (current-1)/2;
		int tmp = heap[current];
		while(current > 0){
				if (heap[parent] > tmp){
						break;
				} else {
						heap[current] = heap[parent];
						current = parent;
						parent = (parent - 1)/2;
				}
		}
		heap[current] = tmp;
}

int heap_insert(int data){
		if (size == length){
				return -1;//堆已满
		}
		heap[size] = data;
		heap_filterup(size);
		size++;
		return 0;
}

int main(){
		int arr[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
		for(int i = 0; i < 9; i++){
				printf(" %d ",arr[i]);
		}
		printf(" ----> 原始数据\n");
		for (int i = 0; i < 9; i++){
				heap_insert(arr[i]);
		}
		for(int i = 0; i < 9; i++){
				printf(" %d ",heap[i]);
		}
		printf(" ----> 堆中的数据\n");
		heap_insert(85);
		for(int i = 0; i < 10; i++){
				printf(" %d ",heap[i]);
		}
		printf(" ----> 堆中添加85后的数据\n");
		heap_delete(85);
		for(int i = 0; i < 9; i++){
				printf(" %d ",heap[i]);
		}
		printf(" ----> 堆中删除85后的数据\n");
}
