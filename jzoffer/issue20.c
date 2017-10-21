#include <stdio.h>
#include <stdlib.h>

/*面试题20:顺时针打印矩阵*/

#define size 4

void traversal(int arr[size][size]){
		int first_begen = 0;
		int first_end = size - 1;
		int second_begen = 0;
		int second_end = size - 1;
		while (first_end >= first_begen || second_end >= second_begen){
				for (int i = second_begen; i <= second_end; i++) {
						printf(" %d ", arr[first_begen][i]);
				}	
				first_begen++;
				for (int i = first_begen; i <= first_end; i++) {
						printf(" %d ", arr[i][second_end]);
				}
				second_end--;
				for (int i = second_end; i >= second_begen; i--) {
						printf(" %d ", arr[first_end][i]);
				}
				first_end--;
				for(int i = first_end; i >= first_begen; i--) {
						printf(" %d ", arr[i][second_begen]);
				}
				second_begen++;
		}
}

int main(){
		int arr[size][size] = { {1,2,3,4}, {6,7,8,9}, {11,12,13,14}, {16,17,18,19}};
		traversal(arr);
		printf("\n");
}
