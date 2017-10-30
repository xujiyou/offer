#include <stdio.h>
#include <malloc.h>

void gai(int &ptr){
		int *b = (int *)malloc(2*sizeof(int));
		b[0] = b[1] = 2;
		ptr = *b;
		printf(" %X ",ptr);

}

int main(){
		int *a = (int *)malloc(2*sizeof(int));
		a[0] = a[1] = 1;
		int *ptr = a;
		printf("%X ", ptr);
		gai(*ptr);		

		printf("%X ", ptr);
		printf("\n");
}
