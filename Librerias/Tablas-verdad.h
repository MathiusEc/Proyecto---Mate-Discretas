#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include ".\Colores_Terminal.h"

// Función para evaluar cada término de la expresión SOP
int evaluarTermino(int variables[], const char *termino) {
    int resultado = 1;
    const char *ptr = termino;

    while (*ptr != '\0') {
        if (*(ptr + 1) == '\'') { // Negación (ejemplo: A')
            int varIndex = *ptr - 'A';
            resultado &= !variables[varIndex];
            ptr += 2;
        } else if (*ptr >= 'A' && *ptr <= 'Z') { // Variable normal (ejemplo: A)
            int varIndex = *ptr - 'A';
            resultado &= variables[varIndex];
            ptr++;
        } else if (*ptr == '*') { // Operador AND ('*')
            ptr++;
        } else {
            ptr++;
        }
    }

    return resultado;
}

// Función para generar la tabla de verdad
void generarTablaDeVerdad(int variables, int filas, int tabla[][variables + 1]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            tabla[i][j] = (i >> (variables - j - 1)) & 1;
        }
    }
}

// Función para imprimir la tabla de verdad con resultados parciales y colores
void imprimirTablaConResultadosParciales(int variables, int filas, int tabla[][variables + 1], const char *expresionSOP) {
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

    // Imprimir encabezado de la tabla
    printf("\nTabla de Verdad con Resultados Parciales:\n");
    for (int i = 0; i < variables; i++) {
        printf("%c   ", 'A' + i);
    }
    for (int i = 0; i < numTerminos; i++) {
        printf("%s   ", terminos[i]);
    }
    printf(RED "S\n" RESET);
    printf("----------------------------------------------------\n");

    // Generar la tabla con resultados parciales
    for (int i = 0; i < filas; i++) {
        int entradas[variables];
        for (int j = 0; j < variables; j++) {
            entradas[j] = tabla[i][j];
            printf("%d   ", entradas[j]);
        }

        int salidaFinal = 0;
        for (int j = 0; j < numTerminos; j++) {
            int resultadoParcial = evaluarTermino(entradas, terminos[j]);
            salidaFinal |= resultadoParcial;
            printf(GREEN "%d     " RESET, resultadoParcial);
        }
        printf(RED "%d\n" RESET, salidaFinal);
    }
}