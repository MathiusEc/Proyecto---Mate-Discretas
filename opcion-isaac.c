#include <stdio.h> // Incluir la biblioteca estándar de entrada y salida.
#include <math.h> // Incluir la biblioteca matemática.
#include <string.h> // Incluir la biblioteca de manipulación de cadenas.
#include ".\Librerias\Colores_Terminal.h" // Incluir la biblioteca para manejar colores en la terminal.
#include ".\Librerias\Funcion-forma-canonica.h" // Incluir la biblioteca personalizada para funciones adicionales.

void generarTablaVerdadSOP(char* expresionSOP, int numVars, int tabla[][numVars + 1]);

int main() {
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
    printf("Instrucciones:\n");
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
    do {
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if (variables < 2 || variables > 3) {
            // Si la entrada no es válida, imprimir un mensaje de error.
            printf(RED "Error: ingrese una opción válida\n" RESET);
        }
    } while (variables < 2 || variables > 3); // Repetir hasta que se ingrese un valor válido.

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
            tabla[i][j] = (i >> (variables - j - 1)) & 1;
        }
    }

    // Imprimir la tabla de verdad.
    printf("\nTabla de Verdad:\n");
    for (int i = 0; i < variables; i++) {
        printf(" %c ", 'A' + i);
    }
    printf(" S\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            printf(" %d ", tabla[i][j]);
        }
        printf(GREEN " %d\n" RESET, tabla[i][variables]);
    }

    // Llamar a la función para construir la expresión SOP (Suma de Productos) definida en el archivo .h.
    construirSOP(variables, tabla, filas, resultado);

    // Imprimir la expresión SOP generada.
    printf("Expresión SOP (Forma Canónica): %s\n", resultado);

    // Generar e imprimir la tabla de verdad de la expresión SOP.
    printf("\nTabla de Verdad de la Expresión SOP:\n");
    generarTablaVerdadSOP(resultado, variables, tabla);

    return 0; // Finalizar el programa.
}

// Función para generar la tabla de verdad de la expresión SOP.
void generarTablaVerdadSOP(char* expresionSOP, int numVars, int tabla[][numVars + 1]) {
    int filas = 1 << numVars;

    // Imprimir los encabezados de la tabla
    for (int i = 0; i < numVars; i++) {
        printf(" %c ", 'A' + i);
    }
    printf(" %s\n", expresionSOP);
    printf("-----------------------\n");

    // Generar la tabla de verdad basada en la expresión SOP
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < numVars; j++) {
            printf(" %d ", tabla[i][j]);
        }
        // Calcular los valores parciales y el resultado final
        int resultadoFinal = 0;
        // Procesar cada término de la expresión SOP
        char copiaExpresion[1024];
        strcpy(copiaExpresion, expresionSOP);
        char* token = strtok(copiaExpresion, " + ");
        while (token != NULL) {
            int valorTermino = 1;
            for (int j = 0; j < strlen(token); j++) {
                if (token[j] >= 'A' && token[j] <= 'C') { // Suponiendo que las variables son A, B y C
                    int varIndex = token[j] - 'A';
                    valorTermino *= tabla[i][varIndex];
                } else if (token[j] == '\'') {
                    int varIndex = token[j - 1] - 'A';
                    valorTermino *= !tabla[i][varIndex];
                }
            }
                        // Imprimir los valores parciales en verde
            printf(GREEN " %d " RESET, valorTermino);
            resultadoFinal += valorTermino;
            token = strtok(NULL, " + ");
        }
        // Imprimir el resultado final en rojo
        printf(RED " %d\n" RESET, resultadoFinal > 0 ? 1 : 0);
    }
}
