/*
 * student_management.c - Dự Án Thực Tế: Hệ Thống Quản Lý Sinh Viên
 * 
 * Đây là dự án tổng hợp tất cả kiến thức đã học:
 * - Structures
 * - Arrays
 * - Functions  
 * - Pointers
 * - File I/O
 * - Dynamic Memory
 * - String manipulation
 * 
 * Một dự án thực tế để áp dụng kiến thức C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

// Structure để lưu thông tin sinh viên
typedef struct {
    int id;                              // Mã sinh viên
    char name[MAX_NAME_LENGTH];          // Tên sinh viên
    int age;                             // Tuổi
    float grades[3];                     // Điểm 3 môn học
    float average;                       // Điểm trung bình
} Student;

// Function prototypes
void display_menu(void);
void add_student(Student students[], int *count);
void display_all_students(const Student students[], int count);
void search_student(const Student students[], int count);
void calculate_average(Student *student);
void find_top_student(const Student students[], int count);
void save_to_file(const Student students[], int count);
void load_from_file(Student students[], int *count);

int main() {
    Student students[MAX_STUDENTS];
    int student_count = 0;
    int choice;
    
    printf("=== HỆ THỐNG QUẢN LÝ SINH VIÊN ===\n");
    printf("Chào mừng bạn đến với chương trình quản lý sinh viên!\n\n");
    
    // Load existing data
    load_from_file(students, &student_count);
    
    do {
        display_menu();
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student(students, &student_count);
                break;
            case 2:
                display_all_students(students, student_count);
                break;
            case 3:
                search_student(students, student_count);
                break;
            case 4:
                find_top_student(students, student_count);
                break;
            case 5:
                save_to_file(students, student_count);
                break;
            case 0:
                save_to_file(students, student_count);
                printf("Cảm ơn bạn đã sử dụng chương trình! Tạm biệt.\n");
                break;
            default:
                printf("❌ Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
                break;
        }
        
        if (choice != 0) {
            printf("\nNhấn Enter để tiếp tục...");
            while (getchar() != '\n');  // Clear input buffer
            getchar();  // Wait for Enter
        }
        
    } while (choice != 0);
    
    return 0;
}

void display_menu(void) {
    printf("\n==================================================\n");
    printf("           MENU CHỨC NĂNG\n");
    printf("==================================================\n");
    printf("1. Thêm sinh viên mới\n");
    printf("2. Hiển thị tất cả sinh viên\n");  
    printf("3. Tìm kiếm sinh viên\n");
    printf("4. Tìm sinh viên giỏi nhất\n");
    printf("5. Lưu dữ liệu vào file\n");
    printf("0. Thoát chương trình\n");
    printf("==================================================\n");
}

void add_student(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("❌ Đã đạt giới hạn tối đa %d sinh viên!\n", MAX_STUDENTS);
        return;
    }
    
    printf("\n=== THÊM SINH VIÊN MỚI ===\n");
    
    Student *new_student = &students[*count];  // Pointer to new student
    
    // Input student information
    printf("Nhập mã sinh viên: ");
    scanf("%d", &new_student->id);
    
    printf("Nhập tên sinh viên: ");
    scanf("%49s", new_student->name);  // Limit input to prevent overflow
    
    printf("Nhập tuổi: ");
    scanf("%d", &new_student->age);
    
    printf("Nhập điểm 3 môn học:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Môn %d: ", i + 1);
        scanf("%f", &new_student->grades[i]);
    }
    
    // Calculate average
    calculate_average(new_student);
    
    (*count)++;  // Increment student count
    
    printf("✅ Đã thêm sinh viên %s thành công!\n", new_student->name);
    printf("   Điểm trung bình: %.2f\n", new_student->average);
}

void display_all_students(const Student students[], int count) {
    if (count == 0) {
        printf("\n❌ Chưa có sinh viên nào trong hệ thống!\n");
        return;
    }
    
    printf("\n=== DANH SÁCH SINH VIÊN ===\n");
    printf("%-10s %-20s %-5s %-8s %-8s %-8s %-10s\n", 
           "Mã SV", "Tên", "Tuổi", "Môn 1", "Môn 2", "Môn 3", "TB");
    printf("-----------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        const Student *s = &students[i];  // Pointer for easier access
        printf("%-10d %-20s %-5d %-8.1f %-8.1f %-8.1f %-10.2f\n",
               s->id, s->name, s->age, 
               s->grades[0], s->grades[1], s->grades[2], s->average);
    }
}

void search_student(const Student students[], int count) {
    if (count == 0) {
        printf("\n❌ Chưa có sinh viên nào để tìm kiếm!\n");
        return;
    }
    
    int search_id;
    printf("\nNhập mã sinh viên cần tìm: ");
    scanf("%d", &search_id);
    
    // Linear search
    for (int i = 0; i < count; i++) {
        if (students[i].id == search_id) {
            const Student *found = &students[i];
            
            printf("\n✅ Tìm thấy sinh viên:\n");
            printf("  Mã SV: %d\n", found->id);
            printf("  Tên: %s\n", found->name);
            printf("  Tuổi: %d\n", found->age);
            printf("  Điểm các môn: %.1f, %.1f, %.1f\n", 
                   found->grades[0], found->grades[1], found->grades[2]);
            printf("  Điểm trung bình: %.2f\n", found->average);
            return;
        }
    }
    
    printf("❌ Không tìm thấy sinh viên có mã %d\n", search_id);
}

void calculate_average(Student *student) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 3.0f;
}

void find_top_student(const Student students[], int count) {
    if (count == 0) {
        printf("\n❌ Chưa có sinh viên nào!\n");
        return;
    }
    
    int top_index = 0;
    float max_average = students[0].average;
    
    // Find student with highest average
    for (int i = 1; i < count; i++) {
        if (students[i].average > max_average) {
            max_average = students[i].average;
            top_index = i;
        }
    }
    
    const Student *top_student = &students[top_index];
    
    printf("\n🏆 SINH VIÊN XUẤT SẮC NHẤT:\n");
    printf("  Mã SV: %d\n", top_student->id);
    printf("  Tên: %s\n", top_student->name);
    printf("  Tuổi: %d\n", top_student->age);
    printf("  Điểm trung bình: %.2f\n", top_student->average);
}

void save_to_file(const Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");  // Binary write mode
    
    if (file == NULL) {
        printf("❌ Không thể tạo file để lưu dữ liệu!\n");
        return;
    }
    
    // Write number of students first
    fwrite(&count, sizeof(int), 1, file);
    
    // Write student data
    fwrite(students, sizeof(Student), count, file);
    
    fclose(file);
    
    printf("✅ Đã lưu dữ liệu %d sinh viên vào file 'students.dat'\n", count);
}

void load_from_file(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");  // Binary read mode
    
    if (file == NULL) {
        printf("📝 Chưa có file dữ liệu. Bắt đầu với danh sách trống.\n");
        *count = 0;
        return;
    }
    
    // Read number of students
    if (fread(count, sizeof(int), 1, file) != 1) {
        printf("❌ Lỗi đọc file dữ liệu!\n");
        *count = 0;
        fclose(file);
        return;
    }
    
    // Read student data
    if (fread(students, sizeof(Student), *count, file) != *count) {
        printf("❌ Lỗi đọc dữ liệu sinh viên!\n");
        *count = 0;
        fclose(file);
        return;
    }
    
    fclose(file);
    
    if (*count > 0) {
        printf("✅ Đã tải dữ liệu %d sinh viên từ file.\n", *count);
    }
}

/*
 * PHÂN TÍCH DỰ ÁN:
 * 
 * 1. STRUCTURES:
 *    - Định nghĩa Student struct để group related data
 *    - Sử dụng typedef để đơn giản hóa syntax
 *    - Arrays trong struct để lưu multiple grades
 * 
 * 2. ARRAYS:
 *    - Static array để lưu multiple students
 *    - String arrays cho names
 *    - Float arrays cho grades
 * 
 * 3. POINTERS:
 *    - Pass by reference để modify data
 *    - Pointer arithmetic để access struct members
 *    - const pointers để protect read-only data
 * 
 * 4. FUNCTIONS:
 *    - Modular design với single responsibility
 *    - Clear function names và parameters
 *    - Return values và error handling
 * 
 * 5. FILE I/O:
 *    - Binary file operations cho efficiency
 *    - Error checking cho file operations  
 *    - Data persistence across program runs
 * 
 * 6. MEMORY MANAGEMENT:
 *    - Static allocation (no malloc needed)
 *    - Careful buffer size management
 *    - Input validation để prevent overflow
 * 
 * IMPROVEMENTS FOR PRODUCTION:
 * - Input validation (grade ranges, etc.)
 * - Error handling cho all user inputs
 * - Dynamic memory allocation for unlimited students
 * - Sort functionality
 * - Search by name
 * - Edit/delete functionality
 * - Configuration file
 * - Backup functionality
 * 
 * LEARNING OUTCOMES:
 * Dự án này giúp bạn:
 * - Hiểu cách organize data với structures
 * - Practice với arrays và string manipulation
 * - Apply functions để create modular code
 * - Learn file I/O for data persistence
 * - Experience real-world programming challenges
 * - Debug complex multi-function programs
 */