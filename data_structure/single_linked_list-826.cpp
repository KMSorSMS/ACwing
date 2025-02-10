/*
题目描述：
实现一个单链表，链表初始为空，支持三种操作：

向链表头插入一个数；
删除第 k个插入的数后面的一个数；
在第 k个插入的数后插入一个数。
现在要对该链表进行 M次操作，进行完所有操作后，从头到尾输出整个链表。

注意:题目中第 k个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了n个数，则按照插入的时间顺序，
这n个数依次为：第1个插入的数，第 2 个插入的数，…第 n 个插入的数。
输入格式
第一行包含整数M，表示操作次数。
接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：
H x，表示向链表头插入一个数 x。
D k，表示删除第 k 个插入的数后面的数（当 k为 0 时，表示删除头结点）。
I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）。
输出格式
共一行，将整个链表从头到尾输出。

数据范围
1≤M≤100000

所有操作保证合法。
*/
#include <iostream>

#define N 100010

int e[N], ne[N], idx, head;
// e store data,ne store next

// struct Node
// {
// 	int data;
// 	struct Node* next;
// };

// Node nodes[N];

inline void init_link()
{
	idx = 0; //index to be inserted
	head = -1; // current head index
}
inline void insert_k(int k, int data)
{
	e[idx] = data;
	ne[idx] = ne[k - 1];
    ne[k - 1] = idx++;
}
inline void insert_head(int data)
{
	e[idx] = data;
	ne[idx] = head;
	head = idx++;
}
inline void delete_k(int k)
{
	ne[k - 1] = ne[ne[k - 1]];
}

int main()
{
	int M;
	std::cin >> M;
	int x, k;
	char op;
	init_link();
	for(int i = 0; i < M; i++)
	{
		std::cin >> op;
		switch(op)
		{
		case 'H':
			std::cin >> x;
			insert_head(x);
			break;
		case 'D':
			std::cin >> k;
			// rm head node
			if(!k) { head = ne[head]; }
			else { delete_k(k); }
			break;
		case 'I':
			std::cin >> k >> x;
			insert_k(k, x);
			break;
		default:
			std::cout << "invalid op: " << op << std::endl;
			break;
		}
	}
	while(head != -1)
	{
		std::cout << e[head] << ' ';
		head = ne[head];
	}
	return 0;
}