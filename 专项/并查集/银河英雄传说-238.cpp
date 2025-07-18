/*
有一个划分为 N 列的星际战场，各列依次编号为 1,2,…,N。
有 N 艘战舰，也依次编号为 1,2,…,N，其中第 i 号战舰处于第 i 列。
有 T 条指令，每条指令格式为以下两种之一：
M i j，表示让第 i 号战舰所在列的全部战舰保持原有顺序，接在第 j 号战舰所在列的尾部。
C i j，表示询问第 i 号战舰与第 j 号战舰当前是否处于同一列中，如果在同一列中，它们之间间隔了多少艘战舰。
现在需要你编写一个程序，处理一系列的指令。

输入格式
第一行包含整数 T ，表示共有 T 条指令。

接下来 T 行，每行一个指令，指令有两种形式：M i j 或 C i j。

其中 M 和 C 为大写字母表示指令类型，i 和 j 为整数，表示指令涉及的战舰编号。

输出格式
你的程序应当依次对输入的每一条指令进行分析和处理：
如果是 M i j 形式，则表示舰队排列发生了变化，你的程序要注意到这一点，但是不要输出任何信息；

如果是 C i j 形式，你的程序要输出一行，仅包含一个整数，表示在同一列上，
第 i 号战舰与第 j 号战舰之间布置的战舰数目，如果第 i 号战舰与第 j 号战舰当前不在同一列上，则输出 −1。

数据范围
N≤30000,T≤500000

输入样例：
4
M 2 3
C 1 2
M 2 4
C 4 2
输出样例：
-1
1
*/

#include <iostream>
#include <utility>
#define N 30010
int p[N], depth[N], d_seq[N];
typedef std::pair<int, int> pii;

pii find_(int x)
{
	int depth_ = depth[x];
	if(p[x] != x)
	{
		pii t = find_(p[x]);
		depth_ += t.second;
		p[x] = t.first;
	}
	depth[x] = depth_;
	return {p[x], depth_};
}

int main()
{
	int t;
	std::cin >> t;
	// init
	for(int i = 0; i < N; i++) { p[i] = i, depth[i] = 0, d_seq[i] = 1; }
	while(t--)
	{
		char op;
		int i_, j_;
		std::cin >> op >> i_ >> j_;
		pii i_class_pii = find_(i_), j_class_pii = find_(j_);
		int i_class = i_class_pii.first, j_class = j_class_pii.first;
		if(op == 'M')
		{
			if(i_class != j_class)
			{
				p[i_class] = j_class;
				depth[i_class] = d_seq[j_class];
				d_seq[j_class] += d_seq[i_class];
			}
		}
		else
		{
			if(i_class != j_class)
				std::cout << "-1\n";
			else
			{
				int result = depth[i_] - depth[j_];
				result = result < 0 ? -result : result;
				result--;
				if(result < 0) result = 0;
				std::cout << result << "\n";
			}
		}
	}
	return 0;
}
