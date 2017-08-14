#include <stdlib.h>
#include <string.h>
#include "my_string.h"

stream_t        *string_init()
{
  stream_t      *stream = (stream_t*) malloc(sizeof(stream_t));

  stream->str = NULL;
  stream->size = stream->limit = 0;

  return stream;
}

stream_t        *string_create(char* str)
{
  stream_t      *s;
  int           size, n;

  size = strlen(str);
  n = size / BUF_SIZE + 1;

  s = string_init();
  s->str = (char*) malloc (n * BUF_SIZE * sizeof(char));

  strcpy(s->str, str);
  s->size = size;
  s->limit = n * BUF_SIZE;

  return s;
}

void            add(stream_t* ptr, char* str)
{
  int           size;

  size = strlen(str);

  for(int i = 0; i < size; i++)
    ptr->str[ptr->size + i] = str[i];

  ptr->size += size;
  ptr->str[ptr->size] = '\0';
}

void string_append(stream_t *ptr, char* str)
{
  int size;

  if(!ptr)
    ptr = string_create(str);
  else {
    size = strlen(str);

    if(ptr->size + size >= ptr->limit)
    {
      ptr->str = (char*) realloc (ptr->str, ptr->limit +  BUF_SIZE);
      ptr->limit +=  BUF_SIZE;
      ptr->str[ptr->size + size] = '\0';
    }

    add(ptr, str);
  }
}

void string_destroy(stream_t *stream)
{
  free(stream->str);
  free(stream);

  stream = NULL;
}
