#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Función para mostrar la carátula del programa
void mostrar_caratula() {
    printf("==========================================\n");
    printf("         MATEMATICAS DISCRETAS 1         \n");
    printf("   NOMBRES DE LOS INTEGRANTES: [Nombre1, Nombre2] \n");
    printf("DESCRIPCION: Este programa genera la expresion SOP\n");
    printf("           a partir de una tabla de verdad\n");
    printf("               ANIO LECTIVO: 2025          \n");
    printf("==========================================\n\n");
}

// Función para generar la tabla de verdad
void generar_tabla_verdad(int num_vars, int tabla[][3]) {
    int filas = (int)pow(2, num_vars); // Número de filas en la tabla de verdad
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < num_vars; j++) {
            tabla[i][j] = (i >> (num_vars - 1 - j)) & 1; // Genera las combinaciones binarias
        }
    }
}

// Función para imprimir la tabla de verdad
void imprimir_tabla_verdad(int num_vars, int tabla[][3], int salidas[]) {
    printf("\nTabla de Verdad:\n");
    for (int i = 0; i < num_vars; i++) {
        printf("%c ", 'A' + i); // Nombres de las variables
    }
    printf("S\n");

    for (int i = 0; i < (int)pow(2, num_vars); i++) {
        for (int j = 0; j < num_vars; j++) {
            printf("%d    ", tabla[i][j]); // Muestra los valores de la tabla
        }
        printf("%d\n", salidas[i]); // Muestra la salida correspondiente
    }
}

// Función para generar la descomposición en términos de producto (SOP) usando matrices
void generar_descomposicion(int num_vars, int tabla[][3], int salidas[]) {
    int filas = (int)pow(2, num_vars);
    
    // Crear matrices para almacenar los resultados de las operaciones
    int neg_A[filas], neg_B[filas], neg_A_and_B[filas], A_and_neg_B[filas], resultado[filas];
    
    // Encabezado de la tabla de descomposición
    printf("\nDescomposición por Términos de Producto:\n");
    printf("%-5s%-5s%-5s%-5s%-10s%-10s%-30s\n", "A", "B", "¬A", "¬B", "¬A ∧ B", "A ∧ ¬B", "(¬A ∧ B) + (A ∧ ¬B)");

    // Llenar las matrices con los resultados de las operaciones
    for (int i = 0; i < filas; i++) {
        neg_A[i] = !tabla[i][0]; // ¬A
        neg_B[i] = (num_vars > 1) ? !tabla[i][1] : 0; // ¬B (solo si hay más de una variable)

        neg_A_and_B[i] = neg_A[i] && tabla[i][1]; // ¬A ∧ B
        A_and_neg_B[i] = tabla[i][0] && neg_B[i]; // A ∧ ¬B

        resultado[i] = neg_A_and_B[i] || A_and_neg_B[i]; // (¬A ∧ B) + (A ∧ ¬B)
    }

    // Mostrar los resultados en una tabla organizada
    for (int i = 0; i < filas; i++) {
        printf("%-5d%-5d%-5d%-5d%-10d%-10d%-30d\n", 
               tabla[i][0], tabla[i][1], neg_A[i], neg_B[i], neg_A_and_B[i], A_and_neg_B[i], resultado[i]);
    }
}

// Función principal
int main() {
    mostrar_caratula(); // Mostrar la carátula del programa

    int num_vars;
    printf("Digite el numero de variables logicas (2 o 3): ");
    scanf("%d", &num_vars); // Obtener el número de variables

    if (num_vars < 2 || num_vars > 3) {
        printf("El numero de variables debe ser 2 o 3.\n");
        return 1; // Asegurarse de que solo haya 2 o 3 variables
    }

    int filas = (int)pow(2, num_vars); // Número de filas en la tabla de verdad
    int tabla[filas][3]; // Matriz para la tabla de verdad
    int salidas[filas];   // Arreglo para almacenar las salidas

    // Generar la tabla de verdad
    generar_tabla_verdad(num_vars, tabla);

    // Pedir al usuario que ingrese los valores de salida
    printf("\nIngrese los valores de salida (0 o 1) para cada fila de la tabla de verdad:\n");
    for (int i = 0; i < filas; i++) {
        printf("Fila %d: ", i + 1);
        scanf("%d", &salidas[i]);
        if (salidas[i] != 0 && salidas[i] != 1) {
            printf("Valor de salida invalido. Use 0 o 1.\n");
            return 1; // Validar las salidas
        }
    }

    // Imprimir la tabla de verdad
    imprimir_tabla_verdad(num_vars, tabla, salidas);

    // Generar la descomposición por términos de producto
    generar_descomposicion(num_vars, tabla, salidas);

    printf("\nGracias por usar este programa.\n");
    return 0;
}