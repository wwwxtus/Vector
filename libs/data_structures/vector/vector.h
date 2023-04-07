#ifndef VECTORC_VECTOR_H
#define VECTORC_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    int size; // размер вектора
    int capacity; // вместимость вектора
} Vector;

Vector createVector(int n);
void reserve(Vector *v, int newCapacity);
void clear(Vector *v);

#endif //VECTORC_VECTOR_H
