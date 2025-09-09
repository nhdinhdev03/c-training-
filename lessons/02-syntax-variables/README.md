# Lesson 02: Cú Pháp Cơ Bản và Biến
*Basic Syntax and Variables*

## 🎯 Mục Tiêu Bài Học

Sau bài học này, bạn sẽ:
- Hiểu cấu trúc cơ bản của một chương trình C
- Nắm vững các kiểu dữ liệu cơ bản
- Biết cách khai báo và sử dụng biến
- Hiểu về phạm vi (scope) của biến
- Sử dụng constants hiệu quả

## 📖 Cấu Trúc Chương Trình C

### Template Cơ Bản
```c
// 1. Preprocessor directives
#include <stdio.h>
#include <stdlib.h>

// 2. Global constants và variables (tránh nếu có thể)
#define PI 3.14159
const int MAX_SIZE = 100;

// 3. Function prototypes (declare trước define)
int calculate_sum(int a, int b);
void print_result(int result);

// 4. Main function - entry point
int main() {
    // Local variables
    int x = 10;
    int y = 20;
    
    // Function calls
    int sum = calculate_sum(x, y);
    print_result(sum);
    
    return 0;  // Success exit code
}

// 5. Function definitions
int calculate_sum(int a, int b) {
    return a + b;
}

void print_result(int result) {
    printf("Result: %d\n", result);
}
```

## 🔤 Kiểu Dữ Liệu Cơ Bản

### Integer Types
```c
// Signed integers
char        c = 127;           // 1 byte: -128 to 127
short       s = 32767;         // 2 bytes: -32,768 to 32,767  
int         i = 2147483647;    // 4 bytes: -2,147,483,648 to 2,147,483,647
long        l = 2147483647L;   // 4/8 bytes (platform dependent)
long long   ll = 9223372036854775807LL; // 8 bytes

// Unsigned integers (chỉ số dương)
unsigned char       uc = 255;          // 0 to 255
unsigned short      us = 65535;        // 0 to 65,535
unsigned int        ui = 4294967295U;  // 0 to 4,294,967,295
unsigned long       ul = 4294967295UL;
unsigned long long  ull = 18446744073709551615ULL;
```

### Floating Point Types
```c
float  f = 3.14159f;      // 4 bytes, ~7 decimal digits precision
double d = 3.14159;       // 8 bytes, ~15 decimal digits precision
long double ld = 3.14159L; // 12/16 bytes, highest precision
```

### Character Type
```c
char letter = 'A';        // Single character
char digit = '5';         // Character representation of digit
char newline = '\n';      // Escape character
```

### Boolean (C99 trở lên)
```c
#include <stdbool.h>
bool is_valid = true;     // true or false
bool is_empty = false;
```

## 📦 Khai Báo và Khởi Tạo Biến

### Cú Pháp Cơ Bản
```c
// Declaration only (biến chưa có giá trị xác định)
int age;
float height;

// Declaration with initialization (khuyến khích)
int age = 25;
float height = 175.5f;

// Multiple declarations
int x, y, z;              // Tất cả đều uninitialized
int a = 1, b = 2, c = 3;  // Tất cả đều được khởi tạo
```

### Naming Rules và Conventions

**RULES (bắt buộc):**
- Bắt đầu bằng chữ cái hoặc underscore (_)
- Chỉ chứa chữ cái, số, và underscore
- Không được trùng với keywords (if, while, int, etc.)
- Case-sensitive: `age` ≠ `Age` ≠ `AGE`

**CONVENTIONS (khuyến khích):**
```c
// ✅ Good naming
int student_age;          // snake_case cho variables
int current_year;
float average_score;

// ✅ Constants  
#define MAX_STUDENTS 100  // UPPER_CASE cho macros
const float PI = 3.14159f; // Normal case cho const

// ❌ Bad naming
int a;                    // Không có ý nghĩa
int studentAge;           // camelCase không phổ biến trong C
int 2students;            // Bắt đầu bằng số
int if;                   // Trùng keyword
```

## 🌍 Phạm Vi Biến (Variable Scope)

### Local Variables
```c
int main() {
    int x = 10;           // Local trong main()
    
    if (x > 5) {
        int y = 20;       // Local trong if block
        printf("%d %d\n", x, y);  // OK: có thể access cả x và y
    }
    
    // printf("%d\n", y);  // ERROR: y out of scope
    
    return 0;
}
```

### Global Variables (tránh sử dụng)
```c
#include <stdio.h>

int global_counter = 0;   // Global variable

void increment() {
    global_counter++;     // Có thể access từ any function
}

int main() {
    printf("Counter: %d\n", global_counter);  // 0
    increment();
    printf("Counter: %d\n", global_counter);  // 1
    return 0;
}
```

**⚠️ Tại sao tránh global variables?**
- Khó debug và maintain
- Tạo dependencies giữa functions
- Thread safety issues
- Khó test

## 🔒 Constants

### #define Macros
```c
#define PI 3.14159
#define MAX_SIZE 100
#define GREETING "Hello, World!"

int main() {
    float radius = 5.0f;
    float area = PI * radius * radius;  // Macro được thay thế
    return 0;
}
```

### const Keyword
```c
int main() {
    const float PI = 3.14159f;        // Typed constant
    const int MAX_SIZE = 100;
    
    // PI = 3.14;  // ERROR: cannot modify const
    
    return 0;
}
```

**#define vs const:**
- `#define`: Text replacement, no type checking
- `const`: Typed, type-safe, có scope

## 💾 Khởi Tạo Biến - Best Practices

### Always Initialize
```c
// ❌ Dangerous - undefined behavior
int main() {
    int x;                // Garbage value
    printf("%d\n", x);    // Undefined behavior!
    return 0;
}

// ✅ Safe
int main() {
    int x = 0;            // Explicitly initialized
    printf("%d\n", x);    // Always prints 0
    return 0;
}
```

### Initialize Arrays
```c
int main() {
    int numbers[5] = {1, 2, 3, 4, 5};      // Full initialization
    int zeros[5] = {0};                     // All elements = 0
    int mixed[5] = {1, 2};                  // 1, 2, 0, 0, 0
    
    return 0;
}
```

## 🔧 Type Casting

### Implicit Casting (Automatic)
```c
int main() {
    int i = 42;
    float f = i;          // int → float (safe)
    printf("%.1f\n", f);  // 42.0
    
    float x = 3.7f;
    int y = x;            // float → int (data loss!)
    printf("%d\n", y);    // 3 (fractional part lost)
    
    return 0;
}
```

### Explicit Casting
```c
int main() {
    float a = 7.0f;
    float b = 3.0f;
    
    // Integer division
    int result1 = (int)a / (int)b;     // 7/3 = 2
    
    // Float division  
    float result2 = a / b;             // 7.0/3.0 = 2.333...
    
    printf("Int division: %d\n", result1);      // 2
    printf("Float division: %.2f\n", result2);  // 2.33
    
    return 0;
}
```

## 📊 Sizeof Operator

```c
#include <stdio.h>

int main() {
    printf("Size of data types:\n");
    printf("char: %lu bytes\n", sizeof(char));
    printf("int: %lu bytes\n", sizeof(int));
    printf("float: %lu bytes\n", sizeof(float));
    printf("double: %lu bytes\n", sizeof(double));
    
    int array[10];
    printf("Array size: %lu bytes\n", sizeof(array));        // 40 bytes
    printf("Array length: %lu\n", sizeof(array)/sizeof(int)); // 10 elements
    
    return 0;
}
```

## 💡 Kinh Nghiệm Thực Tế

### Common Mistakes
1. **Uninitialized variables:**
```c
int x;           // ❌ Garbage value
int x = 0;       // ✅ Explicitly initialized
```

2. **Integer overflow:**
```c
int max = 2147483647;
int overflow = max + 1;  // ❌ Undefined behavior
```

3. **Float comparison:**
```c
float a = 0.1f + 0.2f;
if (a == 0.3f) {         // ❌ May fail due to precision
    printf("Equal\n");
}

// ✅ Better approach
if (fabs(a - 0.3f) < 0.0001f) {
    printf("Approximately equal\n");
}
```

### Best Practices
1. **Always initialize variables**
2. **Use meaningful names**
3. **Prefer local over global variables**
4. **Use const for values that don't change**
5. **Be careful with type conversions**

## 🎯 Bài Tập Thực Hành

### Bài 1: Temperature Converter
Viết chương trình chuyển đổi nhiệt độ:
- Nhập độ C
- Tính và hiển thị độ F và Kelvin
- Công thức: F = C * 9/5 + 32, K = C + 273.15

### Bài 2: Variable Scope Demo
Tạo chương trình minh họa scope của biến với nested blocks.

### Bài 3: Data Type Limits
Viết chương trình hiển thị giá trị min/max của các kiểu dữ liệu.

## 📖 Đọc Thêm

- C99 Standard specification
- "Expert C Programming" - Peter van der Linden
- "C Traps and Pitfalls" - Andrew Koenig

## ⚡ Tóm Tắt

- C có nhiều kiểu dữ liệu: integers, floats, characters
- Always initialize variables để tránh undefined behavior
- Scope determines where variables can be accessed
- Use const cho values không thay đổi
- Be careful với type casting và precision loss

## 🏃 Bước Tiếp Theo

[Lesson 03: Kiểu dữ liệu và Operators](../03-datatypes-operators/) - Tìm hiểu chi tiết về operators và expressions.

---

*💡 "The best way to learn programming is to write programs. Start coding!"*