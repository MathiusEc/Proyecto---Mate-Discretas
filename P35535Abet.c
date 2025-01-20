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

#include <stdio.h>
#include ".\Librerias\Colores_Terminal.h"
//#include ".\Librerias\Funcion-forma-canonica.h"
int main(){
    int variables; 

    printf("           __  ______  __    ___  \n");
    printf("          / / / / __  / /   /   |\n" );
    printf("         / / / / / / / /   / /| |\n");
    printf("        / /_/ / /_/ / /___/ ___ |\n");
    printf("         ____/_____/_____/_/  |_|\n");    

    printf(BG_LBLUE WHITE "=====================================\n" RESET);        // Se utiliza la librería Colores_Terminal.h para imprimir 
    printf(BG_LBLUE WHITE "         MATEMATICAS DISCRETAS I     \n" RESET);        // texto en la consola con fonde celeste y letras blancas.
    printf(BG_LBLUE WHITE "=====================================\n\n" RESET);

    printf(BG_LGREEN BLACK "NOMBRES DE LOS INTEGRANTES:" RESET "\n");               // Se imprimen los nombres de los integrantes del grupo
    printf(ROSE "1. Isaac Benitez  \n");                                            // con letras de color rosada
    printf(ROSE "2. Mathias Castillo \n\n");

    printf(BG_YELLOW BLACK "DESCRIPCION DE LO QUE HACE EL PROGRAMA:\n" RESET);     // Explicación de lo que hace el programa	
    printf(GRAY "Desarrollar un programa que implemente una expresión SOP (Suma de Productos) a partir de una tabla de\n");
    printf(GRAY "verdad ingresada por el usuario. El programa debe construir y presentar la expresión booleana\n");
    printf(GRAY "correspondiente, utilizando operaciones lógicas OR y AND.\n\n");

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

    printf(BG_ORANGE WHITE "NCR:"RESET "\n");                                  // Resetea el color después de "NCR:"
    printf(CYAN "5535\n" RESET);                                            // Imprime el número con el texto en color cian, seguido de un reset.

    printf(BG_ORANGE WHITE "CALENDARIO ACADEMICO" RESET "\n");              // Resetea el fondo justo después del texto.
    printf(CYAN "2025 - 10\n" RESET);                                       // Imprime el calendario en cian y lo resetea.

    printf(BG_LBLUE WHITE "=====================================" RESET "\n"); // Todo bien aquí, ya que el reset viene después de los caracteres de fondo.


 // aqui solo poner lo q ya esta probado, hacer en otros archivos las demas pruebas, para evitar conflictos
    do{
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if(variables<2 || variables>3){
            printf(RED "Error: ingrese una opcion valida\n" RESET);
        }
    }while (variables<2 || variables>3);

    // Determinación del número de filas según las variables (2^n)
    int filas = 1 << variables; // 2^variables
    int tabla[filas];           // Arreglo para almacenar las salida 

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

    //Generación de la tabla de verdad y la expresión booleana
    printf("\nTabla de Verdad:\n");
    printf("A     B    ");
    if (variables == 3){
        printf("C    ");
        printf("S\n");
        printf("------------------------\n");
    }else{
        printf("S\n");
        printf("------------------------\n");
    }

    for (int i = 0; i < filas; i++) {
        for (int j = variables - 1; j >= 0; j--) {
            // Imprime los valores de las variables en formato binario
            printf("%d     ", (i >> j) & 1);
        }
        printf(GREEN "%d\n" RESET, tabla[i]); // Imprime la salida en color verde
    }
    





    return 0;
}