
#include <stdio.h>
#include <stdlib.h>


//declaración de funciones
void caratula();
int solicitar_variables();
void tabla_verdad(int num_variables);
void solicitarValoresSalida(int variables, int *salidas);
void generarExpresionSOP(int variables, int *salidas);


//función mostrar carátula
void caratula(){

    
    int continuar;
    printf("\n========================================================\n");
    printf("=       PROYECTO FINAL - MATEMATICAS DISCRETAS          =\n");
    printf("\n=========================================================\n");
    printf("Intergrantes:\n");
    printf("1. Nicolas Cruz\n");
    printf("2. Diego Moncayo\n");
    printf("\n=========================================================\n");
    printf("Descripcion del programa:\n");
    printf("Este programa genera una expresion SOP a partir de una\ntabla de verdad ingresada por el usuario.\n");
    printf("                     2024 - 2025                       \n");
    printf("\n=========================================================\n");
    printf("Presione '1' para continuar...");
    scanf("%d", &continuar);
}


//función para solicitar el numero de variables y comprobar el rango
int solicitar_variables(){
    int num_variables;
    do{
    printf("Ingrese el numero de variables: ");
    scanf("%d", &num_variables);
    if(num_variables != 2 && num_variables != 3){
        printf("Error: Solo pueden ser 2 o 3 variables logicas\n");
    }
    }while(num_variables != 2 && num_variables != 3);
    
    return num_variables;
}


//función para generar la tabla de verdad
void tabla_verdad(int num_variables){
   int filas = 1 << num_variables; // Calcula 2^variables
    printf("\nTabla de Verdad con %d variables:\n", num_variables);
    printf("\n=========================================================\n");
    
    for (int i = 0; i < filas; i++) {
        for (int j = num_variables - 1; j >= 0; j--) {
            printf("%d ", (i >> j) & 1); 
        }
        printf("\n");
    }
}


// Función para solicitar los valores de salida
void solicitarValoresSalida(int variables, int *salidas) {
    int filas = 1 << variables; // Calcula 2^variables
    printf("\nIngrese los valores de salida (0 o 1) para cada fila:\n");
    
    for (int i = 0; i < filas; i++) {
        int valido = 0;
        while (!valido) {
            printf("Fila %d: ", i + 1);
            scanf("%d", &salidas[i]);
            if (salidas[i] == 0 || salidas[i] == 1) {
                valido = 1;
            } else {
                printf("Error: Solo puede ingresar 0 o 1.\n");
            }
        }
    }
}


// Función para generar la expresión SOP
void generarExpresionSOP(int variables, int *salidas) {
    int filas = 1 << variables;
    int primeraTerm = 1;
    int todasCero = 1;
    int todasUno = 1;

     for (int i = 0; i < filas; i++) { //aquí se comprueba si todas las salidas son 0 o 1
        if (salidas[i] == 1) todasCero = 0;
        if (salidas[i] == 0) todasUno = 0;
    }

    if (todasUno) {
        printf("\nLa expresion booleana generada es: 1\n");
        return;
    }
    if (todasCero) {
        printf("\nLa expresion booleana generada es: 0\n");
        return;
    }
    printf("\nLa expresion booleana generada es: ");
    
    for (int i = 0; i < filas; i++) {
        if (salidas[i] == 1) {
            if (!primeraTerm) {
                printf(" + "); // Agregar OR entre términos
            }
            primeraTerm = 0;

            // Construir el término producto
            for (int j = variables - 1; j >= 0; j--) {
                if (((i >> j) & 1) == 1) {
                    printf("%c", 'A' + (variables - 1 - j)); // Variable sin negación
                } else {
                    printf("%c'", 'A' + (variables - 1 - j)); // Variable negada
                }
            }
        }
    }
    printf("\n");
}