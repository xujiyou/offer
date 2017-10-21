#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0

/*面试题14：把能被3整除的数放在数组前面，这是一类问题，考虑到可扩展性，写一个函数用于判断*/

int condition(int *arr, int n){
		if (arr[n] % 3 != 0 ) {
				return true;
		}
		return false;
}

void recombin(int *arr, int head, int tail){
		while (head < tail) {
				while (head < tail && condition(arr, tail)) {
						tail--;
				}
				while (head < tail && !condition(arr, head)) {
						head++;
				}
				if (head < tail){
						int temp = arr[head];
						arr[head] = arr[tail];
						arr[tail] = temp;

				}
				head++;
				tail--;
		}
}

int main(){
		int arr[10] = {1,2,-2,3,4,5,-6,7,-8,9};
		recombin(arr, 0, 9);
		for (int i = 0; i < 10; i++) {
				printf(" %d ", arr[i]);
		}
		printf("\n");
}
