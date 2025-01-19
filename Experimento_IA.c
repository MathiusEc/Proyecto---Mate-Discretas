#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 3
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int getNumVariables() {
    int num;
    do {
        printf("Digite el número de variables lógicas, solo 2 o 3: ");
        scanf("%d", &num);
        if (num != 2 && num != 3) {
            printf("Error: Solo se permite 2 o 3 variables.\n");
        }
    } while (num != 2 && num != 3);
    return num;
}

void inputTruthTable(int numVars, int truthTable[]) {
    int rows = 1 << numVars;
    printf("Ingrese los valores de salida, 0 o 1 para cada fila de la tabla de verdad:\n");
    printf("A     B");
    if (numVars == 3) printf("    C");
    printf("    S\n");
    printf("-------------------\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < numVars; j++) {
            printf("[%d] ", (i >> (numVars - 1 - j)) & 1);
        }
        int value;
        do {
            scanf("%d", &value);
            if (value != 0 && value != 1) {
                printf("Error: Solo se permite 0 o 1. Intente de nuevo: ");
            }
        } while (value != 0 && value != 1);
        truthTable[i] = value;
    }
}

void generateBooleanExpression(int numVars, int truthTable[]) {
    int rows = 1 << numVars;
    printf("La expresión booleana generada es: ");
    int first = 1;
    for (int i = 0; i < rows; i++) {
        if (truthTable[i]) {
            if (!first) printf(" + ");
            first = 0;
            for (int j = 0; j < numVars; j++) {
                if ((i >> (numVars - 1 - j)) & 1) {
                    printf("%c", 'A' + j);
                } else {
                    printf("%c'", 'A' + j);
                }
            }
        }
    }
    printf("\n\n");
}

void generateTruthTable(int numVars, int truthTable[]) {
    int rows = 1 << numVars;
    printf("Tabla de verdad de la expresión generada\n\n");
    
    // Print header
    for (int i = 0; i < numVars; i++) {
        printf("%c  ", 'A' + i);
    }
    for (int i = 0; i < numVars; i++) {
        printf("%c' ", 'A' + i);
    }
    printf("| ");
    for (int i = 0; i < numVars; i++) {
        for (int j = 0; j < numVars; j++) {
            if (i == j) continue;
            printf("%c'*%c ", 'A' + i, 'A' + j);
        }
    }
    printf("| Result\n");
    
    // Print separator
    for (int i = 0; i < numVars * 3 + numVars * 3 + 2 + numVars * (numVars - 1) * 5 + 8; i++) {
        printf("-");
    }
    printf("\n");
    
    // Print truth table rows
    for (int i = 0; i < rows; i++) {
        // Original variables
        for (int j = 0; j < numVars; j++) {
            printf("%d  ", (i >> (numVars - 1 - j)) & 1);
        }
        
        // Complemented variables
        for (int j = 0; j < numVars; j++) {
            printf("%d  ", !((i >> (numVars - 1 - j)) & 1));
        }
        
        printf("| ");
        
        // Partial results
        for (int j = 0; j < numVars; j++) {
            for (int k = 0; k < numVars; k++) {
                if (j == k) continue;
                int result = (!((i >> (numVars - 1 - j)) & 1)) && ((i >> (numVars - 1 - k)) & 1);
                printf(GREEN "%d    " RESET, result);
            }
        }
        
        // Final result
        printf("| ");
        printf(RED "%d" RESET, truthTable[i]);
        printf("\n");
    }
}

int main() {
    int numVars = getNumVariables();
    int truthTable[1 << MAX_VARS];
    
    inputTruthTable(numVars, truthTable);
    generateBooleanExpression(numVars, truthTable);
    generateTruthTable(numVars, truthTable);
    
    return 0;
}