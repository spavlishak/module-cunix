#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

hashtable_t     *hash_create(unsigned int size)
{
  hashtable_t *hashTable;

  if(size != 0)
  {
    hashTable = malloc(sizeof(hashtable_t));
    hashTable->size = size;
    hashTable->table = (void**)malloc(size * sizeof(void*));
    for (int i=0; i<size; i++)
      hashTable->table[i] = NULL;
    return hashTable;
  }
  else return NULL;
}

void            hash_destroy(hashtable_t *ht, void (*fp)(void *data))
{
  node_t *curr;
  if (ht != NULL)
  {
    for (int i=0; i<ht->size; i++)
    {
      curr = ht->table[i];
      list_destroy(&curr, fp);
    }
    free(ht->table);
    ht->table=NULL;
    free(ht);

  }
}
unsigned int    hash_func(char *key)
{
  if (key == NULL) return 0;

  int code;
  int i;

  i = 0;
  code = 0;
  while(key[i] != '\0')
  {
    code +=(int)key[i];
    i++;
  }
  return code;

}

void            hash_set(hashtable_t *ht, char *key, void *ptr, void (*fp)(void *data))
{
  int code;
  code = hash_func(key) % ht->size;
  if (ht->table[code] == NULL)
   ht->table[code] = list_create(ptr);
  else
  list_push (ht->table[code], ptr);

fp(key);
}

void            *hash_get(hashtable_t *ht, char *key)
{
node_t *curr;
curr = ht->table[hash_func(key) % ht->size];
if (curr == NULL) return NULL;
else
  return curr->data;
}
