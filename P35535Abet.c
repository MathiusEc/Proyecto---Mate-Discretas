/*
Pantallas que debe tener el programa
1.	Inicio caratula
MATEMATICAS DISCRETAS 1
NOMBRES DE LOS INTEGRANTES
DESCRIPCION DE LO QUE HACE EL PROGRAMA

AÑO LECTIVO
2.	Ingreso de número de variables lógicas
Digite el número de variables lógicas, solo 2 o 3:  2
Debe validarse que solo se digite los números dos o tres, caso contrario envié mensaje al usuario 

3.	Ingreso de valores 
Ingrese los valores de salida, 0 o 1 para cada fila de la tabla de verdad:  
A     B    S
-------------------
[0] [0]   0
[0] [1]   1
[1] [0]   1
[1] [1]   0
Debe validarse que solo se digite 0 o 1
4.	Generación de expresión booleana
La expresión booleana generada es: A’*B + B’*A

5.	Generación de LA TABLA DE VERDAD
Tabla de verdad de la expresión A’*B + B’*A

A’ * B      +     B’ * A
-----------------------
1   0   0    0      1  0  0 
1   1   1    1      0  0  0
0   0   0    1      1  1  1
0   0   1    0      0  0  1
Debe presentar los resultados parciales en color verde y el final en rojo

*/

#include <stdlib.h>  // Biblioteca estándar de utilidades. Proporciona funciones para:
                     // - Gestión de memoria dinámica (malloc, calloc, free).
                     // - Conversión de números (atoi, atof).
                     // - Generación de números aleatorios (rand, srand).
                     // - Control de la terminación del programa (exit).

#include <stdio.h>   // Biblioteca estándar de entrada y salida. Proporciona funciones para:
                     // - Escritura de datos (printf, fprintf).
                     // - Lectura de datos (scanf, fscanf).
                     // - Manipulación de archivos (fopen, fclose).
                     // - Mostrar mensajes de error (perror).

#include <math.h>    // Biblioteca matemática. Proporciona funciones para:
                     // - Funciones trigonométricas (sin, cos, tan).
                     // - Funciones exponenciales y logarítmicas (exp, log).
                     // - Funciones de raíz (sqrt).
                     // - Funciones de valor absoluto y redondeo (fabs, floor).

#include <string.h>  // Biblioteca de manipulación de cadenas. Proporciona funciones para:
                     // - Copia de cadenas (strcpy, strncpy).
                     // - Concatenación de cadenas (strcat, strncat).
                     // - Comparación de cadenas (strcmp, strncmp).
                     // - Longitud de cadenas (strlen).
                     // - División de cadenas en subcadenas (strtok).
                     // - Búsqueda de subcadenas (strstr).

#include ".\Librerias\Colores_Terminal.h"  // Biblioteca personalizada para manejar colores en la terminal.
                                           // Proporciona definiciones y funciones para imprimir texto en color.
                                           // Ejemplo: definiciones de colores como GREEN, RED, etc.

#include ".\Librerias\Funcion-forma-canonica.h"  // Biblioteca personalizada para funciones adicionales de forma canónica.
                                                 // Proporciona funciones para construir o manipular expresiones en forma canónica.

#include ".\Librerias\Tablas-verdad.h"  // Biblioteca personalizada para funciones adicionales de tablas de verdad.
                                        // Proporciona funciones para generar y evaluar tablas de verdad.

// Prototipo de la función que construirá la expresión SOP (Suma de Productos).
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado);

int main(){
    int variables; // Declaración de la variable para almacenar el número de variables lógicas.
    char expresionSOP[1024] = "";

    // Imprimir la carátula del programa con detalles de los integrantes y una breve descripción.
    printf("           __  ______  __    ___  \n");
    printf("          / / / / __  / /   /   |\n" );
    printf("         / / / / / / / /   / /| |\n");
    printf("        / /_/ / /_/ / /___/ ___ |\n");
    printf("         ____/_____/_____/_/  |_|\n");    

    // Imprimir título del programa con colores de fondo y texto especificados.
    printf(BG_LBLUE WHITE "=====================================\n" RESET);        
    printf(BG_LBLUE WHITE "         MATEMATICAS DISCRETAS I     \n" RESET);        
    printf(BG_LBLUE WHITE "=====================================\n\n" RESET);

    // Imprimir nombres de los integrantes del proyecto.
    printf(BG_LGREEN BLACK "NOMBRES DE LOS INTEGRANTES:" RESET "\n");               
    printf(ROSE "1. Isaac Benitez  \n");                                            
    printf(ROSE "2. Mathias Castillo \n\n");

    // Imprimir descripción del programa.
    printf(BG_YELLOW BLACK "DESCRIPCION DE LO QUE HACE EL PROGRAMA:\n" RESET);     
    printf(CYAN "Desarrollar un programa que implemente una expresion SOP (Suma de Productos) a partir de una tabla de\n");
    printf(CYAN "verdad ingresada por el usuario. El programa debe construir y presentar la expresion booleana\n");
    printf(CYAN "correspondiente, utilizando operaciones lógicas OR y AND.\n\n");

    // Imprimir las instrucciones del programa.
    printf("Intrucciones:\n");
    printf(LBLUE "   i. Solicitar al usuario que ingrese el numero de variables booleanas (solo 2 o 3).\n");
    printf(LBLUE "   ii. Generar la tabla de verdad correspondiente al numero de variables ingresadas.\n");
    printf(LBLUE "   iii. Pedir al usuario que ingrese los valores de salida (1 o 0) para cada fila de la tabla de verdad.\n");
    printf(LBLUE "   iv. Identificar las filas de la tabla de verdad donde la salida es 1.\n");
    printf(LBLUE "   v. Para cada fila con salida 1:\n");
    printf(LBLUE "       a. Construir un termino producto (AND) que represente las combinaciones de entrada de esa\n");
    printf(LBLUE "          fila. Por ejemplo, si las variables son A y B, y la fila tiene A=1 y B=0, el termino producto seria\n");
    printf(LBLUE "          A AND NOT B.\n");
    printf(LBLUE "       b. Combinar todos los terminos producto usando la operacion suma (OR) para formar la\n");
    printf(LBLUE "          expresion SOP final\n");
    printf(LBLUE "   vi. Presentar al usuario:\n");
    printf(LBLUE "       a. La expresion booleana final\n");
    printf(LBLUE "       b. La tabla de verdad completada con las salidas ingresadas\n\n");
    //TILDES  QUITADAS YA QUE C NO COMPILA CON TILDES :D

    // Imprimir datos adicionales (NCR y Calendario Académico).
    printf(BG_ORANGE WHITE "NCR:"RESET "\n");                                  
    printf(CYAN "5535\n" RESET);                                            

    printf(BG_ORANGE WHITE "CALENDARIO ACADEMICO" RESET "\n");              
    printf(CYAN "2025 - 10\n" RESET);                                       

    printf(BG_LBLUE WHITE "=====================================" RESET "\n"); 

    // Solicitar al usuario el número de variables lógicas (solo 2 o 3) y validar la entrada.
      do {
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if (variables < 2 || variables > 3) {
            printf(RED "Error: ingrese una opcion valida\n" RESET);
        }
    } while (variables < 2 || variables > 3);

    // Determinación del número de filas según las variables (2^n)
    int filas = 1 << variables; // 2^variables
    int tabla[filas][variables + 1]; // Tabla de verdad completa

    // Llenar la tabla de verdad con los valores de entrada
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            tabla[i][j] = (i >> (variables - j - 1)) & 1;
        }
    }

    // Solicitar los valores de salida (S)
    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) { // Bucle externo que recorre cada fila de la tabla de verdad
        do { // Bucle do-while para asegurar una entrada válida
            printf("Fila %d: ", i); // Imprimir el número de la fila
            scanf(" %d", &tabla[i][variables]); // Leer el valor de salida para la fila actual
            // Verificar si el valor ingresado es válido (0 o 1)
            if (tabla[i][variables] != 0 && tabla[i][variables] != 1) {
                printf(RED "Error: Solo puede ingresar 0 o 1.\n" RESET); // Mostrar mensaje de error si el valor es inválido
            }
        }while (tabla[i][variables] != 0 && tabla[i][variables] != 1); // Repetir hasta que se ingrese un valor válido
    }

    //Imprimir el encabezado de la tabla de verdad
    printf("\nTabla de Verdad:\n");
    for (int i = 0; i < variables; i++) {
        printf(" %c ", 'A' + i);
    }
    printf(" S\n");

    // Imprimir el cuerpo de la tabla de verdad
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            printf(" %d ", tabla[i][j]);
        }
        // Imprimir los valores de salida en color verde
        printf(GREEN " %d\n" RESET, tabla[i][variables]);
    }

    // Construcción de la expresión SOP
    construirSOP(variables, tabla, filas, expresionSOP);
    imprimirTablaConResultadosParciales(variables, filas, tabla, expresionSOP);
    // Mostrar la expresión SOP
    printf(ORANGE "\nLa expresion SOP generada es: %s\n" RESET, expresionSOP);

    return 0; // Finalizar el programa.
}
