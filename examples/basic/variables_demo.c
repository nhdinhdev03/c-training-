/*
 * variables_demo.c - Giới thiệu về biến và kiểu dữ liệu cơ bản
 * 
 * Khái niệm quan trọng:
 * - Declaration vs Initialization
 * - Các kiểu dữ liệu cơ bản: int, float, double, char
 * - printf format specifiers
 * - Variable naming conventions
 * 
 * Biên dịch: gcc -Wall -Wextra variables_demo.c -o variables_demo
 */

#include <stdio.h>

int main() {
    // Khai báo và khởi tạo các biến với kiểu khác nhau
    
    // Số nguyên (Integer)
    int age = 25;
    int birth_year = 1998;
    
    // Số thực (Floating point)
    float height = 175.5f;      // f suffix để chỉ định float
    double weight = 70.25;      // double có độ chính xác cao hơn float
    
    // Ký tự (Character)
    char grade = 'A';
    char initial = 'J';
    
    // In ra thông tin với format specifiers
    printf("=== THÔNG TIN CÁ NHÂN ===\n");
    printf("Tuổi: %d tuổi\n", age);                    // %d cho integer
    printf("Năm sinh: %d\n", birth_year);
    printf("Chiều cao: %.1f cm\n", height);            // %.1f cho float (1 chữ số thập phân)
    printf("Cân nặng: %.2lf kg\n", weight);            // %lf cho double
    printf("Điểm: %c\n", grade);                       // %c cho character
    printf("Chữ cái đầu tên: %c\n", initial);
    
    // Tính toán với biến
    int current_year = 2024;
    int calculated_age = current_year - birth_year;
    
    printf("\n=== TÍNH TOÁN ===\n");
    printf("Tuổi tính từ năm %d: %d tuổi\n", current_year, calculated_age);
    
    // Hiển thị size của các kiểu dữ liệu
    printf("\n=== KÍCH THƯỚC KIỂU DỮ LIỆU ===\n");
    printf("sizeof(int): %lu bytes\n", sizeof(int));
    printf("sizeof(float): %lu bytes\n", sizeof(float));
    printf("sizeof(double): %lu bytes\n", sizeof(double));
    printf("sizeof(char): %lu bytes\n", sizeof(char));
    
    return 0;
}

/*
 * KINH NGHIỆM THỰC TẾ:
 * 
 * 1. NAMING CONVENTIONS:
 *    - Dùng snake_case cho variables: birth_year, current_age
 *    - Tên có ý nghĩa: age thay vì a, height thay vì h
 *    - Không dùng keywords: int, float, if, while...
 * 
 * 2. INITIALIZATION:
 *    - Luôn khởi tạo biến khi khai báo
 *    - Uninitialized variables có thể chứa garbage values
 *    - Compiler warning sẽ báo nếu dùng -Wall
 * 
 * 3. FORMAT SPECIFIERS:
 *    - %d: signed decimal integer
 *    - %u: unsigned decimal integer  
 *    - %f: float (6 chữ số thập phân mặc định)
 *    - %lf: double
 *    - %c: character
 *    - %s: string
 *    - %.2f: float với 2 chữ số thập phân
 * 
 * 4. COMMON MISTAKES:
 *    - Dùng %f cho double thay vì %lf
 *    - Quên suffix f cho float literals
 *    - Không check compiler warnings
 *    - Tên biến không có ý nghĩa
 */