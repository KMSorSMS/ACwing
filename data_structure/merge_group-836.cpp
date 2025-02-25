/*
一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。

现在要进行 m 个操作，操作共有两种：

M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；
输入格式
第一行输入整数 n 和 m。

接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。

输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。
每个结果占一行。

数据范围
1≤n,m≤105

输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
*/

#include <iostream>
#include <ostream>
#include <sys/types.h>
#define N 100010
uint Nums[N];

inline uint find(uint x)
{
	// std::cout << "find x: " << x << std::endl;
	if(Nums[x] != x) Nums[x] = find(Nums[x]);
	return Nums[x];
}

int main()
{
	uint n, a, b;
	int m;
	char op;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) Nums[i] = i;
	while(m--)
	{
		std::cin >> op >> a >> b;
		// while(Nums[a] != a) a = Nums[a];
		// while(Nums[b] != b) b = Nums[b];

		switch(op)
		{
		case 'M':
            a = find(a);
		    b = find(b);
			// 将a和b的集合合并
			Nums[b] = a;
			break;
		case 'Q':
           	while(Nums[a] != a) a = Nums[a];
		    while(Nums[b] != b) b = Nums[b]; 
			if(a == b)
				std::cout << "Yes\n";
			else
				std::cout << "No\n";
			break;
		}
	}
}