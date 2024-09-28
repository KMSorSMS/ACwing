# quick_sort-785
# quick_sort-785-2
# quick_select-786
# merge_sort-787
# reverse_pairs-788
# number_range-789
# cubic_equation-790

TARGET := cubic_equation-790
$(TARGET): $(TARGET).c build
	gcc -o build/$(TARGET) $(TARGET).c
run:${TARGET}
	./build/$(TARGET)
debug:build
	gcc -g -o build/debug/$(TARGET) $(TARGET).c
	gdb build/debug/$(TARGET)

build:
	mkdir -p build
	mkdir -p build/debug
format:
	clang-format -i *.c
.PHONY:build format