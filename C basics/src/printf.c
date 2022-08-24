#include <stdio.h>

int main(void) {
  int wholeNumber = 1234;
  float decimalNumber = 3.1416;
  char letter = 'a';

  printf("Number: %d\n", wholeNumber);
  printf("Decimal Number: %f\n", decimalNumber);
  printf("Letter: %c\n", letter);
  printf("Everything %d %f %c\n", wholeNumber, decimalNumber, letter);
  printf("Everything: %d %d %d\n", 1, 2, 3);

  return 0;
}
