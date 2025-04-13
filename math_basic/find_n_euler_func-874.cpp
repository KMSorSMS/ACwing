/*
给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。
输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中每个数的欧拉函数之和。
数据范围
1≤n≤10^6
输入样例：
6
输出样例：
12
*/

#include <iostream>
#define N 1000010

bool st[N];
int primes[N], idx = 0;
int phi[N];
int main()
{
	int n;
	std::cin >> n;
	long long res = 1;
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			primes[idx++] = i;
			phi[i] = i - 1, res += i - 1;
		}
		for(int j = 0; primes[j] <= n / i; j++)
		{
			st[i * primes[j]] = true;
			if(i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j], res += phi[i] * primes[j];
				break;
			}
			phi[i * primes[j]] = phi[i] * (primes[j] - 1), res += phi[i] * (primes[j] - 1);
		}
	}
	std::cout << res << "\n";
	return 0;
}