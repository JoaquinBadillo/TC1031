// Comparacion de cadenas

#include <stdio.h>

#define MAX_LENGTH 128 // Longitud maxima de las cadenas para evitar que el usuario haga cosas inseguras

int main(void) {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    printf("Cadena de texto 1 (max 128 caracteres): ");
    fgets(string1, MAX_LENGTH, stdin);

    printf("Cadena de texto 2 (max 128 caracteres): ");
    fgets(string2, MAX_LENGTH, stdin);

    int i = 0; // Indice
    short j = 0; // Booleano

    while (string1[i] != '\0') {
        if (string2[i] == '\0') {
            j = 1;
            break;
        } 
        else if(string1[i] != string2[i]) {
            j = 1;
            break;
        }
        i++;
    }

    if (j) {
        printf("Las cadenas no son iguales\n");
    } else {
        printf("Las cadenas son iguales\n");
    }

    return 0;
}