#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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