#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

node_t  *list_create(void *data) {
  node_t *el = (node_t*) malloc(sizeof(node_t));
  el->data = data;
  el->data = NULL;
  return el;
}

void    list_destroy(node_t **head, void (*fp)(void *data)) {
  if ((*head) == NULL) return;
  if ((*head) -> next)
    list_destroy(&((*head) -> next), fp);
  fp ((*head) -> data);
  free (*head);
  *head == NULL;
}

void    list_push(node_t *head, char *key, void *data) {
  node_t* curr = head;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = list_create(data);
  curr->next->next = NULL;
}

void    list_unshift(node_t **head, char *key, void *data) {
  node_t* curr = list_create(data);
  curr->next = *head;
  *head = curr;
}

void    *list_pop(node_t **head) {
  if((*head)->next == NULL)
  {
    void *data = (*head)->data;
    free(*head);
    head = NULL;
    return data;
  }
  node_t *curr;
  curr = *head;
  while (curr->next->next != NULL) curr = curr->next;
  void *data = curr->next->data;
  if (curr->next->data) free(curr->next->data);
  free(curr->next);
  curr->next = NULL;
  return data;
}

void    *list_shift(node_t **head) {
  node_t* curr = *head;
  *head = (*head) -> next;
  free(curr->data);
  free(curr);
  curr = NULL;
}

void    *list_remove(node_t **head, int pos) {
  node_t *curr;
  curr  = *head;

  for(int i = 0; i<pos-1; i++)
  {
    if(curr->next->next == NULL) return NULL;
    curr = curr->next;
  }
  void *data = curr->next->data;
  node_t *tmp;
  tmp = curr->next;
  curr->next = curr->next->next;
  free(tmp->data);
  free(tmp);
  tmp = NULL;
  return data;
}

void    list_print(node_t *head) {
  node_t* curr = head;
  while(curr != NULL)
  {
    printf("%s  ", curr->data);
    curr = curr->next;
  }
}

void    list_visitor(node_t *head, void (*fp)(void *data)) {
  node_t *curr;

  curr = head;
  while(curr != NULL)
  {
    fp(curr->data);
    curr = curr->next;
  }
}


