# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif


# single_linked_list-826
# double_linked_list-827
# double_linked_list_imp-827
# mock_stack-828
# mock_queue-829
# first_left_min-830
# calculate-3302
# sliding_window-154
# Trie_str_count-835
# max_xor_pair-143
# KMP_str-831
# merge_group-836
# connected_block-837
# foodchain_imp-240
# foodchain_imp2-240
# heapsort-838
# mock_heap-839
# mock_dis_link-840
# str_hash-841

TARGET := str_hash-841
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