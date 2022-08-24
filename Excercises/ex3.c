// Longitud de cadenas

#include <stdio.h>

#define MAX_LENGTH 128

int main(void) {
    char string1[MAX_LENGTH];
    printf("Introduce una cadena de texto sin espacios: ");

    fgets(string1, MAX_LENGTH, stdin);

    int i=0;
    while(string1[i+1] != '\0') {
        printf("Letra: %c\n", string1[i]);
        i++;
    }

    printf("Numero de caracteres: %d\n", i);

    return 0;
}