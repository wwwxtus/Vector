#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

//first_full_commit
Vector createVector(int n) {
    if (n >= 1000000000) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (Vector) {
            NULL,
            0,
            n
    };
}

Vector getVectorFromArray(const int * const a, int size) {
    Vector v;
    v.data = (int*)malloc(sizeof(int)*size);
    memcpy(v.data, a, sizeof(int) * size);
    v.size = size;
    v.capacity = size;
    return v;
}

void reserve(Vector *v, int newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    }

    v->capacity = newCapacity;
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->capacity = v->size;
}

void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(Vector *v) {
    return v->size == 0 ? true : false;
}

bool isFull(Vector *v) {
    return v->size == v->capacity ? true : false;
}

int getVectorValue(Vector *v, int i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (v->size == v->capacity) {
        reserve(v, v->capacity * 2);
    }

    v->data[v -> size] = x;

    v->size += 1;
}

void popBack(Vector *v) {
    assert(v->size != 0);
    int el = v->data[v->size - 1];
    v->size--;
}