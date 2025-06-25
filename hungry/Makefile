# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif


# 合并果子-148
# 区间选点-905

TARGET := 区间选点-905
TARGET_file := $(wildcard $(TARGET).c $(TARGET).cpp)
# # debug print Target_file
# $(info "debug print TARGET_file")
# $(info $(TARGET_file))
$(TARGET): $(TARGET_file) build
	g++ -std=c++11 -o build/$(TARGET) $(TARGET_file)
run:${TARGET}
	./build/$(TARGET)
debug:build
	g++ -g -o build/debug/$(TARGET) $(TARGET_file)
	$(DEBUGGER) build/debug/$(TARGET)

build:
	mkdir -p build
	mkdir -p build/debug
format:
	clang-format -i *.cpp
change_to_cpp:
	find . -type f -name "*.c" -exec bash -c 'mv "$0" "${0%.c}.cpp"' {} \;
git:
	git add .
	git commit -m ":zap: "
	git commit --amend 
.PHONY:build format