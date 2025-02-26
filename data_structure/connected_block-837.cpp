/*
给定一个包含 n 个点（编号为 1∼n ）的无向图，初始时图中没有边。
现在要进行 m 个操作，操作共有三种：
C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
Q2 a，询问点 a 所在连通块中点的数量；
输入格式
第一行输入整数 n 和 m。
接下来 m 行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。
输出格式 对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。

对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量

每个结果占一行。

数据范围
1≤n,m≤10^5

输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
输出样例：
Yes
2
3
*/
#include <iostream>
#include <ostream>
#include <sys/types.h>

#define N 100010

uint Nums[N], Count[N];

inline uint find(uint x)
{
	if(x != Nums[x]) Nums[x] = find(Nums[x]);
	return Nums[x];
}

int main()
{
	int m, n;
	uint a, b;
	std::string OP;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) { Nums[i] = i, Count[i] = 1; }
	while(m--)
	{
		std::cin >> OP >> a;
		if(OP == "C")
		{
			std::cin >> b;
			// 连线
			a = find(a);
			b = find(b);
            // 只会在双方不在同一个集合里面的时候更新
			if(a != b)
			{
				Nums[b] = a;
				Count[a] += Count[b];
			}
		}
		else if(OP == "Q1")
		{
			std::cin >> b;
			a = find(a);
			b = find(b);
			if(a == b)
				std::cout << "Yes\n";
			else
				std::cout << "No\n";
		}
		else if(OP == "Q2")
		{
			a = find(a);
			std::cout << Count[a] << std::endl;
		}
	}
	return 0;
}