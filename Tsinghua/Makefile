# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif

# U412490数数
# U412534公司
# U419307毕业照
# U560763_Movie
# 1323出现
# 1328众数
# 3397众数
# 3400统计次数
# 4520质数
# 1324五子棋
# 1329文件系统
# 1336矩阵
# U419115售货机
# U414310k叉树
# U276782字符串
# U414204总k次方差
# U414149考试
# U414209租约机制_大模拟
# U419470水滴
# U416819擂台赛

TARGET := U416819擂台赛
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