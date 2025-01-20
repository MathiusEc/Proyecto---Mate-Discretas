#include <stdio.h>
#include <math.h>
#include <string.h>

// Función para imprimir un encabezado de tabla
void imprimirEncabezado(int numVars) {
    for (int i = 0; i < numVars; i++) {
        printf("A%d\t", i + 1);
    }
    printf("S\n");
    printf("---------------------------------\n");
}

// Función para generar la tabla de verdad
void generarTablaVerdad(int numVars, int tabla[][numVars + 1]) {
    int totalFilas = pow(2, numVars);

    for (int i = 0; i < totalFilas; i++) {
        for (int j = 0; j < numVars; j++) {
            tabla[i][j] = (i >> (numVars - j - 1)) & 1;
        }
    }
}

// Función para imprimir la tabla de verdad con las salidas
void imprimirTabla(int numVars, int tabla[][numVars + 1], int totalFilas) {
    imprimirEncabezado(numVars);
    for (int i = 0; i < totalFilas; i++) {
        for (int j = 0; j <= numVars; j++) {
            printf("%d\t", tabla[i][j]);
        }
        printf("\n");
    }
}

// Construir la expresión SOP (Sum of Products)
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado) {
    int primeraSuma = 1;
    for (int i = 0; i < totalFilas; i++) {
        if (tabla[i][numVars] == 1) { // Salida es 1
            if (!primeraSuma) {
                strcat(resultado, " + ");
            }
            strcat(resultado, "(");

            for (int j = 0; j < numVars; j++) {
                if (tabla[i][j] == 1) {
                    char var[5];
                    sprintf(var, "A%d", j + 1);
                    strcat(resultado, var);
                } else {
                    char var[7];
                    sprintf(var, "NOT A%d", j + 1);
                    strcat(resultado, var);
                }

                if (j < numVars - 1) {
                    strcat(resultado, " AND ");
                }
            }

            strcat(resultado, ")");
            primeraSuma = 0;
        }
    }
}

int main() {
    int numVars;

    // Solicitar el número de variables booleanas (solo 2 o 3)
    do {
        printf("Ingrese el número de variables booleanas (solo 2 o 3): ");
        scanf("%d", &numVars);
        if (numVars != 2 && numVars != 3) {
            printf("Error: Solo se permite 2 o 3 variables.\n");
        }
    } while (numVars != 2 && numVars != 3);

    int totalFilas = pow(2, numVars);
    int tabla[totalFilas][numVars + 1]; // Última columna para las salidas

    // Generar la tabla de verdad
    generarTablaVerdad(numVars, tabla);

    // Solicitar las salidas del usuario
    printf("Ingrese las salidas (0 o 1) para cada fila:\n");
    for (int i = 0; i < totalFilas; i++) {
        imprimirEncabezado(numVars);
        for (int j = 0; j < numVars; j++) {
            printf("%d\t", tabla[i][j]);
        }
        do {
            printf("S: ");
            scanf("%d", &tabla[i][numVars]);
            if (tabla[i][numVars] != 0 && tabla[i][numVars] != 1) {
                printf("Error: Solo se permite 0 o 1.\n");
            }
        } while (tabla[i][numVars] != 0 && tabla[i][numVars] != 1);
    }

    // Construir la expresión SOP
    char resultado[1000] = "";
    construirSOP(numVars, tabla, totalFilas, resultado);

    // Presentar la tabla de verdad completa
    printf("\nTabla de verdad completa:\n");
    imprimirTabla(numVars, tabla, totalFilas);

    // Presentar la expresión booleana final
    printf("\nLa expresión booleana generada es:\n");
    printf("%s\n", resultado);

    return 0;
}
