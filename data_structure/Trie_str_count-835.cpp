/*
维护一个字符串集合，支持两种操作：
I x 向集合中插入一个字符串 x ；
Q x 询问一个字符串在集合中出现了多少次。
共有 N 个操作，所有输入的字符串总长度不超过 10^5，字符串仅包含小写英文字母。
输入格式
第一行包含整数 N，表示操作数。
接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。
输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
每个结果占一行。
数据范围
1≤N≤2∗10^4
输入样例：
5
I abc
Q abc
Q ab
I ab
Q ab
输出样例：
1
0
1
*/

#include <iostream>
#include <ostream>
#include <string>
#define N 100010
int Tree[N][26], Count[N][26], idx;

void insert(std::string& x)
{
	int p = 0, next;
	char ch;
	// 从第一个开始比对，有就走下一个，没有就增加节点
	for(int i = 0; i < x.size(); i++)
	{
		// 有就走下一个
		ch = x[i] - 'a';
		next = Tree[p][ch];
		if(!next)
		{
			next = ++idx;
			Tree[p][ch] = next;
		}
		p = next;
	}
	// 出来的next和ch一定是末尾的，比如空的时候输入a,那么Tree[0][a] = next = 1，ch=0 (对应a)
	Count[next][ch]++;
}

int query(std::string& x)
{
	int p = 0, next;
	char ch;
	for(int i = 0; i < x.size(); i++)
	{
		//
		ch = x[i] - 'a';
		next = Tree[p][ch];
		if(!next) { return 0; }
		p = next;
	}
	return Count[next][ch];
}

int main()
{
	int n;
	char op;
	std::string x;
	std::cin >> n;
	while(n--)
	{
		std::cin >> op >> x;
		switch(op)
		{
		case 'I':
			insert(x);
			break;
		case 'Q':
			std::cout << query(x) << std::endl;
			break;
		}
	}
	return 0;
}