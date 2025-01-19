#include <stdio.h>
#include ".\librerias\Colores_Terminal.h"
int main(){
    int variables; // cambie a variables porq vamos a trabajar con esta mas adelante, asi no confundirnos tmb
    do{
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if(variables<2 || variables>3){
            printf("Error: ingrese una opcion valida\n");
        }
    }while (variables<2 || variables>3);

    // Determinación del número de filas según las variables (2^n)
    int filas = 1 << variables; // 2^variables
    int tabla[filas];           // Arreglo para almacenar las salida 

    printf("Ingrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf("%d", &tabla[i]);
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