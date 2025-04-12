/*
给定 n 对正整数 a_i,b_i，请你求出每对数的最大公约数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数对 a_i,b_i。

输出格式
输出共 n 行，每行输出一个整数对的最大公约数。
数据范围
1≤n≤10^5,
1≤ai,bi≤2×10^9
输入样例：
2
3 6
4 6
输出样例：
3
2
*/

// ensure a > b
#include <iostream>
int gcd(int a, int b)
{
	a = a % b;
	if(a == 0)
		return b;
	else
		return gcd(b, a);
}

int main()
{
	int n, a, b;
	std::cin >> n;
	while(n--)
	{
		std::cin >> a >> b;
		if(a > b)
			std::cout << gcd(a, b) << "\n";
		else
			std::cout << gcd(b, a) << "\n";
	}
	return 0;
}