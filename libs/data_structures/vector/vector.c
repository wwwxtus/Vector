#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

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