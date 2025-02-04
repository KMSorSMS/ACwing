#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> high_mul_high(std::vector<int> A, std::vector<int> B);

int main()
{
	// accept the user input string
	std::string str_A, str_B;
	// the number vector we will work on
	std::vector<int> A, B;
	// the user input
	std::cin >> str_A >> str_B;
	// we reverse the input and convert it to the corresponding number
	for(int i = str_A.size() - 1; i >= 0; i--) A.push_back(str_A[i] - '0');
	for(int j = str_B.size() - 1; j >= 0; j--) B.push_back(str_B[j] - '0');
	// then we do multiplication
	std::vector<int> C = high_mul_high(A, B);
	// print it out
	for(int i = 0; i < C.size(); i++) { std::cout << C[i]; }
	std::cout << std::endl;
}

// we do multiplication of two high precision number
std::vector<int> high_mul_high(std::vector<int> A, std::vector<int> B)
{
	// first we do multiply in per location(store in c which is has A's size times B's size in max)
	std::vector<int> C(A.size() + B.size());
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < B.size(); j++) { C[i + j] += A[i] * B[j]; }
	}
	// handle the carrier
	for(int i = 0; i < C.size() - 1; i++)
	{
		C[i + 1] += C[i] / 10;
		C[i] = C[i] % 10;
	}
	// handle the preceding zero
	while(C.size() > 1 && C.back() == 0) { C.pop_back(); }
	// then we need to reverse C to make the lower position the higher number
	std::reverse(C.begin(), C.end());
	return C;
}