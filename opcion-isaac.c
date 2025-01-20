#include <stdio.h>
#include ".\librerias\Colores_Terminal.h"
#include ".\Librerias\Funciones.c"
#include ".\Librerias\Funciones2.h.txt"

int main(){
    int numVars = getNumVariables(); 
    int truthTable[1 << MAX_VARS]; 

    inputTruthTable(numVars, truthTable);
    generateBooleanExpression(numVars, truthTable); 
    generateTruthTable(numVars, truthTable);
    
    
    return 0;
}