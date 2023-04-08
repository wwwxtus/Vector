#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

//first_full_commit
Vector createVector(int n) {
    Vector v;
    v.data = malloc(sizeof(int) * n);
    if (!v.data) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (Vector) {
            v.data,
            0,
            n
    };
}

Vector getVectorFromArray(const int *const a, int size) {
    Vector v;
    v.data = (int *) malloc(sizeof(int) * size);
    memcpy(v.data, a, sizeof(int) * size);
    v.size = size;
    v.capacity = size;
    return v;
}

void reserve(Vector *v, int newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }

    v->data = realloc(v->data, newCapacity * sizeof(int));
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->data = realloc(v->data, v->size * sizeof(int));
}

void deleteVector(Vector *v) {
    free(v->data);
}

//two_full_commit
bool isEmpty(Vector *v) {
    return v->size == 0 ? true : false;
}

bool isFull(Vector *v) {
    return (v->size == v->capacity) && (v->size != 0) ? true : false;
}

int getVectorValue(Vector *v, int i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }

    if (v->size == 0 && v->capacity == 0) {
        v->capacity++;
    }

    v->data[v->size++] = x;
}

void popBack(Vector *v) {
    assert(v->size != 0);
    v->size--;
}

//three_full_commit
int *atVector(Vector *v, int index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return &v->data[index];
}

int *back(Vector *v) {
    return &v->data[v->size - 1];
}

int *front(Vector *v) {
    return &v->data[0];
}