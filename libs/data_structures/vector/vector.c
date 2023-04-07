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