#include <iostream>
#include <vector>

std::vector<int> high_div_int(std::vector<int>& A, int& B, int& remain);

// there we have a large number to be divided and an int number to divide it.
int main()
{
	std::string A_str;
	std::vector<int> A, C;
	int B, remain = 0;
	std::cin >> A_str >> B;
	// we conver A_str to A vector, the higher position store lower number since we
	// operate A from its number's higher position to lower position
	for(int i = 0; i < A_str.size(); i++) { A.push_back(A_str[i] - '0'); }
	C = high_div_int(A, B, remain);
	//print the result
	for(int i = 0; i < C.size(); i++) std::cout << C[i];
	std::cout << std::endl << remain << std::endl;
}

std::vector<int> high_div_int(std::vector<int>& A, int& B, int& remain)
{
	std::vector<int> C;
	// first we just divide it bit by bit;
	for(int i = 0; i < A.size(); i++)
	{
		remain = remain * 10 + A[i];
		C.push_back(remain / B);
		remain = remain % B;
	}
	// we remove the leading zero
	while(C.size() > 1 && C.front() == 0) { C.erase(C.begin()); }
	return C;
}