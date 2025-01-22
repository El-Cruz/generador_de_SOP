#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int numVariables;
    

    caratula();
    numVariables = solicitar_variables();
    int filas = 1 << numVariables; 
    int salidas[filas];
    tabla_verdad(numVariables);
    solicitarValoresSalida(numVariables, salidas);
    generarExpresionSOP(numVariables, salidas);
    
    
    return 0;
}