#include <stdio.h>
#include <math.h>
void generateSOP(int numVars, int truthTable[][3], int output[]) {
    int rows = pow(2, numVars);
    int first = 1;

    printf("Expresión SOP (Forma Canónica): ");
    for (int i = 0; i < rows; i++) {
        if (output[i] == 1) {
            if (!first) {
                printf(" OR ");
            }
            printf("(");
            for (int j = 0; j < numVars; j++) {
                if (j > 0) {
                    printf(" AND ");
                }
                if (truthTable[i][j] == 1) {
                    printf("%c", 'A' + j);
                } else {
                    printf("NOT %c", 'A' + j);
                }
            }
            printf(")");
            first = 0;
        }
    }
    printf("\n");
}