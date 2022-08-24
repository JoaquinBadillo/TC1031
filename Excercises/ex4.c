// Suma del triangular superior

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    srand(time(NULL));
    int n;

    printf("Ingrese la longitud de la matriz: ");
    scanf("%i", &n);

    int matrix[n][n];

    int i;
    int j;

    int sum = 0;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
            sum += (i < j ? matrix[i][j] : 0); 
        }
        printf("\n");
    }

    printf("Suma del triangular superior: %i\n", sum);

    return 0;   
}