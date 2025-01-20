void construirSOP(int numVars, int tabla[][numVars + 1], int totalFilas, char *resultado) {
    int primeraSuma = 1;
    for (int i = 0; i < totalFilas; i++) {
        if (tabla[i][numVars] == 1) { // Salida es 1
            if (!primeraSuma) {
                strcat(resultado, " + ");
            }
            strcat(resultado, "(");

            for (int j = 0; j < numVars; j++) {
                if (tabla[i][j] == 1) {
                    char var[2];
                    sprintf(var, "%c", 'A' + j);
                    strcat(resultado, var);
                } else {
                    char var[6];
                    sprintf(var, "NOT %c", 'A' + j);
                    strcat(resultado, var);
                }

                if (j < numVars - 1) {
                    strcat(resultado, " AND ");
                }
            }

            strcat(resultado, ")");
            primeraSuma = 0;
        }
    }
}