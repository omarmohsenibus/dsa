# Foundational Data Structure 1: The Dynamic Array (Vector)

A dynamic array provides the interface of a standard array but abstracts away the memory allocation, resizing itself when it runs out of space.

State Requirements (What the struct must hold):
- A pointer to the dynamically allocated block of memory. 
- The capacity: The total number of elements the current memory block can hold.
- The size: The actual number of elements currently stored in the array.

Behavioral Requirements (Operations to implement):
- Initialization: Allocate a small initial block of memory (e.g., room for 4 or 8 elements). Set size to 0 and capacity to the initial amount.

- Append (Push Back): Add an element to the end. 
  - Crucial Rule: If size == capacity before appending, you must allocate a new block of memory that is double the current capacity, copy the old data over, free the old memory, and then append the new element.

- Insert at Index: Place an element at a specific index. You must shift all subsequent elements one position to the right. Apply the same resizing logic as above if the array is full.

- Remove at Index: Remove an element and shift all subsequent elements one position to the left to fill the gap. Decrement the size.

- Get/Set: Read or overwrite an element at a specific index. 
  - Crucial Rule: Implement strict bounds checking. If the requested index is out of bounds (less than 0 or greater than/equal to size), the function must fail gracefully.

- Destruction: A function to completely free the underlying memory block and reset the struct to prevent memory leaks.