/*
输入 n 个数，问哪个数出现的次数最多。

如果有多个出现次数最多的数，输出最大的那个数。

输入格式
第一行有一个正整数 n。

第二行有 n 个正整数，表示每一个数，相邻两个数之间用一个空格隔开。

输出格式
只输出一个数即答案。

数据范围
保证 n 和输入的 n 个正整数都不会超过 2048。

输入样例：
7
2 3 6 2 3 6 7
输出样例：
6
*/

#include <iostream>
#define N 2048
int times[N];

int main()
{
	int n;
	std::cin >> n;
	int max = 0, index = 0;
	while(n--)
	{
		int input;
		std::cin >> input;
		times[input]++;
		if(max < times[input] || (max == times[input] && input > index))
		{
			max = times[input], index = input;
		}
	}
	std::cout << index << "\n";
	return 0;
}