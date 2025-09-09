/*
 * input_output.c - Cơ bản về Input/Output trong C
 * 
 * Nội dung:
 * - scanf() để đọc input từ user
 * - printf() để hiển thị output
 * - Buffer và newline issues
 * - Input validation cơ bản
 * 
 * Biên dịch: gcc -Wall input_output.c -o input_output
 */

#include <stdio.h>

int main() {
    // Khai báo biến để lưu input
    char name[50];      // Array để lưu tên (string)
    int age;            // Tuổi
    float height;       // Chiều cao
    char grade;         // Điểm
    
    printf("=== CHƯƠNG TRÌNH NHẬP THÔNG TIN ===\n\n");
    
    // Nhập tên (string)
    printf("Nhập tên của bạn: ");
    scanf("%49s", name);    // %49s để tránh buffer overflow
    
    // Nhập tuổi
    printf("Nhập tuổi: ");
    scanf("%d", &age);      // & để lấy address của biến
    
    // Nhập chiều cao
    printf("Nhập chiều cao (cm): ");
    scanf("%f", &height);
    
    // Xử lý newline còn lại trong buffer
    while (getchar() != '\n');  // Đọc hết ký tự còn lại
    
    // Nhập điểm (character)
    printf("Nhập điểm (A-F): ");
    scanf("%c", &grade);
    
    // Hiển thị kết quả
    printf("\n=== THÔNG TIN VỪA NHẬP ===\n");
    printf("Tên: %s\n", name);
    printf("Tuổi: %d tuổi\n", age);
    printf("Chiều cao: %.1f cm\n", height);
    printf("Điểm: %c\n", grade);
    
    // Tính toán và hiển thị thêm thông tin
    if (height > 0) {
        float height_m = height / 100.0f;   // Chuyển sang mét
        printf("Chiều cao: %.2f mét\n", height_m);
    }
    
    // Đánh giá điểm
    printf("Nhận xét: ");
    if (grade == 'A' || grade == 'a') {
        printf("Xuất sắc!\n");
    } else if (grade == 'B' || grade == 'b') {
        printf("Giỏi!\n");
    } else if (grade == 'C' || grade == 'c') {
        printf("Khá!\n");
    } else if (grade == 'D' || grade == 'd') {
        printf("Trung bình!\n");
    } else if (grade == 'F' || grade == 'f') {
        printf("Cần cố gắng hơn!\n");
    } else {
        printf("Điểm không hợp lệ!\n");
    }
    
    return 0;
}

/*
 * QUAN TRỌNG VỀ scanf():
 * 
 * 1. BUFFER ISSUES:
 *    - scanf() để lại newline trong input buffer
 *    - Có thể gây vấn đề với scanf() tiếp theo
 *    - Giải pháp: while(getchar() != '\n'); hoặc fflush(stdin)
 * 
 * 2. SECURITY ISSUES:
 *    - scanf("%s", name) có thể gây buffer overflow
 *    - Nên dùng scanf("%49s", name) để giới hạn
 *    - Hoặc dùng fgets() an toàn hơn
 * 
 * 3. ADDRESS OPERATOR (&):
 *    - scanf() cần address của biến để ghi data
 *    - Dùng &variable cho int, float, char, double
 *    - KHÔNG dùng & cho arrays/strings (name đã là address)
 * 
 * 4. ERROR HANDLING:
 *    - scanf() return số items đọc thành công
 *    - Nên check return value trong code thực tế
 *    - scanf() có thể fail nếu input không đúng format
 * 
 * EXAMPLE SAFER VERSION:
 * 
 * if (scanf("%d", &age) != 1) {
 *     printf("Lỗi: Tuổi phải là số!\n");
 *     return 1;
 * }
 */