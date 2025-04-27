# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the debugger based on the operating system
ifeq ($(UNAME_S), Darwin)
    DEBUGGER := lldb
else
    DEBUGGER := gdb
endif


# try_div-866
# split-867
# find_prime_n-868
# find_divisor-869
# divisor_nums-870
# divisor_sum-871
# gcd-872
# euler_func-873
# find_n_euler_func-874
# fast_power-875
# fast_power_inverse-876
# ext_Euclid-877
# ext_Euclid2_linear_remain-878
# hard_euclid3-204
# gaussian_del-883
# gaussian_del2-884
# combination_nums1-885
# combination_nums2-886

TARGET := combination_nums2-886
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