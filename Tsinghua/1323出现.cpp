/*
给定 n 个自然数，求没有在这 n 个自然数中出现过的最小的自然数是多少。

注意，0 也是自然数。

输入格式
第一行输入一个正整数 n。

第二行输入给定的 n 个自然数，相邻两个自然数之间用一个空格隔开。

输出格式
输出只有一行，一个自然数，表示没有在输入的 n 个自然数中出现过的最小的自然数。

数据范围
1≤n≤1000,
输入的 n 个自然数都不大于 1000。

输入样例1：
7
2 1000 7 0 1 2 5
输出样例1：
3
输入样例2:
5
1 2 3 4 5
输出样例2：
0
*/
#include <iostream>
#define N 1010
bool occur[N];

int main()
{
	int n;
	std::cin >> n;
	while(n--)
	{
		int input;
		std::cin >> input;
		occur[input] = true;
	}
	for(int i = 0; i <= 1000; i++)
	{
		if(occur[i] == false)
		{
			std::cout << i << "\n";
			break;
		}
	}
	return 0;
}