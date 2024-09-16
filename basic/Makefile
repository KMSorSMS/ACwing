# quick_sort-785
# quick_sort-785-2
# quick_select-786
TARGET := quick_select-786
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
.PHONY:build