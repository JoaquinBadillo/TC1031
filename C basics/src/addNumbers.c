#include <stdio.h>

int main(void) {
  int num1, num2, num3, res1, res2;

  printf("Anote el primer numero\n");
  scanf("%d", &num1);

  printf("Anote el segundo numero\n");
  scanf("%d", &num2);

  res1 = num1 + num2;
  res2 = res1 * 2;

  printf("El resultado de la suma es: %d, \ny el de la multiplicacion es: %d\n", res1, res2);

  return 0;
}
