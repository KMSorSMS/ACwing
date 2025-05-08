/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数 N。
第二行包含 N 个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N≤1000，−10^9≤数列中的数≤10^9
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/
#include <algorithm>
#include <iostream>
#define N 1010

int a[N], v[N];

int main()
{
	int n, max = 0;
	std::cin >> n;
	for(int i = 1; i <= n; i++) { std::cin >> v[i]; }
	a[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = i - 1; j >= 1; j--)
		{
			if(v[j] < v[i]) { a[i] = std::max(a[j], a[i]); }
		}
		a[i] += 1;
		max = std::max(a[i], max);
	}
	std::cout << max << "\n";
	return 0;
}

/*
思路：
先确定集合，我们规定 a[i]表示的是，集合：所有以 第i个元素 作为最后一个元素的严格单调递增子序列，属性：其最大值就为a[i]
我们推导公式，对于：
a[i] = max(a[i-1],a[i-2],...,a[1]) + 1, 其中，a[i-1],a[i-2],...,都要满足v[...] < v[i],否则不考虑
我们有 a[1] = 1;
*/