#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <stddef.h>
typedef struct vector vector;

/**
 * @brief Initializes a new generic vector
 * Allocates memory for both the vector metadata structure and internal data buffer
 * This implementation uses a defensive API; it validates and checks for
 * potentials integer overflows before allocation
 * @param initial_capacity: The number of elements the vector can hold before its first resize. Must be greater than 0
 * @param data_sz: The size of each element in bytes (use sizeof()). Must be greater than 0
 * @return A pointer to the initialized vector on success.
 * @return NULL if:
 *  - initial_capacity or data_sz is 0.
 *  - The requested memory would cause a size_t overflow
 *  - malloc() fails
 *
 * @note The vector performs a <b>shallow copy</b> of the elements.
 * @warning The caller has the ownership of the returned pointer and must deallocate
 * it using @see vector_delete to avoid memory leaks
 */
extern vector *vector_init(size_t initial_capacity, size_t data_sz);

/**
 * @brief Retrieves a pointer to the element at the specified index.
 * Performs bound checking to ensure the requested index is within the currently initialized size of the vector
 * @param v: Pointer to the vector instance.
 * @param index: The zero-based index of the element to retrieve.
 * @return: void * A pointer to the element at the given index.
 * @return NULL if:
 *   - vector is NULL
 *   - internal data buffer is NULL
 *   - index out of bound
 * @note Because this returns a generic void pointer, the caller must cast the result to the appropriate type.
 * @warning The returned pointer points directly into the vector's internal buffer. Modifying the vector internal data
 * may trigger a realloc, that would invalidate this pointer.
 */
extern void *vector_get_at_index(const vector *v, size_t index);

/**
 * Add data to the dynamic array
 * @param v: @struct vector
 * @param element
 */
extern bool vector_push_back(vector *v, const void *element);

/**
 * Remove data to the dynamic array
 * @param v: @struct vector
 */
extern bool vector_pop_back(vector *v);

/**
 * @brief Inserts an element at a specific index, shifting subsequent elements
 * @param v: Pointer to the vector
 * @param index: Target position (must be <= size)
 * @param element: Pointer to the data to be copied
 * @return true on success, false on OOM or invalid index.
 * @warning O(N) due to shifting memory
 */
extern bool vector_insert_at_index(vector *v, size_t index, const void *element);


extern void vector_set_at_index();

extern size_t vector_get_size(const vector *v);

extern size_t vector_get_capacity(const vector *v);

extern void vector_delete(vector *v);


#endif
