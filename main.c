#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include "libs/data_structures/vector/vector.h"

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


int main() {
    test();

    return 0;
}
