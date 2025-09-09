/*
 * SOLUTION 01: Personal Information Program
 * Lời giải bài tập 01: Chương trình thông tin cá nhân
 * 
 * Đây là một lời giải mẫu. Bạn có thể có cách làm khác nhưng đúng.
 */

#include <stdio.h>

int main() {
    // Khai báo biến
    char name[100];     // Tên đầy đủ
    int age;            // Tuổi
    float height_cm;    // Chiều cao (cm)
    float weight;       // Cân nặng (kg)
    float height_m;     // Chiều cao (m)
    float bmi;          // Chỉ số BMI
    
    // Tiêu đề chương trình
    printf("=== CHƯƠNG TRÌNH TÍNH BMI ===\n\n");
    
    // Nhập thông tin
    printf("Nhập tên đầy đủ: ");
    scanf("%99s", name);  // Giới hạn 99 ký tự để tránh overflow
    
    printf("Nhập tuổi: ");
    scanf("%d", &age);
    
    printf("Nhập chiều cao (cm): ");
    scanf("%f", &height_cm);
    
    printf("Nhập cân nặng (kg): ");
    scanf("%f", &weight);
    
    // Tính toán
    height_m = height_cm / 100.0f;      // Chuyển cm sang m
    bmi = weight / (height_m * height_m); // Công thức BMI
    
    // Hiển thị kết quả
    printf("\n=== THÔNG TIN CÁ NHÂN ===\n");
    printf("Tên: %s\n", name);
    printf("Tuổi: %d tuổi\n", age);
    printf("Chiều cao: %.1f cm (%.2f m)\n", height_cm, height_m);
    printf("Cân nặng: %.1f kg\n", weight);
    printf("BMI: %.1f\n", bmi);
    
    // Phân loại BMI
    printf("Phân loại: ");
    if (bmi < 18.5f) {
        printf("Thiếu cân\n");
        printf("💡 Bạn nên tăng cân để có sức khỏe tốt hơn.\n");
    } else if (bmi >= 18.5f && bmi <= 24.9f) {
        printf("Bình thường\n");
        printf("🎉 Tuyệt vời! Bạn có cân nặng lý tưởng.\n");
    } else if (bmi >= 25.0f && bmi <= 29.9f) {
        printf("Thừa cân\n");
        printf("⚠️ Bạn nên kiểm soát cân nặng.\n");
    } else {
        printf("Béo phì\n");
        printf("🚨 Bạn nên giảm cân để bảo vệ sức khỏe.\n");
    }
    
    return 0;
}

/*
 * PHÂN TÍCH SOLUTION:
 * 
 * 1. KHAI BÁO BIẾN:
 *    - char name[100]: Array để lưu string
 *    - float cho height và weight để có thể nhập số thập phân
 *    - Tách height_cm và height_m để rõ ràng
 * 
 * 2. INPUT VALIDATION:
 *    - scanf("%99s", name) để tránh buffer overflow
 *    - Trong thực tế nên check return value của scanf()
 * 
 * 3. CALCULATION:
 *    - Chuyển cm sang m trước khi tính BMI
 *    - Dùng float literals (100.0f) để đảm bảo float division
 * 
 * 4. OUTPUT FORMATTING:
 *    - %.1f để hiển thị 1 chữ số thập phân
 *    - Thêm emoji và lời khuyên để friendly hơn
 * 
 * 5. LOGIC FLOW:
 *    - If-else if-else structure để phân loại BMI
 *    - Điều kiện rõ ràng và không bị overlap
 * 
 * IMPROVEMENTS FOR REAL WORLD:
 * - Check scanf() return values
 * - Handle invalid input (negative weight, etc.)
 * - Use fgets() instead of scanf() for strings
 * - Add input validation loops
 */