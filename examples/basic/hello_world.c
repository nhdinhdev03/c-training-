/*
 * hello_world.c - Chương trình C đầu tiên
 * 
 * Đây là chương trình cơ bản nhất trong C, in ra "Hello, World!"
 * 
 * Kiến thức cần biết:
 * - #include directive
 * - main() function  
 * - printf() function
 * - return statement
 * 
 * Biên dịch: gcc hello_world.c -o hello_world
 * Chạy: ./hello_world
 */

#include <stdio.h>  // Thư viện chuẩn cho input/output

int main() {
    // In ra màn hình với printf()
    printf("Hello, World!\n");
    printf("Chào mừng đến với lập trình C!\n");
    
    // Trả về 0 để báo thành công
    return 0;
}

/*
 * Giải thích chi tiết:
 * 
 * 1. #include <stdio.h>
 *    - Preprocessor directive
 *    - Bao gồm Standard Input/Output library
 *    - Cung cấp functions như printf(), scanf()
 * 
 * 2. int main()
 *    - Entry point của chương trình
 *    - Operating system gọi main() đầu tiên
 *    - int có nghĩa function trả về integer
 * 
 * 3. printf("Hello, World!\n")
 *    - Function in formatted text ra stdout (thường là terminal)
 *    - \n là escape character cho newline (xuống dòng)
 *    - printf return số characters đã in
 * 
 * 4. return 0
 *    - Trả về exit code cho OS
 *    - 0 = success, khác 0 = error
 *    - OS có thể check code này với $? (Linux/macOS)
 */