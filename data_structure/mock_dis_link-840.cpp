/*
维护一个集合，支持如下几种操作：
I x，插入一个整数 x；
Q x，询问整数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。
输入格式
第一行包含整数 N，表示操作数量。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。
输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
每个结果占一行。
数据范围
1≤N≤10^5
−10^9≤x≤10^9
输入样例：
5
I 1
I 2
I 3
Q 2
Q 5
输出样例：
Yes
No
*/

#include <cstring>
#include <iostream>
#define N 200003

int Nums[N];
const int Null = 0x3f3f3f3f;

inline int find_(int x)
{
	int k = (x % N + N) % N;
	while(Nums[k] != Null && Nums[k] != x)
	{
		k++;
		if(k == N) k = 0;
	}
	return k;
}

int main()
{
	int n, x;
	char op;
	std::cin >> n;
	memset(Nums, 0x3f, 4*N);
	while(n--)
	{
		std::cin >> op >> x;
		int k = find_(x);
		if(op == 'I') { Nums[k] = x; }
		else
		{
			if(Nums[k] == Null)
				std::cout << "No\n";
			else
				std::cout << "Yes\n";
		}
	}
	return 0;
}
