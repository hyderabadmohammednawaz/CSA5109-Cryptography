#include <stdio.h>
#include <math.h>

/* Playfair uses a 5x5 matrix. A key is a permutation of 25 symbols.
   This program counts all possible keyed squares, ignoring equivalent
   encryption results as requested in the first part. */
int main(void) {
    double keys = 1.0;
    int i;
    for (i = 1; i <= 25; ++i) keys *= i;
    printf("25! = %.0f\n", keys);
    printf("Approximate power of 2 = 2^%.2f\n", log(keys) / log(2.0));
    printf("Part (a): about 2^83.68 possible keyed squares.\n");
    printf("Part (b): equivalent Playfair keys reduce the effective count;\n");
    printf("the exact equivalence depends on the convention used for the key square.\n");
    return 0;
}
