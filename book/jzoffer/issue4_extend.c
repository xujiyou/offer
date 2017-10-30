#include <stdio.h>

void arr_hebing(int arrA[], int arrB[]){
		int i = 0;
		while(arrA[i] != 0)
				i++;
		int j = 0;
		while(arrB[j] != 0)
				j++;
		int length = i + j;
		while (i > 0 && j > 0){
				if (arrA[i-1] > arrB[j-1]){
						arrA[length-1] = arrB[j-1];
						length--;
						j--;
				} else {
						arrA[length-1] = arrA[i-1];
						length--;
						i--;
				}
		}
		while(i > 0){
				arrA[length-1] = arrA[i-1];
				length--;
				i--;
		}
		while(j > 0){
				arrA[length-1] = arrB[j-1];
				length--;
				j--;
		}
}

int main(){
		int arrA[50] = {10,7,5,2,1,0};
		int arrB[6] = {15,14,13,8,3,0};
		arr_hebing(arrA, arrB);
		for (int i = 0; i < 15; i++){
				printf(" %d ",arrA[i]);
		}
		printf("\n");
}
