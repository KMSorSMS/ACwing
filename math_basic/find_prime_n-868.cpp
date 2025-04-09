/*
给定一个正整数 n，请你求出 1∼n 中质数的个数。
输入格式
共一行，包含整数 n 。

输出格式
共一行，包含一个整数，表示 1∼n 中质数的个数。
数据范围
1≤n≤10^6
输入样例：
8
输出样例：
4
*/

#define N 1000010
bool not_prime[N];
int primes[N];

#include <iostream>

inline int count_prime(int& n)
{
	int res = 0;
	for(int i = 2; i <= n; i++)
	{
		if(!not_prime[i]) { primes[res++] = i; }
		for(int j = 0; j < res && primes[j] <= n / i; j++)
		{
			not_prime[primes[j] * i] = true;

			if(i % primes[j] == 0) { break; }
		}
	}
	return res;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << count_prime(n) << "\n";
    return 0;
}
