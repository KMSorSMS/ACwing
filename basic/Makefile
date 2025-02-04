# quick_sort-785
# quick_sort-785-2
# quick_select-786
# merge_sort-787
# reverse_pairs-788
# number_range-789
# cubic_equation-790
# high_precision_add-791
# high_precision_sub-792
# high_precision_mul-793
# high_precision_mul_re-793
# high_precision_div-794
# high_precision_div_re-794
# prefix_sum-795
# matrix_sum-796
# difference-797
# difference_matrix-798
# longest_non_repeat-799
# longest_non_repeat_imp-799
# array_target_sum-800
# sub_seq-2816
# binary_ones-801
# interval_sum-802
# interval_sum_imp-802
# interval_sum_faster-802

TARGET := interval_sum_faster-802
TARGET_file := $(wildcard $(TARGET).c $(TARGET).cpp)
# # debug print Target_file
# $(info "debug print TARGET_file")
# $(info $(TARGET_file))
$(TARGET): $(TARGET_file) build
	g++ -std=c++17 -o build/$(TARGET) $(TARGET_file)
run:${TARGET}
	./build/$(TARGET)
debug:build
	g++ -g -o build/debug/$(TARGET) $(TARGET_file)
	gdb build/debug/$(TARGET)

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