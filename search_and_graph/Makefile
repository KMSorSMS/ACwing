# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif


# sort_num-842
# eight_queen-843
# solve_maze-844
# solve_maze_imp-844
# eight_num_code-845
# center_of_tree-846
# point_layer-847
# topology_sort-848
# dijkstra01-849
# dijkstra01_imp-849
# dijkstra02-850
# restrict_shortest-853
# spfa_shortest-851
# spfa_find_negtive-852
# floyd_shortest-854
# prime_min_tree-858
# kruskal-859
# draw_2_split-860
# max_2_graph_match-861

TARGET := max_2_graph_match-861
TARGET_file := $(wildcard $(TARGET).c $(TARGET).cpp)
# # debug print Target_file
# $(info "debug print TARGET_file")
# $(info $(TARGET_file))
build/$(TARGET): $(TARGET_file) build
	g++ -std=c++11 -o build/$(TARGET) $(TARGET_file)
run: build/${TARGET}
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
.PHONY:format