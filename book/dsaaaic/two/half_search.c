#include <stdio.h>
#include <stdlib.h>

int half_search(int *arr, int key, int len){
    int head = 0, tail = len - 1, mid = 0;
    while (head <= tail) {
        if (key == arr[head]) {
            return head;
        }
        if (key == arr[tail]) {
            return tail;
        }
        mid = (head + tail) / 2;
        if (key < arr[mid]) {
            tail = mid;
        } else if (key > arr[mid]) {
            head = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf(" %d \n", half_search(arr, 10, len));
}
