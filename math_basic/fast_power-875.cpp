/*
给定 n 组 a_i,b_i,p_i，对于每组数据，求出 a_i^(b_i) mod p_i 的值。
输入格式
第一行包含整数 n。

接下来 n 行，每行包含三个整数 a_i,b_i,p_i。

输出格式
对于每组数据，输出一个结果，表示 a_i^(b_i) mod p_i 的值。
每个结果占一行。
数据范围
1≤n≤100000,
1≤a_i,b_i,p_i≤2×10^9

输入样例：
2
3 2 5
4 3 9
输出样例：
4
1
*/

#include <iostream>

int main()
{
	int n;
	long long res, a_i, b_i, p_i;
	char power;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		res = 1;
		std::cin >> a_i >> b_i >> p_i;
		while(b_i)
		{
			power = b_i & 0x1;
			if(power)
			{
				res = (res * a_i) % p_i;
				// std::cout << "the res in while is " << res << "\n";
			}
			a_i = a_i * a_i % p_i, b_i = b_i >> 1;
		}
		std::cout << res << "\n";
	}
	return 0;
}