#include <stdio.h>
#include <stdlib.h>
int main(){
    int variables; 

    // Determinación del número de filas según las variables (2^n)
    int filas = 1 << variables; // 2^variables
    int tabla[filas];           // Arreglo para almacenar las salida 
    
    do{
        printf("\nPor favor, Ingrese la cantidad de variables que desea usar, solo 2 o 3: ");
        scanf("%d", &variables);
        if(variables<2 || variables>3){
            printf("Error: ingrese una opcion valida\n");
        }
    }while (variables<2 || variables>3);









    return 0;
}