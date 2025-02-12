/*
实现一个栈，栈初始为空，支持四种操作：

push x – 向栈顶插入一个数 x；
pop – 从栈顶弹出一个数；
empty – 判断栈是否为空；
query – 查询栈顶元素。
现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4都要输出相应的结果。

输入格式
第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。

其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示栈顶元素的值。

数据范围
1≤M≤100000,
1≤x≤109
所有操作保证合法，即不会在栈为空的情况下进行 pop 或 query 操作。
输入样例：
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty
输出样例：
5
5
YES
4
NO
*/

#include <iostream>
#include <string>
#define N 100010
int stack = -1, data[N];

inline void push(int x)
{
	data[++stack] = x;
}

inline void pop()
{
	stack--;
}

inline bool empty()
{
	return stack == -1;
}

inline int query()
{
	return data[stack];
}

int main()
{
	int M, x;
	std::string op;
	std::cin >> M;
	while(M--)
	{
		std::cin >> op;
		if(op == "push")
		{
			std::cin >> x;
			push(x);
		}
		else if(op == "pop") { pop(); }
		else if(op == "empty")
		{
			if(empty()) { std::cout << "YES" << std::endl; }
			else { std::cout << "NO" << std::endl; }
		}
		else if(op == "query") { std::cout << query() << std::endl; }
	}
}
