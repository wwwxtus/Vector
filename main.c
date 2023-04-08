#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include "libs/data_structures/vector/vector.h"

void outputVector(Vector v) {
    printf("[");
    for (int i = 0; i < v.size - 1; i++)
        printf("%d, ", v.data[i]);
    if (v.size != 0)
        printf("%d", v.data[v.size - 1]);
    printf("]");
}

void test_pushBack_emptyVector() {
    int a[] = {1,2,3};

    Vector v = getVectorFromArray(a, 6);

    pushBack(&v, 12);
    assert(v.data[6] == 12);
}

void test_pushBack_fullVector() {
    int a[] = {1,2,3,4,5,10};

    Vector v = getVectorFromArray(a, 6);

    pushBack(&v, 34);
    assert(v.data[6] == 34);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    int a[] = {0,1,2,3,4,5};

    Vector v = getVectorFromArray(a, 6);
    int *z = atVector(&v, 2);

    assert(*z == 2);
}

void test_atVector_requestToLastElement() {
    int a[] = {0,1,2,3,4,5};

    Vector v = getVectorFromArray(a, 6);
    int *z = atVector(&v, 7);

    assert(*z == 7);
}

void test_back_oneElementInVector() {
    int a[] = {10};

    Vector v = getVectorFromArray(a, 1);
    int *z = back(&v);

    assert(*z == 10);
}

void test_front_oneElementInVector() {
    int a[] = {10};

    Vector v = getVectorFromArray(a, 1);
    int *z = back(&v);

    assert(*z == 10);
}


void test2() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}
int main() {
    test2();

    return 0;
}
