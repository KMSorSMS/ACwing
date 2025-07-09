/*
在实现程序自动分析的过程中，常常需要判定一些约束条件是否能被同时满足。
考虑一个约束满足问题的简化版本：假设 x1,x2,x3,… 代表程序中出现的变量，给定 n 个形如 x_i=x_j 或 x_i≠x_j 的变量相等/不等的约束条件，请判定是否可以分别为每一个变量赋予恰当的值，使得上述所有约束条件同时被满足。

例如，一个问题中的约束条件为：x_1=x_2，x_2=x_3，x_3=x_4，x_1!=x_4，这些约束条件显然是不可能同时被满足的，因此这个问题应判定为不可被满足。

现在给出一些约束满足问题，请分别对它们进行判定。

输入格式
输入文件的第 1 行包含 1 个正整数 t，表示需要判定的问题个数，注意这些问题之间是相互独立的。

对于每个问题，包含若干行：

第 1 行包含 1 个正整数 n，表示该问题中需要被满足的约束条件个数。

接下来 n 行，每行包括 3 个整数 i,j,e，描述 1 个相等/不等的约束条件，相邻整数之间用单个空格隔开。若 e=1，则该约束条件为 x_i=x_j；若 e=0，则该约束条件为 x_i≠x_j。

输出格式
输出文件包括 t 行。

输出文件的第 k 行输出一个字符串 YES 或者 NO，YES 表示输入中的第 k 个问题判定为可以被满足，NO 表示不可被满足。

数据范围
1≤t≤10
1≤n≤10^5
1≤i,j≤10^9
输入样例：
2
2
1 2 1
1 2 0
2
1 2 1
2 1 1
输出样例：
NO
YES
*/
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <utility>
#define N 100010
typedef std::pair<int, int> pii;
int a[N], hash_key_table[2 * N], hash_value_table[2 * N];
pii not_equals[N];
int idx = 1;
std::unordered_map<int, int> mp;

// inline int find_x(int key)
// {
// 	int init_idx = key % N;
// 	while(hash_key_table[init_idx] != 0 && hash_key_table[init_idx] != key) { init_idx++; }
// 	if(hash_key_table[init_idx] == key) return hash_value_table[init_idx];
// 	hash_key_table[init_idx] = key, hash_value_table[init_idx] = idx++;
// 	return (idx - 1);
// }

int find_class(int node)
{
	int class_ = a[node];
	if(a[node] != node) class_ = find_class(a[node]);
	a[node] = class_;
	return class_;
}

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		// memset(hash_key_table, 0, sizeof(hash_key_table));
		// memset(hash_value_table, 0, sizeof(hash_value_table));
		idx = 1;
		mp.clear();
		int n, not_equal_count = 0;
		std::cin >> n;
		for(int i = 0; i < 2 * N; i++)
		{
			a[i] = i;
			// hash_key_table[i] = 0, hash_value_table[i] = 0;
		}
		while(n--)
		{
			int x_i, x_j, op;
			std::cin >> x_i >> x_j >> op;
			int idx_i, idx_j;
			if(mp.count(x_i))
				idx_i = mp[x_i];
			else
			{
				idx_i = idx;
				mp[x_i] = idx++;
			}
			// =================
			if(mp.count(x_j))
				idx_j = mp[x_j];
			else
			{
				idx_j = idx;
				mp[x_j] = idx++;
			}

			if(op == 0) { not_equals[not_equal_count++] = {idx_i, idx_j}; }
			else
			{
				int class_i = find_class(idx_i), class_j = find_class(idx_j);
				if(class_i != class_j) { a[class_i] = class_j; }
			}
		}
		bool if_right = true;
		for(int i = 0; i < not_equal_count; i++)
		{
			int class_i = find_class(not_equals[i].first),
				class_j = find_class(not_equals[i].second);
			if(class_i == class_j)
			{
				if_right = false;
				break;
			}
		}
		if(if_right)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}
