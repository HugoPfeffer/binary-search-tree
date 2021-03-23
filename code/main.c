#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct song{
  char *songName;
  char *artist;
  int length;
};


struct node {
  struct song s;

  struct node *right_child; // right child
  struct node *left_child; // left child
};

struct node* search(struct node *root, int x) {

  if(root==NULL) //if root->length is x then the element is found
  {
    return root;
  }
  else { 
    if(root->s.length==x) {
      printf("%s->%s\n", root->s.songName, root->s.artist);
    }
    if(x>root->s.length) // x is greater, so we will search the right subtree
    {
      return search(root->right_child, x);
    }
    else //x is smaller than the length, so we will search the left subtree
    {
      return search(root->left_child, x);
    }
  }
};

struct node* find_minimum(struct node *root) {
  if(root == NULL)
    return NULL;
  else if(root->left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root->left_child); // left most element will be minimum
  return root;
}

//function to create a node

struct node* new_node(struct song song) {
  struct node *p;
  p = malloc(sizeof(struct node));
  p->s.length = song.length;
  p->s.artist = song.artist;
  p->s.songName = song.songName;
  p->left_child = NULL;
  p->right_child = NULL;

  return p;
}


struct node* insert(struct node *root, struct song song) {
  //searching for the place to insert
  if(root == NULL)
    return new_node(song);
  else if(song.length>root->s.length) // x is greater. Should be inserted to right
    root->right_child = insert(root->right_child, song);
  else // x is smaller should be inserted to left
    root->left_child = insert(root->left_child, song);
  return root;
}


// funnction to delete a node
struct node* delete(struct node *root, int x) {
  //searching for the item to be deleted
  if(root==NULL)
    return NULL;
  if (x>root->s.length)
    root->right_child = delete(root->right_child, x);
  else if(x<root->s.length)
    root->left_child = delete(root->left_child, x);
  
  else {
    //No Children
    if(root->left_child==NULL && root->right_child==NULL) {
      free(root);
      return NULL;
    }

    //One Child
    else if(root->left_child==NULL || root->right_child==NULL) {
      struct node *temp;
      if(root->left_child==NULL)
        temp = root->right_child;
      else
        temp = root->left_child;
      free(root);
      return temp;
    } 

    //Two Children
    else {
      struct node *temp = find_minimum(root->right_child);
      root->s.length = temp->s.length;
      root->right_child = delete(root->right_child, temp->s.length);
    }
  }
  return root;
}



void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->s.length); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

//////////////////








int main() {
  struct node *root;
  struct song s;


  // open song-list
  FILE * fpointer = fopen("song-list.txt", "r");


  // Vars
  char *length_char;
  int i = -1;    
  int j = 0;    
  char line[255];
  bool root_created = false;
  bool searchInput = true;
  int userInput; 

  // Loop to retrieve lines within file
  while(fgets(line, sizeof line, fpointer) != NULL) {

    // Loop vars
    char c = line[0];
    i = -1;
    j = 0;
    

    // First loop to retrive Song Name
    s.songName = (char*) malloc(50*sizeof(char));
    while (c != ',') { 
      s.songName[i++] = c;
      c = line[j++];
    }
    s.songName[i++] = '\0';
    // printf("%s\n", song);


    // Reset loop vars
    i = 0; 
    c = line[j++];

    // Second Loop to retrive Artists
    s.artist = (char*) malloc(50*sizeof(char));
    while (c != ',') { 
      s.artist[i++] = c;
      c = line[j++];
    }
    s.artist[i++] = '\0';
    // printf("%s\n", s.artist);
    


    // Reset loop vars
    i = 0; 
    c = line[j++];

    // Third Loop to retrieve Length
    length_char = (char*) malloc(50*sizeof(char));
    while (c != '\n') { 
      length_char[i++] = c;
      c = line[j++];
    }
    length_char[i++] = '\0';

    // Convert string to int
    s.length = atoi(length_char);
    // printf("%d\n", length);
  
  
    if (root_created == false) { 
      root = new_node(s);
      root_created = true;
    }
    else {
      insert(root, s);
    }
  }

  fclose(fpointer); 

    

  // while (searchInput == true) { 
  //   printf("Insira o tamanho em segundos da musica desejada: ");
  //   scanf("%d", &userInput);
    
  //   struct node* result = search(root, userInput);

  //   char resposta;
  //   printf("Deseja pesquisar novamente? ");
  //   scanf("%s", resposta);

  //   if(resposta == 'n') {
  //     break;
  //   }
  // }
  
  printf("Insira o tamanho em segundos da musica desejada: ");
  scanf("%d", &userInput);
  struct node* result = search(root, userInput);


  


  // inorder(root);





  return 0;
}