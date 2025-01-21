#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos colores para la terminal
#define GREEN   "\x1B[32m"
#define RED     "\x1B[31m"
#define RESET   "\x1B[0m"

// Función para evaluar cada término de la expresión SOP
int evaluarTermino(int variables[], const char *termino) {
    int resultado = 1; // Inicialmente asumimos que el término es verdadero
    const char *ptr = termino;

    while (*ptr != '\0') {
        if (strncmp(ptr, "NOT A", 5) == 0) {
            int varIndex = ptr[5] - '1'; // Obtener el índice de la variable (A1 -> 0, A2 -> 1, etc.)
            resultado &= !variables[varIndex];
            ptr += 6; // Avanzar después de "NOT A1"
        } else if (strncmp(ptr, "A", 1) == 0) {
            int varIndex = ptr[1] - '1'; // Obtener el índice de la variable (A1 -> 0, A2 -> 1, etc.)
            resultado &= variables[varIndex];
            ptr += 2; // Avanzar después de "A1"
        } else if (strncmp(ptr, " AND ", 5) == 0) {
            ptr += 5; // Saltar el operador "AND"
        } else {
            ptr++; // Avanzar al siguiente carácter
        }
    }
    return resultado;
}

// Función para evaluar la expresión SOP y generar la tabla
void generarTablaConResultadosParciales(int variables, int filas, const char *expresionSOP) {
    int entradas[variables]; // Arreglo para las combinaciones de entrada
    char expresion[1024];    // Copiamos la expresión SOP porque la modificaremos
    strcpy(expresion, expresionSOP);

    // Dividimos la expresión SOP en términos individuales
    char *terminos[1024];
    int numTerminos = 0;
    char *token = strtok(expresion, "+");
    while (token != NULL) {
        terminos[numTerminos++] = token;
        token = strtok(NULL, "+");
    }

    // Imprimimos el encabezado de la tabla
    printf("\nTabla de Verdad con Resultados Parciales:\n");
    for (int i = 0; i < variables; i++) {
        printf("A%d   ", i + 1);
    }
    for (int i = 0; i < numTerminos; i++) {
        printf("%s   ", terminos[i]);
    }
    printf(RED "S\n" RESET);
    printf("------------------------------------------\n");

    // Generamos la tabla
    for (int i = 0; i < filas; i++) {
        // Generamos los valores binarios para las entradas
        for (int j = variables - 1; j >= 0; j--) {
            entradas[j] = (i >> j) & 1;
            printf("%d     ", entradas[j]);
        }

        int resultadosParciales[numTerminos];
        int salidaFinal = 0;

        // Evaluamos cada término
        for (int j = 0; j < numTerminos; j++) {
            resultadosParciales[j] = evaluarTermino(entradas, terminos[j]);
            salidaFinal |= resultadosParciales[j];
            printf(GREEN "%d     " RESET, resultadosParciales[j]);
        }

        // Imprimimos el resultado final en rojo
        printf(RED "%d\n" RESET, salidaFinal);
    }
}

// Función para construir la expresión SOP (Sum of Products)
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
    int variables;

    // Solicitar el número de variables (solo 2 o 3)
    do {
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if (variables < 2 || variables > 3) {
            printf(RED "Error: ingrese una opción válida\n" RESET);
        }
    } while (variables < 2 || variables > 3);

    // Determinación del número de filas según las variables (2^n)
    int filas = 1 << variables; // 2^variables
    int tabla[filas][variables + 1]; // Tabla de verdad completa

    // Llenar la tabla de verdad con los valores de entrada
    for (int i = 0; i < filas; i++) {
        for (int j = variables - 1; j >= 0; j--) {
            tabla[i][j] = (i >> j) & 1;
        }
    }

    // Solicitar los valores de salida (S)
    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf(" %d", &tabla[i][variables]);
            if (tabla[i][variables] != 0 && tabla[i][variables] != 1) {
                printf(RED "Error: Solo puede ingresar 0 o 1.\n" RESET);
            }
        } while (tabla[i][variables] != 0 && tabla[i][variables] != 1);
    }

    // Construcción de la expresión SOP
    char expresionSOP[1024] = "";
    construirSOP(variables, tabla, filas, expresionSOP);

    // Mostrar la expresión SOP
    printf("\nLa expresión SOP generada es: %s\n", expresionSOP);

    // Generar la tabla de verdad con resultados parciales
    generarTablaConResultadosParciales(variables, filas, expresionSOP);

    return 0;
}
