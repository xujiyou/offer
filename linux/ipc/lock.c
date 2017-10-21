#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include 

#define MAXNITERM 1000000
#define MAXNTHREADS 100

int nitems;

struct {
		pthread_mutex_t mutex;
		int buff[MAXNITERM];
		int nput;
		int nval;
} shared = {
		PTHREAD_MUTEX_INITIALIZER,{0},0,0,
};

void *produce(void *), *consume(void *);

int main(){
		nitems = 1000000;
		pthread_t tid_preduce[MAXNTHREADS]
}
