/*
 * pointers_demo.c - Pointers - Khái niệm khó nhất và quan trọng nhất trong C
 * 
 * Nội dung:
 * - Pointer basics: declaration, initialization
 * - Address operator (&) và dereference operator (*)
 * - Pointer arithmetic
 * - Pointers và arrays
 * - Function pointers (advanced)
 * - Common pointer mistakes
 * 
 * ⚠️  QUAN TRỌNG: Đây là chủ đề khiến nhiều người từ bỏ C.
 *     Hãy đọc kỹ và thực hành nhiều!
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void demonstrate_basic_pointers(void);
void demonstrate_pointer_arithmetic(void);
void demonstrate_pointers_and_arrays(void);
void demonstrate_dynamic_memory(void);
void swap_using_pointers(int *a, int *b);

int main() {
    printf("=== POINTERS - KHÁI NIỆM QUAN TRỌNG NHẤT TRONG C ===\n\n");
    
    printf("💡 Pointer là gì?\n");
    printf("   - Pointer là biến chứa địa chỉ bộ nhớ của biến khác\n");
    printf("   - Cho phép truy cập gián tiếp đến dữ liệu\n");
    printf("   - Là nền tảng của dynamic memory, data structures\n\n");
    
    demonstrate_basic_pointers();
    demonstrate_pointer_arithmetic();
    demonstrate_pointers_and_arrays();
    demonstrate_dynamic_memory();
    
    return 0;
}

void demonstrate_basic_pointers(void) {
    printf("1. POINTER BASICS:\n");
    
    // Declare và initialize variables
    int x = 42;
    int y = 100;
    
    // Declare pointers
    int *ptr;           // Pointer to int (uninitialized - dangerous!)
    int *ptr1 = &x;     // Pointer to x (good practice)
    int *ptr2 = &y;     // Pointer to y
    
    printf("Variable values:\n");
    printf("  x = %d, address = %p\n", x, (void*)&x);
    printf("  y = %d, address = %p\n", y, (void*)&y);
    
    printf("\nPointer values:\n");
    printf("  ptr1 = %p (points to x)\n", (void*)ptr1);
    printf("  ptr2 = %p (points to y)\n", (void*)ptr2);
    
    printf("\nDereferencing pointers:\n");
    printf("  *ptr1 = %d (value at address ptr1)\n", *ptr1);
    printf("  *ptr2 = %d (value at address ptr2)\n", *ptr2);
    
    // Modify values through pointers
    *ptr1 = 999;
    printf("\nAfter *ptr1 = 999:\n");
    printf("  x = %d (changed!)\n", x);
    printf("  *ptr1 = %d\n", *ptr1);
    
    // Pointer reassignment
    ptr1 = &y;  // Now ptr1 points to y
    printf("\nAfter ptr1 = &y:\n");
    printf("  *ptr1 = %d (now points to y)\n", *ptr1);
    
    // Demonstrate swap function
    printf("\n--- SWAP DEMO ---\n");
    int a = 10, b = 20;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap_using_pointers(&a, &b);
    printf("After swap:  a=%d, b=%d\n", a, b);
    
    printf("\n");
}

void demonstrate_pointer_arithmetic(void) {
    printf("2. POINTER ARITHMETIC:\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Points to first element
    
    printf("Array: [10, 20, 30, 40, 50]\n");
    printf("Pointer arithmetic:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("  ptr+%d = %p, *(ptr+%d) = %d\n", 
               i, (void*)(ptr+i), i, *(ptr+i));
    }
    
    // Increment pointer
    printf("\nIncrementing pointer:\n");
    ptr = numbers;  // Reset to start
    for (int i = 0; i < 5; i++) {
        printf("  *ptr = %d, ptr = %p\n", *ptr, (void*)ptr);
        ptr++;  // Move to next element
    }
    
    // Pointer subtraction
    int *start = numbers;
    int *end = numbers + 4;
    printf("\nPointer difference: end - start = %ld elements\n", end - start);
    
    printf("\n");
}

void demonstrate_pointers_and_arrays(void) {
    printf("3. POINTERS AND ARRAYS:\n");
    
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;  // Array name is pointer to first element
    
    printf("Array elements using different notations:\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);           // Array notation
        printf("  *(arr+%d) = %d\n", i, *(arr+i));       // Pointer arithmetic
        printf("  p[%d] = %d\n", i, p[i]);               // Pointer as array
        printf("  *(p+%d) = %d\n", i, *(p+i));           // Pointer arithmetic
        printf("\n");
    }
    
    // String as char array
    printf("String manipulation with pointers:\n");
    char str[] = "Hello";
    char *char_ptr = str;
    
    printf("Original string: %s\n", str);
    while (*char_ptr != '\0') {
        printf("  *char_ptr = '%c' at %p\n", *char_ptr, (void*)char_ptr);
        char_ptr++;
    }
    
    printf("\n");
}

void demonstrate_dynamic_memory(void) {
    printf("4. DYNAMIC MEMORY ALLOCATION:\n");
    
    // Allocate memory for array
    int size = 5;
    int *dynamic_array = malloc(size * sizeof(int));
    
    // Check if allocation successful
    if (dynamic_array == NULL) {
        printf("❌ Memory allocation failed!\n");
        return;
    }
    
    printf("✅ Allocated memory for %d integers\n", size);
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        dynamic_array[i] = (i + 1) * 10;  // 10, 20, 30, 40, 50
    }
    
    printf("Dynamic array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    
    // Resize array using realloc
    size = 8;
    dynamic_array = realloc(dynamic_array, size * sizeof(int));
    
    if (dynamic_array == NULL) {
        printf("❌ Memory reallocation failed!\n");
        return;
    }
    
    // Initialize new elements
    for (int i = 5; i < size; i++) {
        dynamic_array[i] = (i + 1) * 10;
    }
    
    printf("Resized array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    
    // Always free allocated memory!
    free(dynamic_array);
    dynamic_array = NULL;  // Good practice to avoid dangling pointer
    printf("✅ Memory freed\n\n");
}

void swap_using_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * KINH NGHIỆM 15 NĂM VỀ POINTERS:
 * 
 * 1. POINTER DECLARATION:
 *    int *ptr;     // Correct: * is part of variable name
 *    int* ptr;     // Also correct but misleading
 *    int *p1, *p2; // Both are pointers
 *    int* p1, p2;  // p1 is pointer, p2 is int (confusing!)
 * 
 * 2. INITIALIZATION:
 *    int *ptr = NULL;  // ✅ Good: explicitly initialized
 *    int *ptr;         // ❌ Dangerous: garbage value
 *    
 * 3. NULL POINTER CHECKS:
 *    if (ptr != NULL) {
 *        *ptr = 10;    // Safe to dereference
 *    }
 * 
 * 4. COMMON MISTAKES:
 *    - Dereferencing NULL pointer → Segmentation fault
 *    - Using uninitialized pointer → Undefined behavior
 *    - Memory leaks (forget to call free())
 *    - Double free (calling free() twice)
 *    - Use after free (accessing freed memory)
 *    - Buffer overflow in dynamic arrays
 * 
 * 5. DEBUGGING TIPS:
 *    - Always initialize pointers
 *    - Check malloc() return value
 *    - Set pointers to NULL after free()
 *    - Use valgrind to detect memory errors
 *    - Print pointer values for debugging
 * 
 * 6. BEST PRACTICES:
 *    - One malloc() for each free()
 *    - Check for NULL before dereferencing
 *    - Use const for read-only data
 *    - Avoid pointer arithmetic unless necessary
 *    - Comment complex pointer operations
 * 
 * 7. TẠI SAO POINTERS KHÓ?
 *    - Abstract concept (địa chỉ bộ nhớ)
 *    - Multiple levels of indirection
 *    - Easy to make mistakes with big consequences
 *    - Debugging pointer errors is hard
 * 
 * 8. TẠI SAO POINTERS QUAN TRỌNG?
 *    - Dynamic memory allocation
 *    - Efficient array/string manipulation
 *    - Implementing data structures (linked list, tree)
 *    - Function parameters (pass by reference)
 *    - System programming
 * 
 * LỜI KHUYÊN CỦA GIÁO VIÊN:
 * "Đừng sợ pointers. Hãy thực hành từng bước một cách chậm rãi.
 *  Vẽ diagrams để visualize memory layout. 
 *  Một khi hiểu pointers, bạn sẽ hiểu C và computer science sâu hơn!"
 */