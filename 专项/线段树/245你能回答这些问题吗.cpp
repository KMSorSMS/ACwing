/*
给定长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
1 x y，查询区间 [x,y] 中的最大连续子段和
2 x y，把 A[x] 改成 y。
对于每个查询指令，输出一个整数表示答案。
输入格式
第一行两个整数 N,M。

第二行 N 个整数 A[i]。

接下来 M 行每行 3 个整数 k,x,y，k=1 表示查询（此时如果 x>y，请交换 x,y），k=2 表示修改。

输出格式
对于每个查询指令输出一个整数表示答案。

每个答案占一行。

数据范围
N≤500000,M≤100000,
−1000≤A[i]≤1000
输入样例：
5 3
1 2 -3 4 5
1 2 3
2 2 -1
1 3 2
输出样例：
2
-1
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;
const int N = 5e5 + 10;
int w[N];

struct tree_node
{
	int l, r;
	int l_max, r_max, max_, sum;
};

tree_node tree[4 * N];

void pushup(tree_node& node, tree_node& l_node, tree_node& r_node)
{
	node.l_max = max(l_node.l_max, l_node.sum + r_node.l_max);
	node.r_max = max(r_node.r_max, r_node.sum + l_node.r_max);
	node.sum = l_node.sum + r_node.sum;
	node.max_ = max(max(l_node.max_, r_node.max_), l_node.r_max + r_node.l_max);
	// printf("r_max:%d,l_max:%d,max:%d\n", r_node.max_, l_node.max_, node.max_);
}

void pushup(int idx)
{
	tree_node l_node = tree[2 * idx], r_node = tree[2 * idx + 1];
	pushup(tree[idx], l_node, r_node);
}

void build_tree(int l, int r, int idx)
{
	tree[idx] = {
		.l = l,
		.r = r,
	};
	if(l == r)
	{
		tree[idx] = {l, r, w[l], w[l], w[l], w[l]};
		return;
	}
	int mid = l + ((r - l) >> 1);
	build_tree(l, mid, 2 * idx);
	build_tree(mid + 1, r, 2 * idx + 1);
	pushup(idx);
}

tree_node query_tree(int l, int r, int idx)
{
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(range_l >= l && range_r <= r) { return tree[idx]; }
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid + 1 > r)
		return query_tree(l, r, 2 * idx);
	else if(mid < l)
		return query_tree(l, r, 2 * idx + 1);
	else
	{
		tree_node l_node = query_tree(l, r, 2 * idx);
		tree_node r_node = query_tree(l, r, 2 * idx + 1);
		tree_node res_node;
		pushup(res_node, l_node, r_node);
		// printf("left:%d,right:%d,res_node_max:%d\n", range_l, range_r, res_node.max_);
		return res_node;
	}
}

void modify_tree(int point, int val, int idx)
{
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(range_l == point && range_r == point)
	{
		tree[idx] = {point, point, val, val, val, val};
		return;
	}
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid >= point) { modify_tree(point, val, 2 * idx); }
	else { modify_tree(point, val, 2 * idx + 1); }
	// printf("l:%d,r:%d,idx:%d\n", range_l, range_r, idx);
	pushup(idx);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) { cin >> w[i]; }
	build_tree(1, n, 1);
	for(int i = 1; i <= m; i++)
	{
		int k, x, y;
		cin >> k >> x >> y;
		if(k == 1)
		{
			if(x > y) swap(x, y);
			tree_node tmp_max = query_tree(x, y, 1);
			cout << tmp_max.max_ << "\n";
		}
		else { modify_tree(x, y, 1); }
	}
	return 0;
}