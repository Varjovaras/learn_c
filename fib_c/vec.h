// vec.h
#ifndef VEC_H
#define VEC_H

#include <stdlib.h>

typedef struct {
    int *data;
    int len;
    int cap;
} vec;

void intvec_push(vec *v, int val);
int  intvec_pop(vec *v);
int  intvec_get(vec *v, int i);
void intvec_free(vec *v);
void intvec_push_many(vec *v, int *vals, int n);
vec intvec_from(int *vals, int n);
void intvec_print(vec *v);
void print_last(vec *v);

#endif
