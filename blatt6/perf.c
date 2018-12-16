#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct timespec timespec_t;

void capture_time(timespec_t *t1) {
    clock_gettime(CLOCK_MONOTONIC, t1);
}

timespec_t time_diff (const timespec_t end, const timespec_t start) {
    timespec_t diff;
    if (end.tv_nsec < start.tv_nsec) {
        diff.tv_sec = end.tv_sec - start.tv_sec - 1;
        diff.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        diff.tv_sec = end.tv_sec - start.tv_sec;
        diff.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return diff;
}

double time_to_double (const timespec_t t) {
    double d = (double)t.tv_nsec;
    d /= 1000000000.0;
    d += (double)t.tv_sec;
    return d;
}

//Ohne Anweisungen zwischen den Time Anweisungen
double noStatement() {

  double secs = 0.0;
  for(int i=0; i<10000; i++) {
    timespec_t t0, t1;
    capture_time(&t0);
    capture_time(&t1);
    secs += time_to_double(time_diff(t1, t0));
  }
  return secs/10000;

}

double arrayStack(int sizeArray) {

  double secs = 0.0;
  for(int i=0; i<10000; i++) {
    timespec_t t0, t1;
    capture_time(&t0);

    int array[sizeArray];

    capture_time(&t1);
    secs += time_to_double(time_diff(t1, t0));
  }
  return secs/10000;

}

//Malloc
double arrayHeapMalloc(int sizeArray) {

  double secs = 0.0;
  for(int i=0; i<10000; i++) {
    timespec_t t0, t1;
    capture_time(&t0);

    int *array = malloc(sizeArray * sizeof(int));
    free(array);

    capture_time(&t1);
    secs += time_to_double(time_diff(t1, t0));
  }
  return secs/10000;

}

//Calloc
double arrayHeapCalloc(int sizeArray) {

  double secs = 0.0;
  for(int i=0; i<10000; i++) {
    timespec_t t0, t1;
    capture_time(&t0);

    int *array = calloc(sizeArray, sizeof(int));
    free(array);

    capture_time(&t1);
    secs += time_to_double(time_diff(t1, t0));
  }
  return secs/10000;

}

int main(int argc, char** args) {

  //No Statement
  double result = noStatement();
  printf("duration: no statement: %0.10f \n", result);

  printf("------------------------------------\n");

  //Array Stack
  result = arrayStack(100);
  printf("duration: Array Stack 100: %0.10f \n", result);

  result = arrayStack(1000);
  printf("duration: Array Stack 1000: %0.10f \n", result);

  result = arrayStack(10000);
  printf("duration: Array Stack 10000: %0.10f \n", result);

  result = arrayStack(100000);
  printf("duration: Array Stack 1000000: %0.10f \n", result);

  printf("------------------------------------\n");

  //Array Heap Malloc
  result = arrayHeapMalloc(100);
  printf("duration: Array Heap Malloc 100: %0.10f \n", result);

  result = arrayHeapMalloc(1000);
  printf("duration: Array Heap Malloc 1000: %0.10f \n", result);

  result = arrayHeapMalloc(10000);
  printf("duration: Array Heap Malloc 10000: %0.10f \n", result);

  result = arrayHeapMalloc(100000);
  printf("duration: Array Heap Malloc 1000000: %0.10f \n", result);

  printf("------------------------------------\n");

  //Array Heap Calloc
  result = arrayHeapCalloc(100);
  printf("duration: Array Heap Calloc 100: %0.10f \n", result);

  result = arrayHeapCalloc(1000);
  printf("duration: Array Heap Calloc 1000: %0.10f \n", result);

  result = arrayHeapCalloc(10000);
  printf("duration: Array Heap Calloc 10000: %0.10f \n", result);

  result = arrayHeapCalloc(100000);
  printf("duration: Array Heap Calloc 1000000: %0.10f \n", result);


	return 0;
}
