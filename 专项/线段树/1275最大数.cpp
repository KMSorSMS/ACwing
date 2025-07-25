/*
给定一个正整数数列 a1,a2,…,an，每一个数都在 0∼p−1 之间。

可以对这列数进行两种操作：
添加操作：向序列后添加一个数，序列长度变成 n+1；
询问操作：询问这个序列中最后 L 个数中最大的数是多少。
程序运行的最开始，整数序列为空。

一共要对整数序列进行 m 次操作。

写一个程序，读入操作的序列，并输出询问操作的答案。

输入格式
第一行有两个正整数 m,p，意义如题目描述；

接下来 m 行，每一行表示一个操作。

如果该行的内容是 Q L，则表示这个操作是询问序列中最后 L 个数的最大数是多少；

如果是 A t，则表示向序列后面加一个数，加入的数是 (t+a) mod p 。其中，t 是输入的参数，a 是在这个添加操作之前最后一个询问操作的答案（如果之前没有询问操作，则 a=0）。

第一个操作一定是添加操作。对于询问操作，L>0 且不超过当前序列的长度。

输出格式
对于每一个询问操作，输出一行。该行只有一个数，即序列中最后 L 个数的最大数。

数据范围
1≤m≤2×10^5,1≤p≤2×10^9,
0≤t<p
输入样例：
10 100
A 97
Q 1
Q 1
A 17
Q 2
A 63
Q 1
Q 1
Q 3
A 99
输出样例：
97
97
97
60
60
97
样例解释
最后的序列是 97,14,60,96。
4 1999999999
A 1999999998
Q 1
A 1999999998
Q 1

1999999998
1999999997
*/
#include <iostream>

using namespace std;
const int M = 2e5 + 10;

struct tree_node
{
	int l, r;
	int max;
};
tree_node tree[4 * M];
int m, p;

int query_tree(int l, int r, int idx)
{
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(l <= range_l && r >= range_r) { return tree[idx].max; }
	int tmp_max = 0;
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid >= l) tmp_max = max(tmp_max, query_tree(l, r, 2 * idx));
	if(mid < r) tmp_max = max(tmp_max, query_tree(l, r, 2 * idx + 1));
	return tmp_max;
}

int modify_tree(int point, int val, int idx)
{
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(range_l == point && range_r == point)
	{
		tree[idx].max = max(tree[idx].max, val);
		return tree[idx].max;
	}
	int tmp_max = tree[idx].max;
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid >= point)
		tmp_max = max(tmp_max, modify_tree(point, val, 2 * idx));
	else
		tmp_max = max(tmp_max, modify_tree(point, val, 2 * idx + 1));
	tree[idx].max = tmp_max;
	return tmp_max;
}

void build_tree(int l, int r, int idx)
{
	tree[idx] = {
		.l = l,
		.r = r,
	};
	if(l == r) return;
	int mid = l + ((r - l) >> 1);
	build_tree(l, mid, 2 * idx);
	build_tree(mid + 1, r, 2 * idx + 1);
}

int main()
{
	cin >> m >> p;
	build_tree(1, m, 1);
	unsigned long last = 0, t;
	int n = 1;
	for(int i = 0; i < m; i++)
	{
		char op;
		cin >> op >> t;
		if(op == 'A')
		{
			t = (t + last) % p;
			modify_tree(n, t, 1);
			n++;
		}
		else
		{
			int max_ = query_tree(n - t, n - 1, 1);
			cout << max_ << "\n";
			last = max_;
		}
	}
	return 0;
}