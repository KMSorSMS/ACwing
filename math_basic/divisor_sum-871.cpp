/*
给定 n 个正整数 a_i，请你输出这些数的乘积的约数之和，答案对 10^9+7 取模。

输入格式
第一行包含整数 n 。

接下来 n 行，每行包含一个整数 a_i。
输出格式
输出一个整数，表示所给正整数的乘积的约数之和，答案需对 10^9+7 取模。
数据范围
1≤n≤100,
1≤a_i≤2×10^9
输入样例：
3
2
6
8
输出样例：
252
*/

#include <iostream>
#include <unordered_map>
#define N 10000010
const int MOD = 1000000007;

std::unordered_map<int, int> primes;

inline void find_primes_divisor(int& a_i)
{
	for(int i = 2; i <= a_i / i; i++)
	{
		while(a_i % i == 0)
		{
			a_i /= i;
			primes[i]++;
		}
	}
	if(a_i != 1) primes[a_i]++;
}

int main()
{
	int n, a;
	std::cin >> n;
	while(n--)
	{
		std::cin >> a;
		find_primes_divisor(a);
	}
	long long res = 1;
	for(auto prime : primes)
	{
		long long tmp = 1;
		while(prime.second--) { tmp = (tmp * prime.first + 1) % MOD; }
		res = res * tmp % MOD;
	}
	std::cout << res << "\n";
	return 0;
}
