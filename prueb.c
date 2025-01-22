#include ".\Librerias\Colores_Terminal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Función para evaluar cada término de la expresión SOP
int evaluarTermino(int variables[], const char *termino) {
    int resultado = 1;

    const char *ptr = termino; // Apuntamos al inicio de la cadena término

    while (*ptr != '\0') {
        if (*(ptr + 1) == '\'') { // Si encontramos A', es una negación
            int varIndex = *ptr - 'A'; // Convertimos 'A', 'B', 'C' a índices (0, 1, 2, ...)
            resultado &= !variables[varIndex]; // Evaluamos la negación de la variable
            ptr += 2; // Avanzamos al siguiente carácter después de la negación
        } else if (*ptr >= 'A' && *ptr <= 'Z') { // Si es una variable normal (A, B, C)
            int varIndex = *ptr - 'A'; // Convertimos 'A', 'B', 'C' a índices (0, 1, 2, ...)
            resultado &= variables[varIndex]; // Evaluamos la variable
            ptr++; // Avanzamos al siguiente carácter
        } else if (*ptr == '*') { // Si encontramos el operador AND ('*')
            ptr++; // Saltamos el operador
        } else {
            ptr++; // Avanzamos al siguiente carácter
        }
    }

    return resultado;
}

// Función para evaluar la expresión SOP y generar la tabla
void generarTablaConResultadosParciales(int variables, int filas, const char *expresionSOP, int *valoresS) {
    // Arreglo para las combinaciones de entrada
    int entradas[variables];

    // Copiamos la expresión SOP porque la modificaremos
    char expresion[1024];
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
        printf("%c   ", 'A' + i); // Imprimimos las variables A, B, C...
    }
    for (int i = 0; i < numTerminos; i++) {
        printf("%s   ", terminos[i]); // Imprimimos los términos individuales
    }
    printf(RED "S\n" RESET);
    printf("------------------------------------------\n");

    // Generamos la tabla
    for (int i = 0; i < filas; i++) {
        // Generamos los valores binarios para las entradas
        for (int j = variables - 1; j >= 0; j--) {
            entradas[j] = (i >> j) & 1;
            printf("%d   ", entradas[j]);
        }

        int resultadosParciales[numTerminos];
        int salidaFinal = 0;

        // Evaluamos cada término de la expresión SOP
        for (int j = 0; j < numTerminos; j++) {
            resultadosParciales[j] = evaluarTermino(entradas, terminos[j]);
            salidaFinal |= resultadosParciales[j];
            printf(GREEN "%d   " RESET, resultadosParciales[j]);
        }

        // Usamos el valor real de salida (S) ingresado por el usuario
        printf(RED "%d\n" RESET, valoresS[i]);
    }
}

// Función principal para probar
int main() {
    int variables;
    do {
        printf("\nPor favor, ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if (variables < 2 || variables > 3) {
            printf(RED "Error: ingrese una opción válida\n" RESET);
        }
    } while (variables < 2 || variables > 3);

    int filas = 1 << variables; // 2^variables
    int tabla[filas];

    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf(" %d", &tabla[i]);
            if (tabla[i] != 0 && tabla[i] != 1) {
                printf(RED "Error: Solo puede ingresar 0 o 1.\n" RESET);
            }
        } while (tabla[i] != 0 && tabla[i] != 1);
    }

    // Generar la expresión SOP
    char expresionSOP[1024] = "";
    int primeraSuma = 1;
    for (int i = 0; i < filas; i++) {
        if (tabla[i] == 1) {
            if (!primeraSuma) {
                strcat(expresionSOP, "+");
            }
            strcat(expresionSOP, "(");
            for (int j = 0; j < variables; j++) {
                if (((i >> (variables - j - 1)) & 1) == 1) {
                    char var[5];
                    sprintf(var, "%c", 'A' + j);
                    strcat(expresionSOP, var);
                } else {
                    char var[5];
                    sprintf(var, "%c'", 'A' + j);
                    strcat(expresionSOP, var);
                }
                if (j < variables - 1) {
                    strcat(expresionSOP, "*");
                }
            }
            strcat(expresionSOP, ")");
            primeraSuma = 0;
        }
    }

    // Mostrar la expresión SOP
    printf("\nExpresión SOP generada: %s\n", expresionSOP);

    // Generar la tabla de verdad con resultados parciales
    generarTablaConResultadosParciales(variables, filas, expresionSOP, tabla);

    return 0;
}
