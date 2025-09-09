# Dự Án Thực Tế - Projects

Các dự án này được thiết kế để áp dụng tất cả kiến thức đã học trong khóa học C.

## 🚀 student_management.c

### Mô Tả
Hệ thống quản lý sinh viên đầy đủ chức năng:
- Thêm sinh viên mới
- Hiển thị danh sách 
- Tìm kiếm sinh viên
- Tìm sinh viên xuất sắc nhất
- Lưu/tải dữ liệu từ file

### Kiến Thức Áp Dụng
- **Structures**: Tổ chức dữ liệu sinh viên
- **Arrays**: Lưu trữ nhiều sinh viên và điểm số
- **Functions**: Code modular và reusable
- **Pointers**: Pass by reference và truy cập struct
- **File I/O**: Lưu trữ dữ liệu persistent
- **String manipulation**: Xử lý tên sinh viên
- **Control flow**: Menu và user interaction

### Cách Sử Dụng

1. **Biên dịch:**
```bash
gcc -Wall projects/student_management.c -o student_manager
```

2. **Chạy chương trình:**
```bash
./student_manager
```

3. **Sử dụng menu để:**
   - Thêm sinh viên với điểm 3 môn học
   - Xem danh sách tất cả sinh viên  
   - Tìm sinh viên theo mã số
   - Xem sinh viên có điểm cao nhất
   - Lưu dữ liệu (tự động khi thoát)

### Ví Dụ Sử Dụng

```
=== HỆ THỐNG QUẢN LÝ SINH VIÊN ===

==================================================
           MENU CHỨC NĂNG
==================================================
1. Thêm sinh viên mới
2. Hiển thị tất cả sinh viên
3. Tìm kiếm sinh viên  
4. Tìm sinh viên giỏi nhất
5. Lưu dữ liệu vào file
0. Thoát chương trình
==================================================

Lựa chọn của bạn: 1

=== THÊM SINH VIÊN MỚI ===
Nhập mã sinh viên: 2001
Nhập tên sinh viên: NguyenVanA
Nhập tuổi: 20
Nhập điểm 3 môn học:
  Môn 1: 8.5
  Môn 2: 9.0  
  Môn 3: 8.0
✅ Đã thêm sinh viên NguyenVanA thành công!
   Điểm trung bình: 8.50
```

### Cải Tiến Có Thể Làm

1. **Input validation** cho tất cả dữ liệu nhập
2. **Dynamic memory allocation** để không giới hạn số sinh viên
3. **Sort functionality** theo tên hoặc điểm
4. **Edit/delete students** 
5. **Export to CSV** file
6. **Grade classification** (A, B, C, D, F)
7. **Statistics** (average class score, etc.)

### Code Structure

```c
// Main components:
typedef struct {
    int id;
    char name[50];
    int age;
    float grades[3];
    float average;
} Student;

// Key functions:
- add_student()        // Thêm sinh viên
- display_all_students() // Hiển thị danh sách
- search_student()     // Tìm kiếm
- find_top_student()   // Tìm sinh viên giỏi nhất
- save_to_file()       // Lưu dữ liệu
- load_from_file()     // Tải dữ liệu
```

## 📖 Học Từ Dự Án

Dự án này giúp bạn hiểu:

1. **Real-world application** của C programming
2. **Data organization** với structures
3. **File persistence** cho applications
4. **User interface design** trong console apps
5. **Error handling** và input validation
6. **Code organization** và modularity

## 🎯 Thử Thách

Sau khi hoàn thành project cơ bản, thử implement:

1. **Tìm kiếm theo tên** (substring search)
2. **Sắp xếp danh sách** theo điểm hoặc tên
3. **Thống kê lớp học** (điểm trung bình, số học sinh giỏi/khá/trung bình)
4. **Export report** ra text file đẹp
5. **Import data** từ CSV file

---

*💡 "The best way to learn programming is to build real projects!"*