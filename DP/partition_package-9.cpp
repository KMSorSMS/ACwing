/*
有 N 组物品和一个容量是 V 的背包。

每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 v_(ij) ，价值是 w_(ij)，其中 i 是组号，j 是组内编号。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。
接下来有 N 组数据：
每组数据第一行有一个整数 S_i，表示第 i 个物品组的物品数量；
每组数据接下来有 S_i 行，每行有两个整数 v_(ij),w_(ij)，用空格隔开，分别表示第 i 个物品组的第 j 个物品的体积和价值；
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤100
0<S_i≤100
0<v_(ij),w_(ij)≤100
输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/

#include <algorithm>
#include <iostream>
#define N 110
#define V 110
#define S 110

int f[V];
int v_[N][S], w_[N][S], s_[N];

int main()
{
	int n, v;
	std::cin >> n >> v;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> s_[i];
		for(int j = 1; j <= s_[i]; j++) { std::cin >> v_[i][j] >> w_[i][j]; }
	}
	// 遍历 n 组内容
	for(int i = 1; i <= n; i++)
	{
		bool in = true;
		for(int j = v; in && j >= 0; j--)
		{
			in = false;
			for(int s = 1; s <= s_[i]; s++)
			{
				if(j >= v_[i][s]) f[j] = std::max(f[j], f[j - v_[i][s]] + w_[i][s]), in = true;
			}
		}
	}
	std::cout << f[v] << "\n";
	return 0;
}