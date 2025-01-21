// Función para construir la expresión SOP (Sum of Products)
void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado) {
    // Variable para controlar si es la primera suma
    int primeraSuma = 1;

    // Bucle que recorre cada fila de la tabla de verdad
    for (int i = 0; i < totalFilas; i++) {
        // Verificar si el resultado en la columna final (S) es 1
        if (tabla[i][numVars] == 1) { // Salida es 1

            // Si no es el primer término, agregar un operador `+`
            if (!primeraSuma) {
                strcat(resultado, " + ");
            }
            
            // Agregar un paréntesis de apertura `(` al inicio del término
            strcat(resultado, "(");

            // Bucle que recorre cada variable de la fila actual
            for (int j = 0; j < numVars; j++) {
                // Verificar si la variable es `1`
                if (tabla[i][j] == 1) {
                    // Declarar una cadena para almacenar el nombre de la variable (por ejemplo, "A")
                    char var[5];
                    // Formatear la cadena `var` para incluir el nombre de la variable
                    sprintf(var, "A%d", j + 1);
                    // Concatenar la variable `var` a la cadena `resultado`
                    strcat(resultado, var);
                } else {
                    // Si la variable no es `1` (es `0`), agregar la variable negada
                    char var[7];
                    // Formatear la cadena `var` para incluir el nombre de la variable negada (por ejemplo, "NOT A")
                    sprintf(var, "NOT A%d", j + 1);
                    // Concatenar la variable negada `var` a la cadena `resultado`
                    strcat(resultado, var);
                }

                // Si no es la última variable, agregar el operador `AND`
                if (j < numVars - 1) {
                    strcat(resultado, " AND ");
                }
            }

            // Agregar un paréntesis de cierre `)` al final del término
            strcat(resultado, ")");
            // Actualizar la variable `primeraSuma` a `0` para indicar que ya se ha agregado el primer término
            primeraSuma = 0;
        }
    }
}