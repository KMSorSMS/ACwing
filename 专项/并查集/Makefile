# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif

# 格子游戏-1250
# 搭配购买-1252
# 程序自动分析-237
# 食物链-240
# 奇偶游戏-239
# 银河英雄传说-238

TARGET := 银河英雄传说-238
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