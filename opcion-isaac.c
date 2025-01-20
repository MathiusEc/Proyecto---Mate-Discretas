#include <stdio.h>
#include <math.h>
#include <string.h>
#include ".\Librerias\Colores_Terminal.h"
#include ".\Librerias\Funcion-forma-canonica.h"

// Prototipo de la función que construirá la expresión SOP (Suma de Productos).
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado);

int main() {
    int variables; // Declarar el número de variables booleanas.

    // Solicitar al usuario el número de variables booleanas (solo 2 o 3).
    do {
        printf("\nPor favor, ingrese la cantidad de variables que desea usar (solo 2 o 3): ");
        scanf("%d", &variables);
        if (variables < 2 || variables > 3) {
            printf(RED "Error: Ingrese una opción válida\n" RESET);
        }
    } while (variables < 2 || variables > 3);

    int filas = 1 << variables; // Total de filas en la tabla de verdad (2^variables).
    int tabla[filas][variables + 1]; // Declarar la tabla de verdad.
    char resultado[1024] = ""; // Cadena para almacenar la expresión SOP.

    // Generar la tabla de verdad.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            tabla[i][j] = (i >> (variables - j - 1)) & 1; // Generar valores binarios.
        }
    }

    // Solicitar los valores de salida (0 o 1) para cada fila.
    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf("%d", &tabla[i][variables]);
            if (tabla[i][variables] != 0 && tabla[i][variables] != 1) {
                printf(RED "Error: Solo puede ingresar 0 o 1.\n" RESET);
            }
        } while (tabla[i][variables] != 0 && tabla[i][variables] != 1);
    }

    // Construir la expresión SOP.
    construirSOP(variables, tabla, filas, resultado);

    // Generar la tabla de verdad específica de la forma canónica.
    printf("\n===============================================\n");
    printf("TABLA DE VERDAD (RESOLUCIÓN EN BINARIO)\n");
    printf("===============================================\n");

    // Imprimir encabezados de las columnas.
    for (int i = 0; i < variables; i++) {
        printf(" %c ", 'A' + i);
    }
    printf("|   A’*B    +    B’*A   | Resultado\n");

    // Generar las resoluciones parciales y resultados finales.
    for (int i = 0; i < filas; i++) {
        if (tabla[i][variables] == 1) { // Solo se evalúan las filas relevantes para la SOP.
            // Imprimir las combinaciones de entrada.
            for (int j = 0; j < variables; j++) {
                printf(" %d ", tabla[i][j]);
            }

            // Calcular y mostrar los valores parciales de la SOP.
            int term1 = (!tabla[i][0] && tabla[i][1]); // A’*B
            int term2 = (tabla[i][0] && !tabla[i][1]); // B’*A

            printf("| " GREEN "%d %d %d" RESET "    +    " GREEN "%d %d %d" RESET " | ", 
                   !tabla[i][0], tabla[i][1], term1, 
                   tabla[i][0], !tabla[i][1], term2);

            // Resultado final en rojo.
            printf(RED "%d\n" RESET, term1 || term2);
        }
    }

    // Mostrar la expresión final completa.
    printf("\n=================================\n");
    printf("EXPRESIÓN SOP FINAL\n");
    printf("=================================\n");
    printf(RED "Expresión SOP: %s\n" RESET, resultado);

    return 0;
}
