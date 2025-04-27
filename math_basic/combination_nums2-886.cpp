/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 C_a^b mod (10^9+7)的值。
输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。
数据范围
1≤n≤10000,
1≤b≤a≤10^5

输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/

// #include <cstdio>
#include <iostream>
#define N 100010
const long long MOD = 1e9 + 7;
long long fac[N], infac[N];

inline long long quick_pow(long long b, long long pow)
{
	long long res = 1;
	while(pow != 0)
	{
		if((pow & 1) == 1) res = b * res % MOD;
		b = (b * b) % MOD;
		pow = pow >> 1;
	}
	return res;
}

int main()
{
	int n, a, b;
	std::cin >> n;
	fac[0] = infac[0] = 1;
	for(int i = 1; i <= 100000; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		infac[i] = infac[i - 1] * quick_pow(i, MOD - 2) % MOD;
	}
	// 根据表来出结果
	while(n--)
	{
		std::cin >> a >> b;
		// printf("fac[a]:%lld,infac[b]:%lld,infac[a-b]:%lld\n", fac[a], infac[b], infac[a - b]);
		int res = fac[a] * infac[b] % MOD * infac[a - b] % MOD;
		std::cout << res << "\n";
	}
	return 0;
}

/*
我们从公式出发 C_a^b = (a!) / (b! * (a-b)!) % MOD
那就有 C_a^b = (a! % MOD) * ((b!)^-1 % MOD) * (((a-b)!)^-1 % MOD)
对于逆元阶乘的模，同余数我们用费马小定理
对于质数MOD, 有 b^(MOD-1) === 1 （% MOD)
因为 b^(MOD-2)*b === 1 (% MOD) => b^-1 === b^(MOD-2) (% MOD)
因为(b!)^-1 % MOD === ((b-1)!*b)^-1 % MOD === ((b-1)!)^-1 * b^-1 % MOD
*/