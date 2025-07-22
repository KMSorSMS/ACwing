/*
如果一个数 x 的约数之和 y（不包括他本身）比他本身小，那么 x 可以变成 y，y 也可以变成 x。

例如，4 可以变为 3，1 可以变为 7。

限定所有数字变换在不超过 n 的正整数范围内进行，求不断进行数字变换且不出现重复数字的最多变换步数。

输入格式
输入一个正整数 n。

输出格式
输出不断进行数字变换且不出现重复数字的最多变换步数。

数据范围
1≤n≤50000

输入样例：
7
输出样例：
3
样例解释
一种方案为：4→3→1→7。
*/
#include <iostream>

const int N = 50010;
const int M = 100010;
int divisor_sum[N];
using namespace std;
int h[N], e[M], ne[M], w[M];
int idx = 1;
bool st[N];
int MAX_ = 0;

inline void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

int dfs(int node, int fa)
{
	int max1 = 0, max2 = 0;
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int next_node = e[edge];
		if(next_node == fa) continue;
		int tmp_max = dfs(next_node, node) + w[edge];
		if(tmp_max > max1)
		{
			max2 = max1;
			max1 = tmp_max;
		}
		else if(tmp_max > max2) { max2 = tmp_max; }
	}
	st[node] = true;
	MAX_ = MAX_ > max1 + max2 ? MAX_ : max1 + max2;
	return max1;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 2; j * i <= n; j++) { divisor_sum[j * i] += i; }
	}
	// 加边
	for(int i = 1; i <= n; i++)
	{
		if(divisor_sum[i] < i && divisor_sum[i] != 0)
		{
			add_edge(i, divisor_sum[i], 1);
			add_edge(divisor_sum[i], i, 1);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!st[i]) { dfs(i, 0); }
	}
	cout << MAX_ << "\n";
	return 0;
}
