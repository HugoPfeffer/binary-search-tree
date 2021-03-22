#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char songName[50];
  char artist[50];
  int length;
}Song;

typedef struct {
  Song song;

  struct Node *right_child; // right child
  struct Node *left_child; // left child
}Node;



int main ()
{
  Song s;






  // open song-list
  FILE * fpointer = fopen("song-list.txt", "r");
  char song[50];
  char artist[50];
  char length_char[50];
  int length;
  char buf[] ="abc/qwe/ccd";
  int i = -1;    
  int j = 0;    
  
  char line[255];

  while(fgets(line, sizeof line, fpointer) != NULL) {
    // printf("%s\n", line);
    char c = line[0];
    

    i = -1;
    j = 0;
    
    while (c != ',') { 
      s.songName[i++] = c;
      c = line[j++];
    }
    s.songName[i++] = '\0';

    printf("%s\n", s.songName);




    i = 0; 
    c = line[j++];

    while (c != ',') { 
      s.artist[i++] = c;
      c = line[j++];
    }
    s.artist[i++] = '\0';


    printf("%s\n", s.artist);
    
    
    
    
    i = 0; 
    c = line[j++];

    while (c != '\n') { 
      length_char[i++] = c;
      c = line[j++];
    }
    length_char[i++] = '\0';


    s.length = atoi(length_char);
    printf("%d\n", s.length);
  }



  fclose(fpointer); 

  return 0;
}