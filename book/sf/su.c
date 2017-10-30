#include <stdio.h>

#define N 10000

int main(){
    int arr[N];
    for (int i = 2; i < N; i++) {
        arr[i] = 1;
    }
    for (int i = 2; i < N; i++) {
//        if (arr[i] == 1) {
            for (int j = i; j * i < N; j++) {
                arr[i * j] = 0;       
            }
  //      }
    }
    for (int i = 2; i < N; i++) {
        if (arr[i] == 1) {
            printf(" %d ", i);
        }
    }
    printf("\n");
    return 0;
}
