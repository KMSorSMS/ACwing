/*
输入 a,b，求 C_a^b 的值。

注意结果可能很大，需要使用高精度计算。

输入格式共一行，包含两个整数 a 和 b。

输出格式
共一行，输出 C_a^b 的值。
数据范围
1≤b≤a≤5000
输入样例：
5 3
输出样例：
10
*/

#include <algorithm>
// #include <cstdio>
#include <iostream>
#define N 5010
#define M 10000

int primes[N], coeffi[N];
bool not_prime[N];
int prime_idx = 0;
int high_mul[M];

inline void find_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!not_prime[i]) primes[prime_idx++] = i;
		for(int j = 0; j < prime_idx && primes[j] <= n / i; j++)
		{
			not_prime[primes[j] * i] = true;
			if((i % primes[j]) == 0) break;
		}
	}
}

int get_prime_decompose(int a, int p)
{
	int res = 0;
	while(a)
	{
		res += a / p;
		a /= p;
	}
	return res;
}

inline int high_value_mul(int* a, int b, int idx)
{
	int inter = 0;
	for(int i = 0; i < idx; i++)
	{
		a[i] *= b;
		a[i] += inter;
		// printf("a[%d] is %d\n", i, a[i]);
		inter = a[i] / 10;
		a[i] %= 10;
		// printf("a[%d] is %d\n", i, a[i]);
	}
	a[idx] += inter;
	while(a[idx])
	{
		// printf("in \n");
		// printf("a[%d] is %d\n", idx, a[idx]);
		a[idx + 1] = a[idx] / 10;
		a[idx] %= 10;
		idx++;
	}
	return idx;
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	find_primes(std::max(a, b));
	high_mul[0] = 1;
	int idx = 1;
	// 质因数分解
	for(int i = 0; i < prime_idx; i++)
	{
		coeffi[i] = get_prime_decompose(a, primes[i]) - get_prime_decompose(b, primes[i]) -
					get_prime_decompose(a - b, primes[i]);
		// 进行高精度乘法，计算 primes 的 coeffi 次方的累积
		while(coeffi[i])
		{
			// printf("I'm in coeffi:%d,primes[%d] %d\n", coeffi[i], i, primes[i]);
			idx = high_value_mul(high_mul, primes[i], idx);
			coeffi[i]--;
		}
	}
	// 打印结果
	// std::cout << "idx is: " << idx << "\n";
	for(int i = idx - 1; i >= 0; i--) { std::cout << high_mul[i]; }
	std::cout << "\n";
}

/*
思路:
公式上：a! / (b! * (a-b)!)
我需要得到阶乘的质因数分解，首先得筛选出 1～max(a,b)范围内的质数，然后用公式：
a!关于 p分解的系数是: a/p + a/p^2 + a/p^3 ...
这样拆解之后，直接做减法，得到结果的质因数分解式子，然后做高精度乘法得到最终结果
*/