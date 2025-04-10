/*
给定 n 个正整数 a_i，对于每个整数 a_i，请你按照从小到大的顺序输出它的所有约数。
输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 a_i。

输出格式
输出共 n 行，其中第 i 行输出第 i 个整数 a_i 的所有约数。
数据范围
1≤n≤100,
1≤a_i≤2×10^9
输入样例：
2
6
8
输出样例：
1 2 3 6 
1 2 4 8 
*/
#define N 100010
#include <iostream>
int half[N];

inline void find_divisor(int& a_i)
{
	int count_half = 0;
	for(int i = 1; i <= a_i / i; i++)
	{
		if(a_i % i == 0)
		{
			std::cout << i << " ";
			if(a_i / i != i) half[count_half++] = a_i / i;
		}
		// while(a_i % i == 0) a_i /= i;
	}
	for(int i = count_half-1; i >= 0; i--) { std::cout << half[i] << " "; }
}

int main()
{
	int n, a;
	std::cin >> n;
	while(n--)
	{
		std::cin >> a;
		find_divisor(a);
		std::cout << "\n";
	}
	return 0;
}