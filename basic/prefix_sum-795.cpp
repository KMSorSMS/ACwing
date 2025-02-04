#include <iostream>
#define N 100010

int nums[N], s[N];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) std::cin >> nums[i];
	// std::cout << "input_done m is " << m << " n is " << n << std::endl;
	s[0] = 0;
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i];
	int l, r;
	for(int i = 0; i < m; i++)
	{
		std::cin >> l >> r;
		std::cout << (s[r] - s[l - 1]) << std::endl;
	}
	return 0;
}