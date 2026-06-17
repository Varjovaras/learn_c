#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *data;
  int len;
  int cap;
} vec;

void intvec_push(vec *v, int val) {
  if (v->len == v->cap) {
    v->cap = v->cap == 0 ? 4 : v->cap * 2;
    v->data = realloc(v->data, v->cap * sizeof(int));
  }
  v->data[v->len++] = val;
}

void free_vec(vec *v) {
  free(v->data);
  v->len = v->cap = 0;
}

void intvec_push_many(vec *v, int *vals, int n) {
  // grow once to fit all new elements
  if (v->len + n > v->cap) {
    while (v->cap < v->len + n)
      v->cap = v->cap == 0 ? 4 : v->cap * 2;
    v->data = realloc(v->data, v->cap * sizeof(int));
  }
  memcpy(v->data + v->len, vals, n * sizeof(int));
  v->len += n;
}

vec intvec_from(int *vals, int n) {
  vec v = {0};
  intvec_push_many(&v, vals, n);
  return v;
}

void intvec_print(vec *v) {
  printf("[");
  for (int i = 0; i < v->len; i++) {
    printf("%d", v->data[i]);
    if (i < v->len - 1)
      printf(", ");
  }
  printf("]\n");
}

void print_last(vec *v) {
    printf("last one :D\n");
    int last = v->data[v->len - 1];
    printf("%d\n", last);
}
