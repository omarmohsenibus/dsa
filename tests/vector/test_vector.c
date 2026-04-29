#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <string.h>
#include <vector.h>

Test(vector_init, std_case) {
  vector *v = vector_init(10, sizeof(int));
  cr_assert_not_null(v);
  cr_expect(vector_get_size(v) == 0);
  cr_expect(vector_get_capacity(v) == 10);
  vector_delete(v);
}

Test(vector_init, small_case) {
  vector *v = vector_init(1, sizeof(int));
  cr_assert_not_null(v);
  cr_expect(vector_get_size(v) == 0);
  cr_expect(vector_get_capacity(v) == 1);
  vector_delete(v);
}

Test(vector_init, big_data_struct) {
  struct my_struct { char x[1024]; };
  vector *v = vector_init(1, sizeof(struct my_struct));
  cr_assert_not_null(v);
  cr_expect(vector_get_size(v) == 0);
  cr_expect(vector_get_capacity(v) == 1);
  vector_delete(v);
}

Test(vector_init, invalid_capacity) {
  const vector *v = vector_init(0, sizeof(char));
  cr_assert_null(v, "vector_init: Must be Null");
}