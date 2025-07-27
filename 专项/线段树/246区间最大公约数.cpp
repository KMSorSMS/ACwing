/*
给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
Q l r，表示询问 A[l],A[l+1],…,A[r] 的最大公约数(GCD)。
对于每个询问，输出一个整数表示答案。

输入格式
第一行两个整数 N,M。

第二行 N 个整数 A[i]。

接下来 M 行表示 M 条指令，每条指令的格式如题目描述所示。

输出格式
对于每个询问，输出一个整数表示答案。

每个答案占一行。

数据范围
N≤500000,M≤100000,
1≤ A[i] ≤ 10^18,
|d| ≤ 10^18,
保证数据在计算过程中不会超过 long long 范围。

输入样例：
5 5
1 3 5 7 9
Q 1 5
C 1 5 1
Q 1 5
C 3 3 6
Q 2 4
输出样例：
1
2
4
*/

#include <cstdio>
#include <cstdlib>
// #include <iostream>
const int N = 5e5 + 10, M = 1e5 + 10;
typedef long long ll;
int n, m;

ll w[N];

struct tree_node
{
	int l, r;
	ll sum, gcd;
};
tree_node tree[4 * N];
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

void pushup(tree_node& node, tree_node& node_l, tree_node& node_r)
{
	node.sum = node_l.sum + node_r.sum;
	node.gcd = gcd(node_l.gcd, node_r.gcd);
}

void pushup(int idx)
{
	pushup(tree[idx], tree[2 * idx], tree[2 * idx + 1]);
}

void build_tree(int l, int r, int idx)
{
	if(l == r)
	{
		tree[idx] = {l, r, w[l] - w[l - 1], w[l] - w[l - 1]};
		return;
	}
	int mid = l + ((r - l) >> 1);
	build_tree(l, mid, 2 * idx);
	build_tree(mid + 1, r, 2 * idx + 1);
	tree[idx] = {l, r};
	pushup(idx);
}

tree_node query_tree(int l, int r, int idx)
{
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(l <= range_l && r >= range_r) { return tree[idx]; }
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid < l)
		return query_tree(l, r, 2 * idx + 1);
	else if(mid >= r)
		return query_tree(l, r, 2 * idx);
	else
	{
		tree_node node_l = query_tree(l, r, 2 * idx);
		tree_node node_r = query_tree(l, r, 2 * idx + 1);
		tree_node res;
		pushup(res, node_l, node_r);
		return res;
	}
}

void modify_tree(int point, ll val, int idx)
{
	if(point > n || point < 1) return;
	int range_l = tree[idx].l, range_r = tree[idx].r;
	if(range_l == point && range_r == point)
	{
		tree[idx] = {point, point, val + tree[idx].sum, val + tree[idx].gcd};
		return;
	}
	int mid = range_l + ((range_r - range_l) >> 1);
	if(mid >= point)
		modify_tree(point, val, 2 * idx);
	else
		modify_tree(point, val, 2 * idx + 1);
	pushup(idx);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) { scanf("%lld", &w[i]); }
	build_tree(1, n, 1);
	while(m--)
	{
		char op[2];
		scanf("%s", op);
		if(*op == 'Q')
		{
			int l, r;
			scanf("%d%d", &l, &r);
			tree_node left_node = query_tree(1, l, 1);
			tree_node range_node = l + 1 <= r ? query_tree(l + 1, r, 1) : tree_node{0, 0, 0, 0};
			ll res = std::abs(gcd(left_node.sum, range_node.gcd));
			// std::cout << res << "\n";
			std::printf("%lld\n", res);
		}
		else
		{
			int l, r;
			ll x;
			scanf("%d%d%lld", &l, &r, &x);
			modify_tree(l, x, 1);
			modify_tree(r + 1, -x, 1);
		}
	}
	return 0;
}
