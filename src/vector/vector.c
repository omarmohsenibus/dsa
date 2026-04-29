#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <vector.h>
#include <stdint.h>

typedef struct vector {
  size_t data_sz;
  size_t capacity;
  size_t size;
  void *data;
} vector;

vector *vector_init(const size_t initial_capacity, const size_t data_sz) {
  if (initial_capacity == 0 || data_sz == 0)
    return NULL;
  if (data_sz > SIZE_MAX / initial_capacity)
    return NULL;
  vector *ret = malloc(sizeof(vector));
  if (ret == NULL)
    return NULL;

  ret->capacity = initial_capacity;
  ret->data_sz = data_sz;
  ret->size = 0;

  ret->data = malloc(data_sz * initial_capacity);
  if (ret->data == NULL) {
    free(ret);
    return NULL;
  }

  return ret;
}

bool vector_push_back(vector *v, const void *element) {
  assert(v != NULL);
  if (v->size == v->capacity) {
    void *data = realloc(v->data, 2 * v->capacity * v->data_sz);
    if (data == NULL)
      return false;
    v->capacity = 2 * v->capacity;
    v->data = data;
  }
  char *data = v->data;
  memcpy(&data[v->size * v->data_sz], element, v->data_sz);
  v->size += 1;

  return true;
}

bool vector_pop_back(vector *v) {
  assert(v != NULL);
  assert(v->size != 0);
  if ((double) v->size <= 0.25 * (double) v->capacity) {
    // shrink to fit
    void *data = realloc(v->data, (v->capacity / 2) * v->data_sz);
    if (data == NULL)
      return false;
    v->capacity = v->capacity / 2;
    v->data = data;
  }
  v->size -= 1; // free lazy
  return true;
}

void *vector_get_at_index_internal(const vector *v, const size_t index) {
  char *data = v->data;

  return data + index * v->data_sz;
}

void *vector_get_at_index(const vector *v, const size_t index) {
  if (v == NULL || v->data == NULL || index >= v->size)
    return NULL;

  return vector_get_at_index_internal(v, index);
}


void vector_delete(vector *v) {
  assert(v != NULL);
  free(v->data);
  v->data = NULL;
  free(v);
  v = NULL;
}

size_t vector_get_size(const vector *v) {
  assert(v != NULL);
  return v->size;
}

size_t vector_get_capacity(const vector *v) {
  assert(v != NULL);
  return v->capacity;
}

bool vector_insert_at_index(vector *v, const size_t index, const void *element) {
  if (v == NULL || v->data == NULL)
    return false;
  if (index > v->size)
    return false;

  if (index == v->size)
    return vector_push_back(v, element);

  void *target = vector_get_at_index_internal(v, index);
  void *next_slot = target + v->data_sz;
  const size_t bytes_to_move = (v->size - index) * v->size;

  // Shifting: starting from `target` (index position) move `bytes_to_move` bytes into new position (index + 1)
  memmove(next_slot, target, bytes_to_move);
  memcpy(target, element, v->data_sz);

  v->size += 1;
  return true;
}

bool vector_delete_at_index(vector *v, const size_t index, void *delete_element) {
  if (v == NULL || v->data == NULL)
    return false;

  if (index >= v->size)
    return false;

  void *target = vector_get_at_index_internal(v, index);

  if (delete_element != NULL)
    memcpy(delete_element, target, v->data_sz);


  const void *source = target + v->data_sz;
  const size_t bytes_to_move = (v->size - index - 1) * v->size;
  // Shifting: starting from `source` (index position) move `bytes_to_move` bytes into new position `target`
  memmove(target, source, bytes_to_move);
  v->size -= 1;

  return true;
}
