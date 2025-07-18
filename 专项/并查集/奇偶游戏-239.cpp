/*
小 A 和小 B 在玩一个游戏。
首先，小 A 写了一个由 0 和 1 组成的序列 S，长度为 N。
然后，小 B 向小 A 提出了 M 个问题。
在每个问题中，小 B 指定两个数 l 和 r，小 A 回答 S[l∼r] 中有奇数个 1 还是偶数个 1。
机智的小 B 发现小 A 有可能在撒谎。
例如，小 A 曾经回答过 S[1∼3] 中有奇数个 1，S[4∼6] 中有偶数个 1，现在又回答 S[1∼6] 中有偶数个 1，显然这是自相矛盾的。
请你帮助小 B 检查这 M 个答案，并指出在至少多少个回答之后可以确定小 A 一定在撒谎。
即求出一个最小的 k ，使得 01 序列 S 满足第 1∼k 个回答，但不满足第 1∼k+1 个回答。
输入格式
第一行包含一个整数 N，表示 01 序列长度。
第二行包含一个整数 M，表示问题数量。
接下来 M 行，每行包含一组问答：两个整数 l 和 r，以及回答 even 或 odd，用以描述 S[l∼r] 中有偶数个 1 还是奇数个 1。
输出格式
输出一个整数 k，表示 01 序列满足第 1∼k 个回答，但不满足第 1∼k+1 个回答，如果 01 序列满足所有回答，则输出问题总数量。

数据范围
N≤10^9,M≤5000

输入样例：
10
5
1 2 even
3 4 odd
5 6 even
1 6 even
7 10 odd
输出样例：
3
*/

// #include <cstdio>
#include <iostream>
#include <unordered_map>
#define N 10010
using namespace std;
unordered_map<int, int> class_map;
int idx = 1;
int p[N], d[N];

int find(int x)
{
	if(p[x] != x)
	{
		int t = find(p[x]);
		d[x] = (d[x] + d[p[x]]) % 2;
		p[x] = t;
	}
	return p[x];
}

int main()
{
	int n, m;
	cin >> n >> m;
	bool if_right = true;
	int ans = m;
	for(int i = 0; i <= 2 * m; i++)
	{
		p[i] = i;
		d[i] = 0;
	}
	for(int i = 0; i < m; i++)
	{
		int l, r;
		string op;
		cin >> l >> r >> op;
		if(if_right)
		{
			l = l - 1;
			if(class_map.count(l) == 0) class_map[l] = idx++;
			if(class_map.count(r) == 0) class_map[r] = idx++;
			int l_idx = class_map[l], r_idx = class_map[r];
			int l_class = find(l_idx), r_class = find(r_idx);
			if(op == "even")
			{
				// printf("l_class is %d,r_class is %d, l_idx %d,r_idx %d\n",
				// 	   l_class,
				// 	   r_class,
				// 	   l_idx,
				// 	   r_idx);
				if(l_class != r_class)
				{
					p[r_class] = l_class;
					d[r_class] = (d[l_idx] + 2 - d[r_idx]) % 2;
				}
				else if((d[l_idx] % 2) != (d[r_idx] % 2)) { if_right = false, ans = i; }
				// printf("d[l_idx]:%d,d[r_idx]:%d\n", d[l_idx], d[r_idx]);
			}
			else
			{
				// printf("l_class is %d,r_class is %d, l_idx %d,r_idx %d\n",
				// 	   l_class,
				// 	   r_class,
				// 	   l_idx,
				// 	   r_idx);
				if(l_class != r_class)
				{
					p[r_class] = l_class;
					d[r_class] = (d[l_idx] + 3 - d[r_idx]) % 2;
				}
				else if((d[l_idx] + 1) % 2 != (d[r_idx]) % 2) { if_right = false, ans = i; }
				// printf("d[l_idx]:%d,d[r_idx]:%d\n", d[l_idx], d[r_idx]);
			}
		}
	}
	cout << ans << "\n";
}