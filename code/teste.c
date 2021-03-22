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


  // Vars
  char song[50];
  char artist[50];
  char length_char[50];
  int length;
  int i = -1;    
  int j = 0;    
  char line[255];

  // Loop to retrieve lines within file
  while(fgets(line, sizeof line, fpointer) != NULL) {

    // Loop vars
    char c = line[0];
    i = -1;
    j = 0;
    

    // First loop to retrive Song Name
    while (c != ',') { 
      s.songName[i++] = c;
      c = line[j++];
    }
    s.songName[i++] = '\0';
    printf("%s\n", s.songName);



    // Reset loop vars
    i = 0; 
    c = line[j++];

    // Second Loop to retrive Artists
    while (c != ',') { 
      s.artist[i++] = c;
      c = line[j++];
    }
    s.artist[i++] = '\0';
    printf("%s\n", s.artist);
    


    // Reset loop vars
    i = 0; 
    c = line[j++];

    // Third Loop to retrieve Length
    while (c != '\n') { 
      length_char[i++] = c;
      c = line[j++];
    }
    length_char[i++] = '\0';

    // Convert string to int
    s.length = atoi(length_char);
    printf("%d\n", s.length);
  }



  fclose(fpointer); 

  return 0;
}