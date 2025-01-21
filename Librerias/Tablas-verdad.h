#include ".\Colores_Terminal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Función para evaluar cada término de la expresión SOP
int evaluarTermino(int variables[], const char *termino) {
    int resultado = 1; // Inicialmente asumimos que el término es verdadero

    const char *ptr = termino; // Apuntamos al inicio de la cadena término

    while (*ptr != '\0') { // Recorremos la cadena hasta el final
        if (ptr[1] == '\'') { // Verificamos si la variable está negada
            int varIndex = ptr[0] - 'A'; // Obtener el índice de la variable (A -> 0, B -> 1, etc.)
            resultado &= !variables[varIndex]; // Evaluamos la negación de la variable y combinamos con el resultado
            ptr += 2; // Avanzamos el puntero 2 posiciones (después de "A'")
        } else if (ptr[0] >= 'A' && ptr[0] <= 'Z') { // Verificamos si es una variable
            int varIndex = ptr[0] - 'A'; // Obtener el índice de la variable (A -> 0, B -> 1, etc.)
            resultado &= variables[varIndex]; // Evaluamos la variable y combinamos con el resultado
            ptr += 1; // Avanzamos el puntero 1 posición (después de "A")
        } else if (ptr[0] == '*') { // Verificamos el operador "*"
            ptr += 1; // Saltamos el operador "*"
        } else {
            ptr++; // Avanzamos al siguiente carácter
        }
    }

    return resultado; // Devolvemos el resultado de la evaluación del término
}

// Función para evaluar la expresión SOP y generar la tabla
void generarTablaConResultadosParciales(int variables, int filas, const char *expresionSOP) {
    // Arreglo para las combinaciones de entrada
    int entradas[variables];
    
    // Copiamos la expresión SOP porque la modificaremos
    char expresion[1024];
    strcpy(expresion, expresionSOP);

    // Dividimos la expresión SOP en términos individuales
    char *terminos[1024];     // Arreglo para almacenar los términos individuales
    int numTerminos = 0;      // Contador de términos
    char *token = strtok(expresion, "+"); // Dividimos la expresión SOP por el operador '+'
    while (token != NULL) {   // Mientras haya más términos
        terminos[numTerminos++] = token; // Añadimos el término al arreglo
        token = strtok(NULL, "+");       // Obtenemos el siguiente término
    }

    // Imprimimos el encabezado de la tabla
    printf("\nTabla de Verdad con Resultados Parciales:\n");
    for (int i = 0; i < variables; i++) {
        printf("%c   ", 'A' + i); // Imprimimos las variables A, B, etc.
    }
    for (int i = 0; i < numTerminos; i++) {
        if (i == numTerminos / 2) {
            printf(RED "   S" RESET "   "); // Agregamos la columna del resultado final S en la mitad
        }
        printf("(%s)", terminos[i]); // Imprimimos los términos individuales con paréntesis
        if (i < numTerminos - 1) {
            printf(" + "); // Agregamos el '+' entre términos, pero no al final
        }
    }
    printf("\n------------------------------------------\n");

    // Generamos la tabla
    for (int i = 0; i < filas; i++) { // Bucle externo que recorre cada fila de la tabla de verdad
        // Generamos los valores binarios para las entradas
        for (int j = variables - 1; j >= 0; j--) { // Bucle interno que recorre cada variable de entrada de derecha a izquierda
            entradas[j] = (i >> j) & 1; // Calculamos el valor binario de la entrada para la variable j-ésima
            printf("%d     ", entradas[j]); // Imprimimos el valor de la entrada
        }

        int resultadosParciales[numTerminos]; // Arreglo para almacenar los resultados parciales de cada término
        int salidaFinal = 0; // Inicializamos el resultado final en 0

        // Evaluamos cada término de la expresión SOP
        for (int j = 0; j < numTerminos; j++) { // Bucle que recorre cada término de la expresión SOP
            resultadosParciales[j] = evaluarTermino(entradas, terminos[j]); // Evaluamos el término j-ésimo
            salidaFinal |= resultadosParciales[j]; // Combinamos el resultado parcial con el resultado final usando OR bit a bit
            if (j == numTerminos / 2) {
                printf(RED "%d     " RESET, salidaFinal); // Imprimimos el resultado final en rojo en la mitad
            }
            printf(GREEN "%d     " RESET, resultadosParciales[j]); // Imprimimos el resultado parcial en verde
        }

        printf("\n"); // Pasamos a la siguiente fila
    }
}
