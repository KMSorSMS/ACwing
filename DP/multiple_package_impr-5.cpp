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
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。
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
#include <iostream>
#define N 25000
#define V 2010

int f[V];
int v_[N], w_[N];

int main()
{
	int n, v, v_i, w_i, s_i, n_all = 1;
	std::cin >> n >> v;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> v_i >> w_i >> s_i;
		// 切割 s_i;
		for(int k = 1; k < s_i; k *= 2)
		{
			v_[n_all] = k * v_i;
			w_[n_all] = k * w_i;
			s_i -= k;
			n_all++;
		}
		if(s_i)
		{
			v_[n_all] = s_i * v_i;
			w_[n_all] = s_i * w_i;
			n_all++;
		}
	}
	n_all--;
	// 做标准的 0 1 背包，商品总数变成了 n_all 个
	for(int i = 1; i <= n_all; i++)
	{
		for(int j = v; j >= v_[i]; j--) { f[j] = std::max(f[j], f[j - v_[i]] + w_[i]); }
	}
	std::cout << f[v] << "\n";
}

/*
思路：
把多重背包问题的 s_i 进行拆解，s_i 应该被按照 1,2,4,...,2^k, remain 这样拆分，
每个代表了新的物品，以及新的价值（也就是系数*原来的价值），其中 1～2^k = 2^(k+1) -1,这是它们组合可以表示的最大值，低于这个值的所有数都能被表示，
然后加上 remain < 2^(k+1),那么就能表示 remain <= 2^(k+1) -1 ~ s_i 的所有值，那么就能完美覆盖完所有 s_i 的选择，就能等效替代为 01 背包问题
*/
