#include <stdio.h>
#include <string.h>
int main(void) {
  int a, *b;
  a = 15;
  *b = a;
  printf("Valor de p: %d. \n", *b);
  return 0;
}