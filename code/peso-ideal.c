#include <stdio.h>
int main() {
   double altura;
   double pesoideal;
   printf("Digite sua altura: ");
   scanf("%lf", &altura);
   pesoideal = 72.7*altura-58;
   printf("Seu peso ideal: %.lf\n", pesoideal);
   return 0;
}