/*
给定 2n 个整数 a1,a2,…,an 和 m1,m2,…,mn，求一个最小的非负整数 x，满足 ∀i∈[1,n],x≡mi(mod ai)。

输入格式第 1 行包含整数 n。

第 2…n+1 行：第 i+1 行包含两个整数 ai 和 mi，数之间用空格隔开。

输出格式
输出最小非负整数 x，如果 x 不存在，则输出 −1。

数据范围
1≤ai≤2^31−1,
0≤mi<ai
1≤n≤25

所有 mi 的最小公倍数在 64 位有符号整数范围内。

输入样例：
2
8 7
11 9
输出样例：
31
*/

// #include <cstdio>
#include <iostream>

long long extgcd(long long a1, long long a2, long long& k1, long long& k2)
{
	if(!a2)
	{
		k1 = 1, k2 = 0;
		return a1;
	}
	long long d = extgcd(a2, a1 % a2, k2, k1);
	k2 = k2 - a1 / a2 * k1;
	return d;
}

int main()
{
	long long n, a1, a2, m1, m2, k1, k2;
	std::cin >> n >> a1 >> m1;
	for(long long i = 1; i < n; i++)
	{
		std::cin >> a2 >> m2;
		long long d = extgcd(a1, a2, k1, k2);
		if((m2 - m1) % d)
		{
			std::cout << "-1\n";
			return 0;
		}
		k1 = ((m2 - m1) / d) * k1 % (a2 / d);
		m1 = m1 + k1 * a1;
		a1 = a2 * a1 / d;
	}
	// printf("m1:%lld,a1:%lld\n", m1, a1);
	long long res = m1 % a1;
	if(res < 0) res += a1;
	std::cout << res << "\n";
	return 0;
}

/*
思路：
先看前两个方程组，要
x = m1 + a1 * k1, x = m2 + a2 * k2; (已知 a1 a2 m1 m2)=>
a1 * k1 - a2 * k2 = m2 - m1 => 可以得到解（充要条件是 m2 - m1 是a1 和 a2 的最大公因数的倍数)(找到的 k1_s 和 k2_s,是一组特解)
则任意解就是: k1 = k1_s + k * a2/d ; k2 = k2_s + k * a1/d (仅有一个自由度)
则 x = (m1 + k1_s * a1) + k * (a2 * a1 / d)
    这个是特解 x (常数等价m3')    这个是变化 k * 常数 (等价 a3' * k3')
和下一个方程
   x = m3               + k3 * a3
如此可以减少方程组，直到为一个方程
    x = m + k * a
此时解 x的最小非负数 就是 m % a
*/