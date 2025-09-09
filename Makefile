# Makefile for C Training Course
# Giáo viên: 15 năm kinh nghiệm lập trình
# Mục đích: Biên dịch tất cả examples và exercises một cách dễ dàng

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Directories
EXAMPLES_DIR = examples
EXERCISES_DIR = exercises
BUILD_DIR = build

# Create build directory
$(BUILD_DIR):
	@echo "Tạo thư mục build..."
	@mkdir -p $(BUILD_DIR)/{basic,intermediate,advanced,exercises}

# Build all examples
all: $(BUILD_DIR) basic intermediate advanced
	@echo "✅ Đã biên dịch thành công tất cả examples!"
	@echo "💡 Tip: Chạy 'make run-basic' để test các chương trình cơ bản"

# Basic examples
basic: $(BUILD_DIR)
	@echo "📚 Biên dịch examples cơ bản..."
	@mkdir -p $(BUILD_DIR)/basic
	@if [ -d "$(EXAMPLES_DIR)/basic" ] && [ -n "$$(ls -A $(EXAMPLES_DIR)/basic/*.c 2>/dev/null)" ]; then \
		for file in $(EXAMPLES_DIR)/basic/*.c; do \
			name=$$(basename $$file .c); \
			echo "  - Biên dịch $$name..."; \
			$(CC) $(CFLAGS) $$file -o $(BUILD_DIR)/basic/$$name; \
		done; \
	else \
		echo "  ⚠️  Chưa có file nào trong $(EXAMPLES_DIR)/basic/"; \
	fi

# Intermediate examples
intermediate: $(BUILD_DIR)
	@echo "📖 Biên dịch examples trung cấp..."
	@mkdir -p $(BUILD_DIR)/intermediate
	@if [ -d "$(EXAMPLES_DIR)/intermediate" ] && [ -n "$$(ls -A $(EXAMPLES_DIR)/intermediate/*.c 2>/dev/null)" ]; then \
		for file in $(EXAMPLES_DIR)/intermediate/*.c; do \
			name=$$(basename $$file .c); \
			echo "  - Biên dịch $$name..."; \
			$(CC) $(CFLAGS) $$file -o $(BUILD_DIR)/intermediate/$$name; \
		done; \
	else \
		echo "  ⚠️  Chưa có file nào trong $(EXAMPLES_DIR)/intermediate/"; \
	fi

# Advanced examples  
advanced: $(BUILD_DIR)
	@echo "🚀 Biên dịch examples nâng cao..."
	@mkdir -p $(BUILD_DIR)/advanced
	@if [ -d "$(EXAMPLES_DIR)/advanced" ] && [ -n "$$(ls -A $(EXAMPLES_DIR)/advanced/*.c 2>/dev/null)" ]; then \
		for file in $(EXAMPLES_DIR)/advanced/*.c; do \
			name=$$(basename $$file .c); \
			echo "  - Biên dịch $$name..."; \
			$(CC) $(CFLAGS) $$file -o $(BUILD_DIR)/advanced/$$name; \
		done; \
	else \
		echo "  ⚠️  Chưa có file nào trong $(EXAMPLES_DIR)/advanced/"; \
	fi

# Debug builds
debug: CFLAGS += $(DEBUG_FLAGS)
debug: all
	@echo "🐛 Debug build hoàn thành!"

# Release builds
release: CFLAGS += $(RELEASE_FLAGS)  
release: all
	@echo "🚀 Release build hoàn thành!"

# Run basic examples for testing
run-basic: basic
	@echo "🏃 Chạy thử các chương trình cơ bản..."
	@for exe in $(BUILD_DIR)/basic/*; do \
		if [ -x "$$exe" ]; then \
			echo "--- Chạy $$(basename $$exe) ---"; \
			$$exe; \
			echo ""; \
		fi \
	done

# Clean build files
clean:
	@echo "🧹 Dọn dẹp files build..."
	@rm -rf $(BUILD_DIR)
	@echo "✅ Đã dọn dẹp xong!"

# Help target
help:
	@echo "📖 Makefile cho Khóa Học Lập Trình C"
	@echo ""
	@echo "Các lệnh có sẵn:"
	@echo "  make all        - Biên dịch tất cả examples"
	@echo "  make basic      - Biên dịch examples cơ bản"  
	@echo "  make intermediate - Biên dịch examples trung cấp"
	@echo "  make advanced   - Biên dịch examples nâng cao"
	@echo "  make debug      - Biên dịch với debug flags"
	@echo "  make release    - Biên dịch tối ưu cho release"
	@echo "  make run-basic  - Chạy thử các chương trình cơ bản"
	@echo "  make clean      - Dọn dẹp files build"
	@echo "  make help       - Hiển thị help này"
	@echo ""
	@echo "💡 Tip: Luôn chạy 'make clean' trước khi 'make all' để đảm bảo build sạch!"

.PHONY: all basic intermediate advanced debug release run-basic clean help