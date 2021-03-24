#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song{
  char *songName;
  char *artist;
  int length;
};

void teste() { 
  struct song s;
  char *lengthInput;

  s.songName = "music1";
  s.artist = "artist1";
  s.length = 1;

  printf("%s\n", s.songName);
  printf("%s\n", s.artist);
  printf("%d\n", s.length);


  printf("Insira o nome da musica: \n");
  scanf("%s", &s.songName);
  printf("%s\n", &s.songName);

  printf("Insira o nome do artista: \n");
  scanf("%s", &s.artist);
  printf("%s\n", &s.artist);

  printf("Insira o tempo de duracao da musica (em segundos): \n");
  scanf("%d", &s.length);
  printf("%d\n", s.length);

}
int main(void) {
  teste();

  
  return 0;
}