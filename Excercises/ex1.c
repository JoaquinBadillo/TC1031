// Manipulacion de arreglos

#include <stdio.h>

int main(void) {
    int arr[5];
    int arr2[5];

    int* pointer1 = &arr[0];

    int i;

    for (i=0; i < 5; i++)
    {
        printf("Ingresa un entero: ");
        scanf("%i", pointer1 + i);
        arr2[i] = 2 * arr[i];
    }

    for (i=0; i < 5; i++)
      printf("%d ", arr2[i]);  

    printf("\n");

    return 0;
}