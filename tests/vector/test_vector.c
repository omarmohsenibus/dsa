#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <vector.h>

void vector_init_std_case() {
  const int initial_capacity = 10;
  const int data_sz = sizeof(int);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);
  vector_delete(v);
}

void vector_init_small_case() {
  const int initial_capacity = 1;
  const int data_sz = sizeof(char);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);
  vector_delete(v);
}

void vector_init_assertion_case() {
  const int initial_capacity = 0;
  const int data_sz = sizeof(char);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);
  vector_delete(v);
}

void vector_init_big_data_sz_case() {
  struct my_struct {
    char x[1024];
  };
  const int initial_capacity = 1;
  const int data_sz = sizeof(struct my_struct);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);
  vector_delete(v);
}

void vector_push_back_std_case() {
  const int initial_capacity = 10;
  const int data_sz = sizeof(int);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);

  const int a = 1;
  const int b = 2;
  const int c = 3;
  vector_push_back(v, &a);
  vector_push_back(v, &b);
  vector_push_back(v, &c);

  const int *pa = vector_get_at_index(v, 0);
  const int *pb = vector_get_at_index(v, 1);
  const int *pc = vector_get_at_index(v, 2);

  assert(*pa == a);
  assert(*pb == b);
  assert(*pc == c);

  vector_delete(v);
}

void vector_push_back_std_case_str() {
  const int initial_capacity = 10;
  const int data_sz = sizeof(char *); // data size is size of a char *
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);

  const char str_a[] = "String A";
  const char str_b[] = "String B";
  const char str_c[] = "String C";

  const char *pstr_a = str_a;
  const char *pstr_b = str_b;
  const char *pstr_c = str_c;

  vector_push_back(v, &pstr_a);
  vector_push_back(v, &pstr_b);
  vector_push_back(v, &pstr_c);

  const char **pa = vector_get_at_index(v, 0);
  const char **pb = vector_get_at_index(v, 1);
  const char **pc = vector_get_at_index(v, 2);

  assert(strcmp(*pa, str_a) == 0);
  assert(strcmp(*pb, str_b) == 0);
  assert(strcmp(*pc, str_c) == 0);

  vector_delete(v);
}

void vector_insert_at_index_std_case() {
  const int initial_capacity = 5;
  const int data_sz = sizeof(int);
  vector *v = vector_init(initial_capacity, data_sz);
  assert(v != NULL);
  assert(vector_get_size(v) == 0);
  assert(vector_get_capacity(v) == initial_capacity);

  const int a = 10;
  const int b = 20;
  const int c = 30;
  vector_push_back(v, &a);
  vector_push_back(v, &c);

  vector_insert_at_index(v, 1, &b);

  const int *pa = vector_get_at_index(v, 0);
  const int *pb = vector_get_at_index(v, 1);
  const int *pc = vector_get_at_index(v, 2);

  assert(*pa == a);
  assert(*pb == b);
  assert(*pc == c);
  assert(vector_get_size(v) == 3);

  vector_delete(v);
}


int main(void) {
  //vector_init_std_case();
  //vector_init_small_case();
  //vector_init_big_data_sz_case();
  // vector_init_assertion_case();


  // vector_push_back_std_case();
  // vector_push_back_std_case_str();
  vector_insert_at_index_std_case();

  return 0;
}
