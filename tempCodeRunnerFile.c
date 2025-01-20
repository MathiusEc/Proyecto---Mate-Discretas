#include <stdio.h>
#include <math.h>

void generateTruthTable(int numVars, int truthTable[][3]) {
    int rows = pow(2, numVars);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < numVars; j++) {
            truthTable[i][j] = (i >> (numVars - 1 - j)) & 1;
        }
    }
}

void printTruthTable(int numVars, int truthTable[][3], int output[]) {
    int rows = pow(2, numVars);
    printf("Tabla de verdad completa:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < numVars; j++) {
            printf("%d ", truthTable[i][j]);
        }
        printf("| %d\n", output[i]);
    }
}

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

int main() {
    int numVars;
    printf("Ingrese el número de variables booleanas (2 o 3): ");
    scanf("%d", &numVars);

    if (numVars < 2 || numVars > 3) {
        printf("Número de variables no válido.\n");
        return 1;
    }

    int rows = pow(2, numVars);
    int truthTable[8][3];  // Máximo de 3 variables -> 2^3 = 8 filas
    int output[8];

    generateTruthTable(numVars, truthTable);

    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < numVars; j++) {
            printf("%d ", truthTable[i][j]);
        }
        printf("| ");
        scanf("%d", &output[i]);
    }

    printTruthTable(numVars, truthTable, output);
    generateSOP(numVars, truthTable, output);

    return 0;
}


// Comparalo con Experimento_IA.c