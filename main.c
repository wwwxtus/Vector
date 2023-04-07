#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    Vector v = createVector(5);

    reserve(&v, 0);

    printf("%d %d", v.capacity, v.data);

    return 0;
}
