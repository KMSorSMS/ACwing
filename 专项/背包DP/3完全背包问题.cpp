/*
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
第 i 种物品的体积是 v_i，价值是 w_i。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行两个整数 v_i,w_i，用空格隔开，分别表示第 i 种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<v_i,w_i≤1000

输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
10
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4 + 10, V = 1e3 + 10;
int v_s[N], w_s[N];
int f[V];
int idx = 0;
int v, n;

void add_package(int v_, int w_)
{
	while(v_ <= v)
	{
		idx++;
		v_s[idx] = v_, w_s[idx] = w_;
		v_ *= 2, w_ *= 2;
	}
}

int main()
{
	cin >> n >> v;
	for(int i = 1; i <= n; i++)
	{
		int v_, w_;
		cin >> v_ >> w_;
		add_package(v_, w_);
	}
	for(int i = 1; i <= idx; i++)
	{
		for(int j = v; j >= v_s[i]; j--) { f[j] = max(f[j], f[j - v_s[i]] + w_s[i]); }
	}
	cout << f[v] << "\n";
	return 0;
}
