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

#include <stdio.h> // Incluir la biblioteca estándar de entrada y salida.
#include <math.h> // Incluir la biblioteca matemática.
#include <string.h> // Incluir la biblioteca de manipulación de cadenas.
#include ".\Librerias\Colores_Terminal.h" // Incluir la biblioteca para manejar colores en la terminal.
#include ".\Librerias\Funcion-forma-canonica.h" // Incluir la biblioteca personalizada para funciones adicionales.

// Prototipo de la función que construirá la expresión SOP (Suma de Productos).
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado);

int main(){
    int variables; // Declaración de la variable para almacenar el número de variables lógicas.

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
    printf(GRAY "Desarrollar un programa que implemente una expresión SOP (Suma de Productos) a partir de una tabla de\n");
    printf(GRAY "verdad ingresada por el usuario. El programa debe construir y presentar la expresión booleana\n");
    printf(GRAY "correspondiente, utilizando operaciones lógicas OR y AND.\n\n");

    // Imprimir las instrucciones del programa.
    printf("Intrucciones:\n");
    printf(GRAY "   i. Solicitar al usuario que ingrese el número de variables booleanas (solo 2 o 3).\n");
    printf(GRAY "   ii. Generar la tabla de verdad correspondiente al número de variables ingresadas.\n");
    printf(GRAY "   iii. Pedir al usuario que ingrese los valores de salida (“1” o “0”) para cada fila de la tabla de verdad.\n");
    printf(GRAY "   iv. Identificar las filas de la tabla de verdad donde la salida es “1”.\n");
    printf(GRAY "   v. Para cada fila con salida “1”:\n");
    printf(GRAY "       a. Construir un término producto (AND) que represente las combinaciones de entrada de esa\n");
    printf(GRAY "          fila. Por ejemplo, si las variables son A y B, y la fila tiene A=1 y B=0, el término producto sería\n");
    printf(GRAY "          A AND NOT B.\n");
    printf(GRAY "       b. Combinar todos los términos producto usando la operación suma (OR) para formar la\n");
    printf(GRAY "          expresión SOP final\n");
    printf(GRAY "   vi. Presentar al usuario:\n");
    printf(GRAY "       a. La expresión booleana final\n");
    printf(GRAY "       b. La tabla de verdad completada con las salidas ingresadas\n\n");

    // Imprimir datos adicionales (NCR y Calendario Académico).
    printf(BG_ORANGE WHITE "NCR:"RESET "\n");                                  
    printf(CYAN "5535\n" RESET);                                            

    printf(BG_ORANGE WHITE "CALENDARIO ACADEMICO" RESET "\n");              
    printf(CYAN "2025 - 10\n" RESET);                                       

    printf(BG_LBLUE WHITE "=====================================" RESET "\n"); 

    // Solicitar al usuario el número de variables lógicas (solo 2 o 3) y validar la entrada.
    do{
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if(variables<2 || variables>3){
            // Si la entrada no es válida, imprimir un mensaje de error.
            printf(RED "Error: ingrese una opcion valida\n" RESET);
        }
    }while (variables<2 || variables>3); // Repetir hasta que se ingrese un valor válido.

    int filas = 1 << variables; // Calcular el número de filas en la tabla de verdad (2^variables).
    int tabla[filas][variables + 1]; // Declarar la matriz para la tabla de verdad.
    char resultado[1024] = ""; // Declarar una cadena para almacenar la expresión SOP.

    // Solicitar al usuario los valores de salida (0 o 1) para cada fila de la tabla de verdad.
    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf(" %d", &tabla[i][variables]);
            if (tabla[i][variables] != 0 && tabla[i][variables] != 1) {
                // Si la entrada no es válida, imprimir un mensaje de error.
                printf(RED "Error: Solo puede ingresar 0 o 1.\n" RESET);
            }
        } while (tabla[i][variables] != 0 && tabla[i][variables] != 1); // Repetir hasta que se ingrese un valor válido.
    }

    // Generar los valores de la tabla de verdad.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            // Calcular los valores binarios correspondientes a las variables de entrada.
            tabla[i][j] = (i >> (variables - j - 1)) & 1;
        }
    }

    // Imprimir la tabla de verdad.
    printf("\nTabla de Verdad:\n");
    for (int i = 0; i < variables; i++) {
        // Imprimir los encabezados de las columnas (A, B, C, etc.).
        printf(" %c ", 'A' + i);
    }
    printf(" S\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            // Imprimir los valores de las variables de entrada.
            printf(" %d ", tabla[i][j]);
        }
        // Imprimir los valores de salida en color verde.
        printf(GREEN " %d\n" RESET, tabla[i][variables]);
    }

    // Llamar a la función para construir la expresión SOP (Suma de Productos).
    construirSOP(variables, tabla, filas, resultado);

    // Imprimir la expresión SOP generada.
    printf("Expresión SOP (Forma Canónica): %s\n", resultado);

    return 0; // Finalizar el programa.
}



