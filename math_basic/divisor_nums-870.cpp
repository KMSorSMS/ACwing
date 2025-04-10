/*
给定 n 个正整数 a_i，请你输出这些数的乘积的约数个数，答案对 10^9+7取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 a_i。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对 10^9+7 取模。

数据范围
1≤n≤100,
1≤a_i≤2×10^9
输入样例：
3
2
6
8
输出样例：
12
*/

#include <iostream>
#include <unordered_map>
const int MOD = 1000000007;
std::unordered_map<int, int> h;

int main()
{
	int n, a;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a;
		// 寻找a的质因数
		for(int prime_ = 2; prime_ <= a / prime_; prime_++)
		{
			while(a % prime_ == 0) { a /= prime_, h[prime_]++; }
		}
		if(a != 1) h[a]++;
	}
	long long res = 1;
	for(const auto& pair : h)
	{
		res *= (pair.second + 1);
		res %= MOD;
	}
	std::cout << res << "\n";
	return 0;
}