#include <stdio.h>
#include <stdlib.h>

struct node {
  int length; // node will store int length 
  char artist; // node will store char artist name
  char songName; // node will store char song name

  struct node *right_child; // right child
  struct node *left_child; // left child
};

struct node* search(struct node *root, int x) {
  if(root==NULL || root->length==x) //if root->length is x then the element is found
    return root;
  else if(x>root->length) // x is greater, so we will search the right subtree
    return search(root->right_child, x);
  else //x is smaller than the length, so we will search the left subtree
    return search(root->left_child, x);
};

struct node* find_minimum(struct node *root) {
  if(root == NULL)
    return NULL;
  else if(root->left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root->left_child); // left most element will be minimum
  return root;
}

//function to create a node

struct node* new_node(int x) {
  struct node *p;
  p = malloc(sizeof(struct node));
  p->length = x;
  p->left_child = NULL;
  p->right_child = NULL;

  return p;
}


struct node* insert(struct node *root, int x) {
  //searching for the place to insert
  if(root == NULL)
    return new_code(x);
  else if(x>root->length) // x is greater. Should be inserted to right
    root->right_child = insert(root->right_child, x);
  else // x is smaller should be inserted to left
    root->left_child = insert(root->left_child, x);
  return root;
}


// funnction to delete a node
struct node* delete(struct node *root, int x) {
  //searching for the item to be deleted
  if(root==NULL)
    return NULL;
  if (x>root->length)
    root->right_child = delete(root->right_child, x);
  else if(x<root->length)
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
      root->length = temp->length;
      root->right_child = delete(root->right_child, temp->length);
    }
  }
  return root;
}



int main() {

   return 0;
}