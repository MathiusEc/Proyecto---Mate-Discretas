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
int main(){

    printf("\n==============================\n"); 
    printf(" MATEMATICAS DISCRETAS I\n"); 
    printf("\n==============================\n"); 
    printf(" NOMBRES DE LOS INTEGRANTES\n"); 
    printf("\n==============================\n"); 
    printf(" DESCRIPCION DE LO QUE HACE EL PROGRAMA\n"); 
    printf("\n==============================\n"); 
    printf(" AÑO LECTIVO\n"); 
    printf("\n==============================\n");

// ya voy a buscar como imprimirle con colores y medio bastante decorando
// https://gist-github-com.translate.goog/Alfonzzoj/db207b89d56f24d9d0b17ff93e091be8?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=tc


/*se viene tremenda "Inspiracion" ve isaac jsjsjs ya el hago yo lo de imprimir y decorarle, tu sigue con las validaciones y demas, pero
 hazle en otro .c para evitarle conflits, y luego unimos, pilas
 */














    return 0;
}