#include <stdio.h>

#define length 10

/*
 *希尔排序(Shell Sort)是插入排序的一种，它是针对直接插入排序算法的改进。该方法又称缩小增量排序，因DL．Shell于1959年提出而得名。

 希尔排序实质上是一种分组插入方法。它的基本思想是：对于n个待排序的数列，取一个小于n的整数gap(gap被称为步长)将待排序元素分成若干个组子序列，所有距离为gap的倍数的记录放在同一个组中；然后，对各组内的元素进行直接插入排序。 这一趟排序完成之后，每一个组的元素都是有序的。然后减小gap的值，并重复执行上述的分组和排序。重复这样的操作，当gap=1时，整个数列就是有序的。
 希尔排序的时间复杂度与增量(即，步长gap)的选取有关。例如，当增量为1时，希尔排序退化成了直接插入排序，此时的时间复杂度为O(N²)，而Hibbard增量的希尔排序的时间复杂度为O(N3/2)。
 * */

void xier_sort(int arr[], int n){
		for (int gap = n/2; gap > 0; gap /= 2){
				for(int i = 0; i < gap; i++){
						//插入排序
						for(int j = i + gap; j < n; j += gap){
								int tag;
								for (tag = i; tag < j; tag += gap){
										if (arr[tag] < arr[j]){
												break;
										}
								}
								int temp = arr[j];
								for (int k = j; k > tag; k -= gap){
										arr[k] = arr[k-gap];
								}
								arr[tag] = temp;
						}
				}
		}
}

int main(){
		int arr[length] = {10,20,30,40,50,60,70,80,90,100};
		xier_sort(arr, length);
		for(int i = 0; i < length; i++){
				printf(" %d ",arr[i]);
		}
		printf("\n");
}
