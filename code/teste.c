#include <stdio.h>
struct horario {
  int horas;
  int minutos;
  int segundos;
};
int main(void) {

   struct horario agora;

   agora.horas = 15;
   agora.minutos = 17;
   agora.segundos = 30;

   printf("%i:%i:%i", agora.horas, agora.minutos, agora.segundos);

   return 0;
}