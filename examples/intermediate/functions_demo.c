/*
 * functions_demo.c - Minh họa về Functions trong C
 * 
 * Nội dung:
 * - Function declaration và definition
 * - Parameters và return values
 * - Pass by value vs pass by reference (pointers)
 * - Function scope và local variables
 * - Recursive functions
 * 
 * Đây là khái niệm cực kỳ quan trọng trong lập trình!
 */

#include <stdio.h>

// Function declarations (prototypes)
int add(int a, int b);
void print_greeting(char name[]);
int factorial(int n);
void swap_values(int *a, int *b);  // Pass by reference
int max_of_three(int a, int b, int c);

int main() {
    printf("=== DEMO VỀ FUNCTIONS ===\n\n");
    
    // 1. Basic function call
    int sum = add(15, 25);
    printf("15 + 25 = %d\n", sum);
    
    // 2. Function với string parameter
    print_greeting("Minh");
    
    // 3. Recursive function
    int n = 5;
    int fact = factorial(n);
    printf("Factorial của %d = %d\n", n, fact);
    
    // 4. Pass by reference demo
    int x = 10, y = 20;
    printf("Trước swap: x=%d, y=%d\n", x, y);
    swap_values(&x, &y);  // Pass addresses
    printf("Sau swap: x=%d, y=%d\n", x, y);
    
    // 5. Function với multiple parameters
    int max = max_of_three(45, 23, 67);
    printf("Max của 45, 23, 67 = %d\n", max);
    
    return 0;
}

// Function definitions

/*
 * Hàm cộng hai số nguyên
 * Parameters: int a, int b (pass by value)
 * Return: tổng của a và b
 */
int add(int a, int b) {
    return a + b;  // Simple return statement
}

/*
 * In lời chào với tên
 * Parameters: char array (string)
 * Return: void (không trả về gì)
 */
void print_greeting(char name[]) {
    printf("Xin chào, %s! Chào mừng bạn học C.\n", name);
    // Local variables chỉ tồn tại trong function này
    int greeting_count = 1;
    printf("Đây là lời chào thứ %d\n", greeting_count);
}

/*
 * Tính factorial bằng recursion
 * Factorial(n) = n * factorial(n-1)
 * Base case: factorial(0) = factorial(1) = 1
 */
int factorial(int n) {
    // Base case để tránh infinite recursion
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
    
    /*
     * Trace ví dụ factorial(5):
     * factorial(5) = 5 * factorial(4)
     * factorial(4) = 4 * factorial(3)  
     * factorial(3) = 3 * factorial(2)
     * factorial(2) = 2 * factorial(1)
     * factorial(1) = 1
     * 
     * Kết quả: 5 * 4 * 3 * 2 * 1 = 120
     */
}

/*
 * Swap hai số bằng pointers (pass by reference)
 * Tham số là pointer để có thể modify original variables
 */
void swap_values(int *a, int *b) {
    int temp = *a;   // Lưu giá trị tại địa chỉ a
    *a = *b;         // Gán giá trị tại b vào a
    *b = temp;       // Gán temp vào b
    
    /*
     * Tại sao cần pointers?
     * - Nếu dùng pass by value: swap_values(int a, int b)
     * - Function chỉ nhận COPY của values
     * - Modifications chỉ ảnh hưởng local copies
     * - Original variables không đổi
     * 
     * Với pointers:
     * - Function nhận ADDRESSES của variables  
     * - Có thể modify original values qua addresses
     */
}

/*
 * Tìm số lớn nhất trong ba số
 * Minh họa nested if-else trong function
 */
int max_of_three(int a, int b, int c) {
    int max = a;  // Assume a is max initially
    
    if (b > max) {
        max = b;
    }
    
    if (c > max) {
        max = c;
    }
    
    return max;
    
    // Alternative: one-liner (advanced)
    // return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

/*
 * KINH NGHIỆM THỰC TẾ VỀ FUNCTIONS:
 * 
 * 1. FUNCTION DESIGN PRINCIPLES:
 *    - Single Responsibility: Mỗi function làm một việc duy nhất
 *    - Meaningful names: add(), not compute()
 *    - Keep functions small: < 50 lines ideal
 *    - Minimize side effects
 * 
 * 2. PARAMETER CONVENTIONS:
 *    - Pass by value: cho primitive types (int, float, char)
 *    - Pass by reference (pointers): để modify original data
 *    - Arrays luôn là pass by reference
 * 
 * 3. RETURN VALUES:
 *    - Always return meaningful values
 *    - Use return codes for error handling
 *    - void functions for actions (print, modify)
 * 
 * 4. COMMON MISTAKES:
 *    - Forgetting return statement
 *    - Wrong parameter types
 *    - Not handling edge cases
 *    - Infinite recursion (missing base case)
 * 
 * 5. DEBUGGING TIPS:
 *    - Test functions individually
 *    - Use printf() for tracing
 *    - Check boundary conditions
 *    - Validate inputs
 */