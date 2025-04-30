/*
给定 n 组询问，每组询问给定三个整数 a,b,p，其中 p 是质数，请你输出 C_a^b mod p 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a,b,p。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤20,
1≤b≤a≤10^18,
1≤p≤10^5,

输入样例：
3
5 3 7
3 1 5
6 4 13
输出样例：
3
3
2
*/
// #include <cstdio>
#include <iostream>
const int N = 1e5 + 10;
typedef long long LL;
LL fac[N], invfac[N];

inline LL quick_pow(LL b, LL pow, LL p)
{
	LL res = 1;
	while(pow != 0)
	{
		if((pow & 1) == 1) { res = res * b % p; }
		b = b * b % p;
		pow = pow >> 1;
	}
	return res;
}

inline LL C(LL a, LL b, LL p)
{
	// printf("a is %lld, b is%lld, p is %lld\n", a, b, p);
	// printf("fac[a]%lld invfac[b]%lld, invfac[a-b]%lld\n", fac[a], invfac[b], invfac[a - b]);
	// if(a == b) return 1;
	LL res = fac[a] % p;
	res = res * invfac[b] % p;
	res = res * invfac[a - b] % p;
	// std::cout << "res in C is: " << res << "\n";
	return res;
}

LL lucas(LL a, LL b, LL p)
{
	LL res = C(a % p, b % p, p);
	// std::cout << "res in lucas is: " << res << "\n";
	if(a / p >= p || b / p >= p) { res = res * lucas(a / p, b / p, p) % p; }
	else { res = res * C(a / p, b / p, p) % p; }
	return res;
}

int main()
{
	LL a, b, p;
	int n;
	std::cin >> n;
	fac[0] = 1;
	invfac[0] = 1;
	while(n--)
	{
		std::cin >> a >> b >> p;
		// 初始化 fac 和 invfac
		for(int i = 1; i <= p; i++)
		{
			fac[i] = fac[i - 1] * i % p;
			invfac[i] = invfac[i - 1] * quick_pow(i, p - 2, p) % p;
		}
		LL res = lucas(a, b, p);
		std::cout << res << "\n";
	}
	return 0;
}

/*
lucas定理
C_a^b === C_(a/p)^(b/p) * C_(a%p)^(b%p) (mod p)
算更小的 C_a^b的时候，用费马小定理 === （a!) (mod p) * (b!)^-1 (mod p) * ((a-b)!)^-1 (mod p)

b^(p-1) === 1 (mod p)
b^-1 === b^(p-2) (mod p)
(b!)^-1 = ((b-1)!)^-1 * b^-1 mod p

先把a 和b 换成 p 进制数
a = a_k * p^k + a_(k-1) * p^(k-1) + ... + a_0 * p^(0)
b = b_k * p^k + b_(k-1) * p^(k-1) + ... + b_0 * p^(0)
这里把 a b的 k 对齐，可以允许高位为 0
(1+x)^p === 1 + x^p (mod p)
(1+x)^a === (1+x^(p^k))^(a_k) * (1+x^(p^(k-1)))^(a_(k-1)) * ... * (1+x^(p^(0)))^(a_(0)) (mod p)
则C_a^b === C_(a_k)^(b_k) * C_(a_(k-1))^(b_(k-1)) * ... * C_(a_0)^(b_0)
对于最后的C_(a_0)^(b_0)我们很容易的有 a_0 = a % p ; b_0 = b % p =>
= C_(a % p)^(b % p)
而对于剩下的部分：C_(a_k)^(b_k) * C_(a_(k-1))^(b_(k-1)) * ... * C_(a_1)^(b_1)
相当于是 
a / p = a_k * p^(k-1) + a_(k-2) * p^(k-2) + ... + a_1 * p^(0)
b / p = b_k * p^(k-1) + b_(k-2) * p^(k-2) + ... + b_1 * p^(0)
C_(a/p)^(b/p) = C_(a_k)^(b_k) * C_(a_(k-1))^(b_(k-1)) * ... * C_(a_1)^(b_1)
所以可以得到
C_a^b === C_(a/p)^(b/p) * C_(a%p)^(b%p) (mod p)
p 为质数
*/