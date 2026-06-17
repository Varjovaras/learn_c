#include "vec.h"
#include <stdio.h>
#include <time.h>

void fibo(void);
double elapsed_(struct timespec start, struct timespec now);

vec fibNums = {0};
int firstTwo[] = {0, 1};

int main(void) {
  struct timespec start, now;
  clock_gettime(CLOCK_MONOTONIC, &start);
  intvec_push_many(&fibNums, firstTwo, 2);

  long count = 0;

  while (1) {
    clock_gettime(CLOCK_MONOTONIC, &now);
    double elapsed =
        (now.tv_sec - start.tv_sec) + (now.tv_nsec - start.tv_nsec) / 1e9;
    if (elapsed >= 1.0)
      break;

    fibo();
    count++;
  }

  print_last(&fibNums);
  printf("Ran %ld times in 1 second\n", count);
}

void fibo(void) {
  intvec_push(&fibNums,
              fibNums.data[fibNums.len - 1] + fibNums.data[fibNums.len - 2]);
}
