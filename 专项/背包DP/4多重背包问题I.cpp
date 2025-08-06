/*
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 s_i 件，每件体积是 v_i，价值是 w_i。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 v_i,w_i,s_i，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100

0<v_i,w_i,s_i≤100

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010, V = 110;

int v_s[N], w_s[N];
int f[V];
int idx = 0;
int v, n;

void add_package(int v_, int w_, int s_)
{
	int k = 1;
	while(k <= s_)
	{
		idx++;
		v_s[idx] = k * v_, w_s[idx] = k * w_;
		s_ -= k;
		k *= 2;
	}
	if(s_ > 0)
	{
		idx++;
		v_s[idx] = s_ * v_, w_s[idx] = s_ * w_;
	}
}

int main()
{
	cin >> n >> v;
	for(int i = 1; i <= n; i++)
	{
		int v_i, w_i, s_i;
		cin >> v_i >> w_i >> s_i;
		add_package(v_i, w_i, s_i);
	}
	for(int i = 1; i <= idx; i++)
	{
		for(int j = v; j >= v_s[i]; j--) { f[j] = max(f[j], w_s[i] + f[j - v_s[i]]); }
	}
	cout << f[v] << "\n";
	return 0;
}
