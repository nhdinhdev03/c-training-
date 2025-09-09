# C Programming Cheatsheet - Tài Liệu Tham Khảo Nhanh

## 🚀 Quick Reference

### Cấu Trúc Chương Trình
```c
#include <stdio.h>      // Preprocessor

int main() {            // Entry point
    // Your code here
    return 0;           // Exit status
}
```

### Kiểu Dữ Liệu
| Type | Size | Range | Format |
|------|------|-------|---------|
| `char` | 1 byte | -128 to 127 | `%c` |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | `%d` |
| `float` | 4 bytes | ~7 digits precision | `%f` |
| `double` | 8 bytes | ~15 digits precision | `%lf` |
| `unsigned int` | 4 bytes | 0 to 4,294,967,295 | `%u` |

### Printf Format Specifiers
```c
%d    // int
%u    // unsigned int
%f    // float (input), double (output)
%lf   // double (input)
%c    // char
%s    // string
%p    // pointer
%x    // hex
%o    // octal
%.2f  // float with 2 decimal places
%5d   // int with min width 5
```

### Escape Characters
```c
\n    // Newline
\t    // Tab
\\    // Backslash
\"    // Double quote
\'    // Single quote
\0    // Null terminator
```

### Operators
```c
// Arithmetic
+  -  *  /  %

// Assignment
=  +=  -=  *=  /=  %=

// Comparison
==  !=  <  >  <=  >=

// Logical
&&  ||  !

// Increment/Decrement
++  --

// Bitwise
&  |  ^  ~  <<  >>
```

### Control Structures
```c
// If-else
if (condition) {
    // code
} else if (condition2) {
    // code
} else {
    // code
}

// For loop
for (init; condition; increment) {
    // code
}

// While loop
while (condition) {
    // code
}

// Do-while loop
do {
    // code
} while (condition);

// Switch
switch (variable) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code
        break;
}
```

### Functions
```c
// Function declaration
return_type function_name(parameters);

// Function definition
return_type function_name(parameters) {
    // code
    return value;  // if not void
}

// Example
int add(int a, int b) {
    return a + b;
}
```

### Arrays
```c
// Declaration and initialization
int arr[5] = {1, 2, 3, 4, 5};
int arr2[5] = {0};  // All elements 0
int arr3[] = {1, 2, 3};  // Size automatically determined

// Access
arr[0] = 10;        // Set first element
int x = arr[1];     // Get second element

// String (char array)
char name[] = "Hello";
char name2[10] = "World";
```

### Pointers
```c
int x = 42;
int *ptr = &x;      // ptr points to x
int value = *ptr;   // Dereference: get value at ptr

// Array and pointer relationship
int arr[5];
int *p = arr;       // p points to first element
```

### Memory Management
```c
#include <stdlib.h>

// Allocate memory
int *ptr = malloc(sizeof(int) * 10);  // Array of 10 ints
if (ptr == NULL) {
    // Handle allocation failure
}

// Free memory
free(ptr);
ptr = NULL;  // Good practice
```

### String Functions
```c
#include <string.h>

strlen(str)           // Length
strcpy(dest, src)     // Copy
strcat(dest, src)     // Concatenate
strcmp(str1, str2)    // Compare
strstr(haystack, needle)  // Find substring
```

### File I/O
```c
#include <stdio.h>

// Open file
FILE *fp = fopen("filename.txt", "r");  // "w", "a", "r+"
if (fp == NULL) {
    // Handle error
}

// Read/Write
fprintf(fp, "Hello %s\n", name);
fscanf(fp, "%d", &number);
fgets(buffer, size, fp);

// Close file
fclose(fp);
```

### Structures
```c
// Define structure
struct Person {
    char name[50];
    int age;
    float height;
};

// Use structure
struct Person p1;
strcpy(p1.name, "John");
p1.age = 25;

// Pointer to structure
struct Person *ptr = &p1;
ptr->age = 26;  // Same as (*ptr).age = 26;
```

### Common Library Functions
```c
// stdio.h
printf(), scanf(), fopen(), fclose()

// stdlib.h
malloc(), free(), atoi(), exit()

// string.h
strlen(), strcpy(), strcmp()

// math.h (link with -lm)
sqrt(), pow(), sin(), cos()

// ctype.h
isdigit(), isalpha(), toupper(), tolower()
```

### Compilation Commands
```bash
# Basic compilation
gcc program.c -o program

# With warnings
gcc -Wall -Wextra program.c -o program

# Debug mode
gcc -g -Wall program.c -o program

# Optimized
gcc -O2 program.c -o program

# Link math library
gcc program.c -o program -lm

# Multiple files
gcc main.c utils.c -o program
```

### Debugging
```bash
# Compile with debug info
gcc -g program.c -o program

# Run with gdb
gdb ./program

# GDB commands
(gdb) run                # Start program
(gdb) break main         # Set breakpoint
(gdb) step               # Step into function
(gdb) next               # Step over function
(gdb) print variable     # Print variable value
(gdb) quit               # Exit gdb
```

### Common Errors and Solutions

**Compilation Errors:**
```c
// Missing semicolon
int x = 5  // Error: expected ';'

// Undeclared variable
printf("%d", y);  // Error: 'y' undeclared

// Wrong include
prinf("Hello");   // Error: 'prinf' undeclared (typo)
```

**Runtime Errors:**
```c
// Segmentation fault
int *ptr = NULL;
*ptr = 5;  // Error: dereferencing NULL pointer

// Array out of bounds
int arr[5];
arr[10] = 1;  // Error: accessing invalid memory

// Memory leak
int *ptr = malloc(sizeof(int) * 100);
// ... use ptr ...
// Missing: free(ptr);
```

### Best Practices
1. **Always initialize variables**
2. **Check malloc() return value**
3. **Free allocated memory**
4. **Use meaningful variable names**
5. **Add comments for complex logic**
6. **Compile with warnings enabled**
7. **Handle edge cases**
8. **Use const for read-only data**

### Quick Problem Solving

**"undefined reference" error:**
- Missing library: add `-lm` for math functions
- Missing function definition
- Typo in function name

**"segmentation fault":**
- NULL pointer dereference
- Array bounds violation
- Stack overflow (too much recursion)
- Use of uninitialized pointer

**"warning: unused variable":**
- Remove unused variables
- Or use `(void)variable;` to suppress

**Program crashes randomly:**
- Uninitialized variables
- Buffer overflow
- Use after free
- Double free

---

*💡 Keep this cheatsheet handy while coding. Practice makes perfect!*