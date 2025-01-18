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

    printf(BG_LBLUE WHITE "=====================================\n" RESET);        // Se utiliza la librería Colores_Terminal.h para imprimir 
    printf(BG_LBLUE WHITE "         MATEMÁTICAS DISCRETAS I     \n" RESET);        // texto en la consola con fonde celeste y letras blancas.
    printf(BG_LBLUE WHITE "=====================================\n\n" RESET);

    printf(BG_LGREEN BLACK "NOMBRES DE LOS INTEGRANTES:\n" RESET);                 // Se imprimen los nombres de los integrantes del grupo
    printf(ROSE "1. Isaac Benitez\n" RESET);                                       // con letras de color rosada
    printf(ROSE "2. Mathias Castillo\n" RESET);

    printf(BG_YELLOW BLACK "DESCRIPCIÓN DE LO QUE HACE EL PROGRAMA:\n" RESET);     // Explicación de lo que hace el programa	
    printf(GRAY "aqui va la\n");
    printf(GRAY "descripcion\n\n" RESET);

    printf(BG_ORANGE WHITE "NCR:\n" RESET);                                        // NCR y año lectivo con letras celestes
    printf(CYAN "5535 \n" RESET);

    printf(BG_ORANGE WHITE "AÑO LECTIVO:\n" RESET);
    printf(CYAN "2025 - 10 \n" RESET);

    printf(BG_LBLUE WHITE "\n=====================================\n" RESET);      // Fin de la Carátula


 // loco, quieres meterle una imagen que diga udla? o ascci art?












    return 0;
}