
#include ".\Colores_Terminal.h"
#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida. Proporciona funciones para realizar operaciones de entrada y salida, como printf, scanf, etc.
#include <string.h> // Incluye la biblioteca para manipulación de cadenas de caracteres. Proporciona funciones para manejar y operar con cadenas (char arrays), como strcpy, strcat, strlen, etc.
#include <stdlib.h> // Incluye la biblioteca estándar de utilidades. Proporciona funciones para realizar operaciones de propósito general, como memoria dinámica (malloc, free), conversión de números (atoi, atof), control de procesos (exit), entre otras.

// Función para evaluar cada término de la expresión SOP
int evaluarTermino(int variables[], const char *termino) {
    int resultado = 1; // Inicialmente asumimos que el término es verdadero

    const char *ptr = termino; // Apuntamos al inicio de la cadena término

    while (*ptr != '\0') { // Recorremos la cadena hasta el final
        if (strncmp(ptr, "NOT A", 5) == 0) { // Comparamos las primeras 5 letras con "NOT A"
            int varIndex = ptr[5] - '1'; // Obtener el índice de la variable (A1 -> 0, A2 -> 1, etc.)
            resultado &= !variables[varIndex]; // Evaluamos la negación de la variable y combinamos con el resultado
            ptr += 6; // Avanzamos el puntero 6 posiciones (después de "NOT A1")
        } else if (strncmp(ptr, "A", 1) == 0) { // Comparamos la primera letra con "A"
            int varIndex = ptr[1] - '1'; // Obtener el índice de la variable (A1 -> 0, A2 -> 1, etc.)
            resultado &= variables[varIndex]; // Evaluamos la variable y combinamos con el resultado
            ptr += 2; // Avanzamos el puntero 2 posiciones (después de "A1")
        } else if (strncmp(ptr, " AND ", 5) == 0) { // Comparamos las primeras 5 letras con " AND "
            ptr += 5; // Saltamos el operador "AND"
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
    /*
    cada elemento de este arreglo terminos puede apuntar a una cadena diferente. 
    Por ejemplo, terminos[0] puede apuntar a la primera cadena, terminos[1] puede 
    apuntar a la segunda cadena, y así sucesivamente.
    */
    int numTerminos = 0;      // Contador de términos
    char *token = strtok(expresion, "+"); // Dividimos la expresión SOP por el operador '+'
    while (token != NULL) {   // Mientras haya más términos
        terminos[numTerminos++] = token; // Añadimos el término al arreglo
        token = strtok(NULL, "+");       // Obtenemos el siguiente término
    }

    // Imprimimos el encabezado de la tabla
    printf("\nTabla de Verdad con Resultados Parciales:\n");
    for (int i = 0; i < variables; i++) {
        printf("A%d   ", i + 1); // Imprimimos las variables A1, A2, etc.
    }
    for (int i = 0; i < numTerminos; i++) {
        printf("%s   ", terminos[i]); // Imprimimos los términos individuales
    }
    printf(RED "S\n" RESET);          // Imprimimos la columna del resultado final S
    printf("------------------------------------------\n");

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
            printf(GREEN "%d     " RESET, resultadosParciales[j]); // Imprimimos el resultado parcial en verde
        }

        // Imprimimos el resultado final en rojo
        printf(RED "%d\n" RESET, salidaFinal); // Imprimimos el resultado final en rojo y pasamos a la siguiente fila
    }

}
