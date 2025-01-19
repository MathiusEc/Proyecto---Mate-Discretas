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
int main(){ 

    printf("          __  ______  __    ___  \n");
    printf("         / / / / __  / /   /   |\n" );
    printf("        / / / / / / / /   / /| |\n");
    printf("       / /_/ / /_/ / /___/ ___ |\n");
    printf("        ____/_____/_____/_/  |_|\n");    

    printf(BG_LBLUE WHITE "=====================================" RESET "\n");      // Se utiliza la librería Colores_Terminal.h para imprimir 
    printf(BG_LBLUE WHITE "         MATEMATICAS DISCRETAS I     " RESET "\n");      // Se utiliza la librería Colores_Terminal.h para imprimir   
    printf(BG_LBLUE WHITE "=====================================" RESET "\n\n");    // texto en la consola con fonde celeste y letras blancas.

    printf(BG_LGREEN BLACK "NOMBRES DE LOS INTEGRANTES:" RESET "\n");               // Se imprimen los nombres de los integrantes del grupo
    printf(ROSE "1. Isaac Benitez  \n");                                            // con letras de color rosada
    printf(ROSE "2. Mathias Castillo \n\n");

    printf(BG_YELLOW BLACK "DESCRIPCION DE LO QUE HACE EL PROGRAMA:" RESET "\n");   // Explicación de lo que hace el programa
    printf(GRAY "Desarrollar un programa que implemente una expresión SOP (Suma de Productos) a partir de una tabla de \n");
    printf(GRAY "verdad ingresada por el usuario. El programa debe construir y presentar la expresión booleana \n");
    printf(GRAY "correspondiente, utilizando operaciones lógicas OR y AND. \n \n");

    printf(GRAY "Instrucciones: \n");
    printf(GRAY "i. Solicitar al usuario que ingrese el número de variables booleanas (solo 2 o 3).\n");
    printf(GRAY "ii. Generar la tabla de verdad correspondiente al número de variables ingresadas.\n");
    printf(GRAY "iii. Pedir al usuario que ingrese los valores de salida (“1” o “0”) para cada fila de la tabla de verdad.\n");
    printf(GRAY "iv. Identificar las filas de la tabla de verdad donde la salida es “1”.\n");
    printf(GRAY "v. Para cada fila con salida “1”:\n");   
    printf(GRAY "   a. Construir un término producto (AND) que represente las combinaciones de entrada de esa \n");
    printf(GRAY "   fila. Por ejemplo, si las variables son A y B, y la fila tiene A=1 y B=0, el término producto sería\n");  
    printf(GRAY "   A AND NOT B.\n \n"); 

    printf(GRAY "   b. Combinar todos los términos producto usando la operación suma (OR) para formar la\n");
    printf(GRAY "   expresión SOP final.\n \n");

    printf(GRAY "vi. Presentar al usuario: \n");
    printf(GRAY "   a. La expresión booleana final. \n");
    printf(GRAY "   b. La tabla de verdad completa con las salidas ingresadas. \n \n");

    printf(BG_ORANGE WHITE "NCR:" RESET "\n");                                      // NCR y año lectivo con letras celestes
    printf(CYAN "5535" RESET "\n");

    printf(BG_ORANGE WHITE "CALENDARIO ACADEMICO" RESET "\n");
    printf(CYAN "2025 - 10" RESET "\n");

    printf(BG_LBLUE WHITE "=====================================" RESET "\n");      // Fin de la Carátula


    













    return 0;
}