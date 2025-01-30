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

TARGET := longest_non_repeat_imp-799
TARGET_file := $(wildcard $(TARGET).c $(TARGET).cpp)
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
	clang-format -i *.c
.PHONY:build format