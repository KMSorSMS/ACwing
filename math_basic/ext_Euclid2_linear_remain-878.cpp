/*
给定 n 组数据 a_i,b_i,m_i，对于每组数求出一个 x_i，使其满足 a_i×x_i≡b_i(mod m_i)，如果无解则输出 impossible。

输入格式
第一行包含整数 n 。

接下来 n 行，每行包含一组数据 a_i,b_i,m_i。

输出格式
输出共 n 行，每组数据输出一个整数表示一个满足条件的 x_i，如果无解则输出 impossible。
每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。

输出答案必须在 int 范围之内。

数据范围
1≤n≤10^5,
1≤a_i,b_i,m_i≤2×10^9

输入样例：
2
2 3 6
4 3 5
输出样例：
impossible
-3
*/

#include <iostream>

long long ext_gcd(long long a, long long b, long long& x, long long& y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	long long d = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	long long n, a_i, b_i, m_i, x, y;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a_i >> b_i >> m_i;
		long long d = ext_gcd(a_i, m_i, x, y);
		if(b_i % d)
			std::cout << "impossible\n";
		else
			std::cout << (b_i / d * x) % m_i<< "\n";
	}
}

/*
思路： a_i * x_i 和 b_i 关于 m_i 同余的意思，就是 a_i * x_i == y * m_i + b_i
也就是说，a_i * x_i + y * m_i == b_i 
有解的话，b_i 必须是 a_i 和 m_i 的公约数的倍数（充要条件）
而解这个，就是 gcd 里面，传入满足 b*y + (a-a/b*b)*x = d
得到 a*x + b(y-(a/b)*x) = d，所以迭代传出的 x = x,y = y-(a/b)*x;
*/