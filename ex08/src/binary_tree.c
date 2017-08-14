#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

node_t  *allocnode()
{
  node_t   *curr;
  curr = (node_t*) malloc(sizeof(node_t));
  curr->left = NULL;
  curr->right = NULL;
  return curr;
}

node_t  *insert(node_t *root, char *key, void *data)
{
  if(root == NULL)
  {
    root  = allocnode();
    root->key = key;
    root->data = data;
  }
  else if(root->key < key)
    root->left =  insert(root->left, key, data);
  else
    root->right = insert(root->right, key, data);
  return root;
}

void    print_node(node_t *node)
{
  if(!node) return;
  printf(node->data);
}

void    visit_tree(node_t *node, void (*fp)(node_t *root))
{
  fp(node);
  if(node->right)
    visit_tree(node->right, fp);
  if(node->left)
    visit_tree(node->left, fp);
}

void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
  if(node->right)
    destroy_tree(node->right, fdestroy);
  if(node->left)
    destroy_tree(node->left, fdestroy);

  fdestroy(node);
  free(node);
  node = NULL;
}


