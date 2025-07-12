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

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
std::unordered_map<int, int> ranges_l;
std::unordered_map<int, int> ranges_r;
std::unordered_map<std::pair<int, int>, int> if_odd;


int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		std::string op;
		std::cin >> l >> r >> op;
		int even_odd = 0;
		if(op == "even")
			even_odd = 0;
		else
			even_odd = 1; //代表奇数

		if(if_odd.count({l, r}) && if_odd[{l, r}] != even_odd)
		{
			std::cout << i << "\n";
			break;
		}
		else { ranges_l[l] = r, ranges_r[r] = l, if_odd[{l, r}] = even_odd; }
		int l_l = l, r_r = r, even_odd_l = 0, even_odd_r = 0;
		if(ranges_r.count(l - 1))
		{
			int even_odd_l = even_odd;
			even_odd_l = if_odd[{ranges_r[l - 1], l - 1}];
			l_l = ranges_r[l - 1];
			if(if_odd.count({l_l, r}) && if_odd[{l_l, r}] != (even_odd_l ^ even_odd))
			{
				std::cout << i << "\n";
				break;
			}
			else
			{
				ranges_l[l_l] = r, ranges_r[r] = l_l,
				if_odd[{l_l, r_r}] = (even_odd ^ even_odd_l ^ even_odd_r);
			}
		}
		if(ranges_l.count(r + 1))
		{
			even_odd_r = if_odd[{r + 1, ranges_l[r + 1]}];
			r_r = ranges_l[r + 1];
			if(if_odd.count({l, r_r}) && if_odd[{l, r_r}] != (even_odd_r ^ even_odd))
			{
				std::cout << i << "\n";
				break;
			}
		}
		if(if_odd.count({l_l, r_r}) && if_odd[{l_l, r_r}] != (even_odd ^ even_odd_l ^ even_odd_r))
		{
			std::cout << i << "\n";
			break;
		}
		ranges_l[l_l] = r_r, ranges_r[r_r] = l_l,
		if_odd[{l_l, r_r}] = (even_odd ^ even_odd_l ^ even_odd_r);
	}
}
