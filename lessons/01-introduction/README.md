# Lesson 01: Giới Thiệu và Cài Đặt
*Introduction and Setup*

## 🎯 Mục Tiêu Bài Học

Sau bài học này, bạn sẽ:
- Hiểu được C là gì và tại sao nó quan trọng
- Cài đặt được môi trường lập trình C
- Viết và chạy được chương trình C đầu tiên
- Hiểu được quy trình biên dịch cơ bản

## 📚 C Programming Language Là Gì?

### Lịch Sử Ngắn Gọn
C được phát triển bởi **Dennis Ritchie** tại Bell Labs từ năm 1969-1973. Đây là ngôn ngữ:
- **Cấp thấp**: Gần với phần cứng máy tính
- **Mạnh mẽ**: Có thể làm hầu hết mọi thứ
- **Hiệu quả**: Code chạy rất nhanh
- **Portable**: Chạy được trên nhiều nền tảng

### Tại Sao Học C? (Kinh nghiệm 15 năm)

Tôi thường được hỏi: *"Tại sao phải học C khi có Python, JavaScript dễ hơn?"*

Câu trả lời của tôi:
1. **C là nền tảng**: Linux kernel, Windows, macOS đều viết bằng C
2. **Hiểu bộ nhớ**: C dạy bạn cách máy tính thực sự hoạt động
3. **Performance**: Khi tốc độ quan trọng, C là lựa chọn hàng đầu
4. **Learning other languages**: Học C xong, học gì cũng dễ

> *"C là như việc học lái xe số sàn. Khó hơn xe số tự động, nhưng bạn sẽ hiểu engine hoạt động như thế nào."*

## 🛠️ Cài Đặt Môi Trường

### Trên Linux (Ubuntu/Debian)
```bash
# Cập nhật package list
sudo apt update

# Cài đặt build tools
sudo apt install build-essential

# Kiểm tra cài đặt
gcc --version
make --version
```

### Trên macOS
```bash
# Cài đặt Command Line Tools
xcode-select --install

# Hoặc dùng Homebrew
brew install gcc

# Kiểm tra
gcc --version
```

### Trên Windows
1. Tải [MSYS2](https://www.msys2.org/)
2. Cài đặt và mở MSYS2 terminal
3. Chạy các lệnh:
```bash
# Cập nhật MSYS2
pacman -Syu

# Cài đặt GCC
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-make

# Thêm vào PATH
echo 'export PATH="/mingw64/bin:$PATH"' >> ~/.bashrc
```

## 💻 Chương Trình Đầu Tiên

### Hello World - Phân Tích Chi Tiết

```c
// File: hello_world.c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

**Phân tích từng dòng:**

1. `#include <stdio.h>`: 
   - Preprocessor directive
   - Bao gồm thư viện Standard Input/Output
   - Cung cấp function `printf()`

2. `int main()`:
   - Entry point của chương trình
   - `int` có nghĩa function trả về số nguyên
   - `main()` là function đặc biệt, được gọi đầu tiên

3. `printf("Hello, World!\n")`:
   - In text ra màn hình
   - `\n` là newline character (xuống dòng)

4. `return 0`:
   - Trả về 0 cho operating system
   - 0 = success, khác 0 = error

### Biên Dịch và Chạy

```bash
# Biên dịch
gcc hello_world.c -o hello_world

# Chạy
./hello_world
```

**Output:**
```
Hello, World!
```

## 🔍 Quy Trình Biên Dịch (Compilation Process)

Đây là kiến thức mà nhiều người bỏ qua, nhưng rất quan trọng:

```
Source Code (.c) → Preprocessor → Compiler → Assembler → Linker → Executable
```

### 1. Preprocessing
```bash
gcc -E hello_world.c -o hello_world.i
```
- Xử lý các `#include`, `#define`
- Tạo file `.i` với code đã được expanded

### 2. Compilation  
```bash
gcc -S hello_world.i -o hello_world.s
```
- Chuyển C code thành Assembly code
- Tạo file `.s`

### 3. Assembly
```bash
gcc -c hello_world.s -o hello_world.o  
```
- Chuyển Assembly thành machine code
- Tạo object file `.o`

### 4. Linking
```bash
gcc hello_world.o -o hello_world
```
- Link với các library cần thiết
- Tạo executable file

### Làm Tất Cả Một Lúc
```bash
gcc hello_world.c -o hello_world
```

## 🎯 Compiler Flags Quan Trọng

```bash
# Basic compilation with warnings
gcc -Wall -Wextra hello_world.c -o hello_world

# Debug mode
gcc -g -Wall hello_world.c -o hello_world_debug

# Optimized release
gcc -O2 -Wall hello_world.c -o hello_world_release

# Very strict checking
gcc -Wall -Wextra -Werror -pedantic hello_world.c -o hello_world
```

**Giải thích flags:**
- `-Wall`: Bật tất cả warnings thông thường
- `-Wextra`: Thêm warnings khác
- `-Werror`: Treat warnings như errors
- `-pedantic`: Strict ISO C compliance
- `-g`: Include debugging information
- `-O2`: Optimization level 2

## 💡 Kinh Nghiệm Thực Tế

### Thói Quen Tốt Từ Đầu
1. **Luôn dùng compiler warnings**: `-Wall -Wextra`
2. **Comment code**: Giải thích logic phức tạp
3. **Consistent naming**: `snake_case` cho variables, `PascalCase` cho constants
4. **Indent đều**: 4 spaces hoặc 1 tab

### Common Mistakes Của Newbie
1. **Quên `#include <stdio.h>`**
2. **Không check compiler warnings**
3. **Viết tất cả code trong `main()`**
4. **Không hiểu error messages**

## 🔨 Bài Tập Thực Hành

### Bài 1: Hello với Tên Riêng
```c
#include <stdio.h>

int main() {
    printf("Hello, [Your Name]!\n");
    printf("Welcome to C Programming!\n");
    return 0;
}
```

### Bài 2: Compiler Flags Experiment
Thử biên dịch file sau với các flags khác nhau:
```c
#include <stdio.h>

int main() {
    int x;  // Uninitialized variable
    printf("Value of x: %d\n", x);
    return 0;
}
```

### Bài 3: Error Analysis
Fix lỗi trong code này:
```c
#include <studio.h>  // Lỗi gì?

int main() {
    printf("Debug this!")
    return 0  // Lỗi gì?
}
```

## 📖 Đọc Thêm

- **The C Programming Language** - Kernighan & Ritchie (K&R Bible)
- **C Programming: A Modern Approach** - K.N. King
- **Learn C The Hard Way** - Zed Shaw

## ⚡ Tóm Tắt

- C là ngôn ngữ cấp thấp, mạnh mẽ và hiệu quả
- Quy trình: Source → Preprocessor → Compiler → Assembler → Linker → Executable  
- Luôn dùng compiler warnings (`-Wall -Wextra`)
- Hello World là bước đầu, nhưng hiểu rõ từng dòng code rất quan trọng

## 🏃 Bước Tiếp Theo

[Lesson 02: Cú pháp cơ bản và Biến](../02-syntax-variables/) - Tìm hiểu về variables, data types cơ bản và cú pháp C.

---

*💡 "Every expert was once a beginner. Every pro was once an amateur." - Keep coding!*