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


int main() {
    test_popBack_notEmptyVector();

    return 0;
}
