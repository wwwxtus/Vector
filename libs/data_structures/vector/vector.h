#include <stdbool.h>

#ifndef VECTORC_VECTOR_H
#define VECTORC_VECTOR_H

//first_full_commit
typedef struct vector {
    int *data; // указатель на элементы вектора
    int size; // размер вектора
    int capacity; // вместимость вектора
} Vector;

Vector createVector(int n);
Vector getVectorFromArray(const int * const a, int size);
void reserve(Vector *v, int newCapacity);
void clear(Vector *v);
void shrinkToFit(Vector *v);
void deleteVector(Vector *v);

//two_full_commit
bool isEmpty(Vector *v);
bool isFull(Vector *v);

int getVectorValue(Vector *v, int i);
void pushBack(Vector *v, int x);
void popBack(Vector *v);

int* atVector(Vector *v, int index);
#endif //VECTORC_VECTOR_H
