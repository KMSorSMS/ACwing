/*
实现一个双链表，双链表初始为空，支持 5 种操作：
在最左侧插入一个数；
在最右侧插入一个数；
将第 k 个插入的数删除；
在第 k 个插入的数左侧插入一个数；
在第 k 个插入的数右侧插入一个数
现在要对该链表进行 M 次操作，进行完所有操作后，从左到右输出整个链表。

注意:题目中第 k 个插入的数并不是指当前链表的第 k 个数。
例如操作过程中一共插入了 n个数，则按照插入的时间顺序，这 n 个数依次为：
第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数。

输入格式
第一行包含整数 M ，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：
L x，表示在链表的最左端插入数 x 。
R x，表示在链表的最右端插入数 x 。
D k，表示将第 k 个插入的数删除。
IL k x，表示在第 k 个插入的数左侧插入一个数。
IR k x，表示在第 k 个插入的数右侧插入一个数。
输出格式
共一行，将整个链表从左到右输出。
数据范围
1≤M≤100000
输入样例：
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
输出样例：
8 7 7 3 2 9
所有操作保证合法
*/

#include <iostream>
#include <ostream>
#include <string>
#define N 100010

int e[N], ne[N], bf[N], idx, head, end;

inline void init()
{
	idx = 0, head = -1, end = -1;
}

inline void insert_r_most(int x)
{
	e[idx] = x, ne[idx] = -1, bf[idx] = end;
	if(end == -1) { head = idx; }
	else { ne[end] = idx; }
	end = idx++;
}

inline void insert_l_most(int x)
{

	e[idx] = x, bf[idx] = -1, ne[idx] = head;
	if(head == -1) { end = idx; }
	else { bf[head] = idx; }
	head = idx++;
}

inline void delete_k(int k)
{
	if(k == end)
	{
		// std::cout << "bfk is:" << bf[k] << std::endl;
		if(bf[k] == -1) { head = -1; }
		else { ne[bf[k]] = -1; }
		end = bf[k];
	}
	else if(k == head)
	{
		if(ne[k] == -1) { end = -1; }
		else { bf[ne[k]] = -1; }
		head = ne[k];
	}
	else
	{
		ne[bf[k]] = ne[k];
		bf[ne[k]] = bf[k];
	}
}

inline void insert_l_k(int k, int x)
{
	e[idx] = x, ne[idx] = k, bf[idx] = bf[k];
	if(k == head) { head = idx; }
	else { ne[bf[k]] = idx; }
	bf[k] = idx++;
}

inline void insert_r_k(int k, int x)
{
	e[idx] = x, ne[idx] = ne[k], bf[idx] = k;
	if(k == end) { end = idx; }
	else { bf[ne[k]] = idx; }
	ne[k] = idx++;
}
inline void print_link()
{
	for(int i = head; i != -1; i = ne[i]) { std::cout << e[i] << ' '; }
	std::cout << std::endl;
}
int main()
{
	init();
	int M, k, x;
	std::cin >> M;
	std::string op;
	for(int i = 0; i < M; i++)
	{
		std::cin >> op;
		if(op == "L")
		{
			std::cin >> x;
			insert_l_most(x);
		}
		else if(op == "R")
		{
			std::cin >> x;
			insert_r_most(x);
		}
		else if(op == "D")
		{
			std::cin >> k;
			delete_k(k - 1);
		}
		else if(op == "IL")
		{
			std::cin >> k >> x;
			insert_l_k(k - 1, x);
		}
		else if(op == "IR")
		{
			std::cin >> k >> x;
			insert_r_k(k - 1, x);
		}
		else { std::cout << "Invalid op " << op << std::endl; }
	}
	print_link();
	return 0;
}