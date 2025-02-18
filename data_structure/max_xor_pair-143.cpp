/*
在给定的 N
个整数 A1，A2……AN
中选出两个进行 xor
（异或）运算，得到的结果最大是多少？
输入格式
第一行输入一个整数 N。
第二行输入 N 个整数 A1 ～AN。
输出格式
输出一个整数表示答案。
数据范围
1≤N≤10^5,
0≤Ai<2^31
输入样例：
3
1 2 3
输出样例：
3
*/
#include <iostream>
#include <ostream>
#define N 5000010

uint Trie[N][2], idx;

inline void insert(int x)
{
	uint p = 0, q, next;
	// printf("in insert");
	for(int i = 31; i >= 0; i--)
	{
		q = (x >> i) & 1;
		next = Trie[p][q];
		// 如果节点不存在的话
		if(!next)
		{
			// printf("add node from idx: %d\n", idx);
			Trie[p][q] = ++idx;
			next = idx;
		}
		p = next;
	}
}

inline int query(int x)
{
	// 找最大的异或值
	uint p = 0, q, next, result = 0;
	for(int i = 31; i >= 0; i--)
	{
		result = (result << 1);
		q = (x >> i) & 1;
		next = Trie[p][!q];
		// 这个值可以加上，和原值是不同的
		if(next) { result++, p = next; }
		else { p = Trie[p][q]; }
	}
	// printf("the result is :%d\n", result);
	return result;
}

int main()
{
	int n, x, result = 0, find;
	std::cin >> n;
	// 读的时候先遍历树找异或值，然后插入树
	for(int i = 0; i < n; i++)
	{
		std::cin >> x;
		find = query(x);
		result = find > result ? find : result;
		insert(x);
	}
	std::cout << result << std::endl;
	return 0;
}