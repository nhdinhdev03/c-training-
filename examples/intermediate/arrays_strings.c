/*
 * arrays_strings.c - Arrays và Strings trong C
 * 
 * Nội dung quan trọng:
 * - Array declaration và initialization
 * - Array indexing và bounds checking
 * - String manipulation
 * - Multi-dimensional arrays
 * - Array as function parameters
 * 
 * Đây là foundation để hiểu pointers và memory management!
 */

#include <stdio.h>
#include <string.h>  // For string functions

// Function prototypes
void print_array(int arr[], int size);
void print_string_info(char str[]);
int find_max(int arr[], int size);

int main() {
    printf("=== DEMO VỀ ARRAYS VÀ STRINGS ===\n\n");
    
    // 1. Array Declaration và Initialization
    printf("1. ARRAY BASICS:\n");
    
    // Different ways to declare arrays
    int numbers[5] = {10, 20, 30, 40, 50};  // Full initialization
    int scores[] = {85, 92, 78, 95, 88};    // Size auto-determined
    int zeros[5] = {0};                     // All elements 0
    int mixed[5] = {1, 2};                  // 1, 2, 0, 0, 0
    
    printf("Numbers array: ");
    print_array(numbers, 5);
    
    printf("Scores array: ");
    print_array(scores, 5);
    
    // 2. Array Indexing và Modification
    printf("\n2. ARRAY INDEXING:\n");
    printf("numbers[0] = %d (first element)\n", numbers[0]);
    printf("numbers[4] = %d (last element)\n", numbers[4]);
    
    // Modify array elements
    numbers[2] = 99;
    printf("After modifying numbers[2] = 99: ");
    print_array(numbers, 5);
    
    // 3. Array Size và Length
    printf("\n3. ARRAY SIZE:\n");
    int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int array_size = sizeof(my_array);           // Total bytes
    int element_size = sizeof(my_array[0]);      // Bytes per element  
    int length = array_size / element_size;      // Number of elements
    
    printf("Array size: %d bytes\n", array_size);
    printf("Element size: %d bytes\n", element_size);
    printf("Array length: %d elements\n", length);
    
    // 4. Finding Maximum Value
    printf("\n4. ARRAY PROCESSING:\n");
    int max_value = find_max(scores, 5);
    printf("Maximum score: %d\n", max_value);
    
    // 5. String Basics (char arrays)
    printf("\n5. STRINGS (CHAR ARRAYS):\n");
    
    // Different ways to declare strings
    char greeting[] = "Hello, World!";        // Auto-sized
    char name[20] = "Programming";            // Fixed size
    char empty[10] = "";                      // Empty string
    char letter_by_letter[] = {'H', 'i', '\0'}; // Manual termination
    
    print_string_info(greeting);
    print_string_info(name);
    
    // 6. String Input/Output
    printf("\n6. STRING INPUT:\n");
    char user_input[50];
    printf("Nhập tên của bạn (không có space): ");
    scanf("%49s", user_input);  // Limit input to prevent overflow
    printf("Xin chào, %s!\n", user_input);
    
    // 7. String Manipulation
    printf("\n7. STRING MANIPULATION:\n");
    char first_name[20] = "Nguyen";
    char last_name[20] = "Van A";
    char full_name[50];
    
    // Concatenate strings
    strcpy(full_name, first_name);    // Copy first_name to full_name
    strcat(full_name, " ");           // Add space
    strcat(full_name, last_name);     // Add last_name
    
    printf("Full name: %s\n", full_name);
    printf("Full name length: %lu characters\n", strlen(full_name));
    
    // 8. 2D Arrays (Matrix)
    printf("\n8. 2D ARRAYS:\n");
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6}, 
        {7, 8, 9}
    };
    
    printf("3x3 Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

// Function implementations

/*
 * In array ra màn hình
 * Lưu ý: array parameter thực chất là pointer
 */
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/*
 * Hiển thị thông tin về string
 */
void print_string_info(char str[]) {
    printf("String: \"%s\"\n", str);
    printf("  Length: %lu characters\n", strlen(str));
    printf("  First char: '%c'\n", str[0]);
    
    // Find last character (before null terminator)
    int len = strlen(str);
    if (len > 0) {
        printf("  Last char: '%c'\n", str[len - 1]);
    }
    
    printf("  Memory size: %lu bytes\n", sizeof(str));  // Warning: only gives pointer size!
}

/*
 * Tìm giá trị lớn nhất trong array
 */
int find_max(int arr[], int size) {
    if (size <= 0) {
        printf("Error: Invalid array size\n");
        return 0;
    }
    
    int max = arr[0];  // Assume first element is max
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

/*
 * KINH NGHIỆM THỰC TẾ VỀ ARRAYS VÀ STRINGS:
 * 
 * 1. ARRAY BOUNDS:
 *    - C không check array bounds tự động
 *    - Accessing arr[size] hoặc arr[-1] = undefined behavior
 *    - Luôn đảm bảo 0 <= index < size
 * 
 * 2. ARRAY VS POINTER:
 *    - Array name là constant pointer to first element
 *    - arr[i] equivalent to *(arr + i)
 *    - Cannot reassign array name: arr = other_array; // ERROR
 * 
 * 3. STRING SAFETY:
 *    - Strings phải có null terminator '\0'
 *    - Buffer overflow rất dễ xảy ra với gets(), strcpy()
 *    - Dùng fgets(), strncpy() để an toàn hơn
 * 
 * 4. COMMON MISTAKES:
 *    - Buffer overflow: scanf("%s", small_array)
 *    - Missing null terminator
 *    - Confusing array size vs string length
 *    - Off-by-one errors in loops
 * 
 * 5. MEMORY LAYOUT:
 *    - Arrays stored in contiguous memory
 *    - Multi-dimensional arrays stored row-major order
 *    - Local arrays on stack, static arrays in data segment
 * 
 * 6. BEST PRACTICES:
 *    - Always pass array size to functions
 *    - Initialize arrays when declared
 *    - Use const for read-only arrays
 *    - Consider using string.h functions safely
 * 
 * SAFER STRING INPUT EXAMPLE:
 * 
 * char buffer[100];
 * printf("Enter text: ");
 * fgets(buffer, sizeof(buffer), stdin);
 * // Remove newline if present
 * buffer[strcspn(buffer, "\n")] = '\0';
 */