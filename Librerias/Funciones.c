#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_VARS 3

int getNumVariables();
void inputTruthTable(int numVars, int truthTable[]);
void generateBooleanExpression(int numVars, int truthTable[]);
void generateTruthTable(int numVars, int truthTable[]);

#endif
