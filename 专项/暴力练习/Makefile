# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif

# 849Dijkstra求最短路I
# 850Dijkstra求最短路II
# 854Floyd求最短路
# P8815逻辑表达式
# 3302表达式求值
# P8815逻辑表达式_imp
# 799最长连续不重复子序列
# 800数组元素的目标和
# 858Prim算法求最小生成树
# 859Kruskal算法求最小生成树
# test
# 846树的重心
# 847图中点的层次
# 848有向图的拓扑序列
# 173矩阵距离
# 173矩阵距离_imp
# 843n-皇后问题

TARGET := 843n-皇后问题
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