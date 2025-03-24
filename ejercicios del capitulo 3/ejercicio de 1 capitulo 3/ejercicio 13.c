#include <stdio.h>

/* Fibonacci.
   El programa calcula y escribe los primeros 50 números de Fibonacci. */

int main(void) {
    int I, PRI = 0, SEG = 1, SIG;

    printf("%d\t%d", PRI, SEG);

    for (I = 3; I <= 50; I++) {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
        printf("\t%d", SIG);
    }

 printf("\n");


 }
