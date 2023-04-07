#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    Vector v = createVector(5);

    shrinkToFit(&v);

    printf("%d", v.capacity);

    return 0;
}
