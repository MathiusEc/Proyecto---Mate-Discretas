//SOP: Suma de Productos(Sum of Products)
// Definir la función que construye la expresión SOP a partir de la tabla de verdad.
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado) {
    int primeraSuma = 1; // Variable para manejar si es la primera suma (OR) en la expresión.

    // Bucle para recorrer todas las filas de la tabla de verdad.
    for (int i = 0; i < totalFilas; i++) {
        // Si la salida de la fila actual es 1, significa que esta fila contribuye a la expresión SOP.
        if (tabla[i][numVars] == 1) {
            // Si no es la primera vez que se añade una suma (OR), añadir " + " a la expresión.
            if (!primeraSuma) {
                strcat(resultado, " + ");
            }
            strcat(resultado, "("); // Añadir un paréntesis de apertura para el término producto.

            // Bucle para recorrer las variables de entrada de la fila actual.
            for (int j = 0; j < numVars; j++) {
                // Si el valor de la variable es 1, añadir la variable (A, B, C, etc.) a la expresión.
                if (tabla[i][j] == 1) {
                    char var[2]; // Declarar una cadena para almacenar la variable.
                    sprintf(var, "%c", 'A' + j); // Convertir el índice de la variable en el carácter correspondiente.
                    strcat(resultado, var); // Añadir la variable a la expresión.
                } else {
                    // Si el valor de la variable es 0, añadir la variable negada (NOT A, NOT B, NOT C, etc.) a la expresión.
                    char var[6]; // Declarar una cadena para almacenar la variable negada.
                    sprintf(var, "NOT %c", 'A' + j); // Convertir el índice de la variable en el carácter correspondiente.
                    strcat(resultado, var); // Añadir la variable negada a la expresión.
                }

                // Si no es la última variable, añadir " AND " entre las variables.
                if (j < numVars - 1) {
                    strcat(resultado, " AND ");
                }
            }

            strcat(resultado, ")"); // Añadir un paréntesis de cierre para el término producto.
            primeraSuma = 0; // Cambiar la bandera para indicar que la primera suma ya se ha añadido.
        }
    }
}
