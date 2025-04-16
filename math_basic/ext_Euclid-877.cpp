/*
给定 n 对正整数 a_i,b_i，对于每对数，求出一组 x_i,y_i，使其满足 a_i×x_i+b_i×y_i=gcd(a_i,b_i)。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 a_i,b_i。

输出格式
输出共 n 行，对于每组 a_i,b_i，求出一组满足条件的 x_i,y_i，每组结果占一行。

本题答案不唯一，输出任意满足条件的 x_i,y_i 均可。

数据范围
1≤n≤10^5,
1≤a_i,b_i≤2×10^9
输入样例：
2
4 6
8 18
输出样例：
-1 1
-2 1
*/

// #include <cstdio>
#include <iostream>

int ext_gcd(int a, int b, int& x, int& y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ext_gcd(b, a % b, x, y);
	int tmp_x = x;
	x = y, y = tmp_x - (a / b) * y;
	// printf("a is%d, b is%d\n", a, b);
	// std::cout << "in loop" << x << " " << y << "\n";
	return d;
}

int main()
{
	int n, a_i, b_i, x, y;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a_i >> b_i;
		ext_gcd(a_i, b_i, x, y);
		std::cout << x << " " << y << "\n";
	}
	return 0;
}