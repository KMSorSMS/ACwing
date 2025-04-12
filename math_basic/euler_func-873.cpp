/*
给定 n 个正整数 a_i，请你求出每个数的欧拉函数。
欧拉函数的定义
1∼N 中与 N 互质的数的个数被称为欧拉函数，记为 ϕ(N)。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 a_i。

输出格式
输出共 n 行，每行输出一个正整数 a_i的欧拉函数。

数据范围
1≤n≤100,
1≤a_i≤2×10^9

输入样例：
3
3
6
8
输出样例：
2
2
4
*/

#include <iostream>
int main()
{
	int n, a;
	std::cin >> n;
	while(n--)
	{
		std::cin >> a;
		long long res = a;
		for(int i = 2; i <= a / i; i++)
		{
			if(a % i == 0)
			{
				res = res * (i - 1) / i;
				while(a % i == 0) a /= i;
			}
		}
		if(a != 1) res = res * (a - 1) / a;
		std::cout << res << "\n";
	}
	return 0;
}