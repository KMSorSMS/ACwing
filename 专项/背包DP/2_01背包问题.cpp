/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 v_i，价值是 w_i。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 v_i,w_i，用空格隔开，分别表示第 i 件物品的体积和价值。

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
8
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010, VW = 1010;
int v[N], w[N];
int f[VW];

int n, v_;

int main()
{
	cin >> n >> v_;
	for(int i = 1; i <= n; i++) { cin >> v[i] >> w[i]; }
	for(int i = 1; i <= n; i++)
	{
		for(int j = v_; j >= v[i]; j--) { f[j] = max(f[j], w[i] + f[j - v[i]]); }
	}
	cout << f[v_] << "\n";
	return 0;
}
