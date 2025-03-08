/*
维护一个集合，初始时集合为空，支持如下几种操作：

I x，插入一个数 x；
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 k 个插入的数；
C k x，修改第 k 个插入的数，将其变为 x；
现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。
输入格式
第一行包含整数 N。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。
输出格式
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
每个结果占一行。
数据范围
1≤N≤10^5
−10^9≤x≤10^9
数据保证合法。
输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
输出样例：
-10
6
*/

#include <iostream>
#include <ostream>
#include <string>
#define N 100010
// the K_H stores the index of kth insertion to its heap index
// the H_K stores the index of numbers in heap to its kth insertion
int HEAP[N], K_H[N], H_K[N];

inline void h_swap(int node1, int node2)
{
	int tmp1 = HEAP[node1], tmp2 = H_K[node1];
	HEAP[node1] = HEAP[node2];
	K_H[H_K[node1]] = node2, K_H[H_K[node2]] = node1;
	H_K[node1] = H_K[node2];

	HEAP[node2] = tmp1, H_K[node2] = tmp2;
}

inline void smaller_h_down(int node, int last)
{
	while(node <= last)
	{
		int left = node << 1, right = (node << 1) + 1, smaller;
		left = left > last ? node : left, right = right > last ? node : right;
		smaller = HEAP[left] < HEAP[right] ? left : right;
		if(HEAP[smaller] < HEAP[node])
		{
			// we need to exchange and then update node to its changed son (going down)
			h_swap(smaller, node);
			node = smaller;
		}
		else { break; }
	}
	// int left = (node << 1), right = (node << 1) + 1, smaller;
	// left = left > last ? node : left, right = right > last ? node : right;
	// smaller = HEAP[left] < HEAP[right] ? left : right;
	// if(HEAP[node] > HEAP[smaller])
	// {
	// 	// need to exchange
	// 	h_swap(node, smaller);
	// 	// recursively sort the changed val
	// 	smaller_h_down(smaller, last);
	// }
}

inline void smaller_h_up(int node)
{
	int fa = node >> 1;
	while(fa)
	{

		if(HEAP[node] < HEAP[fa])
		{
			h_swap(node, fa);
			node = fa;
			fa = node >> 1;
		}
		else { break; }
	}
	// while(node / 2 && HEAP[node / 2] > HEAP[node])
	// {
	// 	h_swap(node / 2, node);
	// 	node /= 2;
	// }
}

int main()
{
	int n, size = 0, x, k, node, k_num_ = 1;
	std::string op;
	scanf("%d", &n);
	while(n--)
	{
		std::cin >> op;
		if(op == "I")
		{
			std::cin >> x;
			HEAP[++size] = x;
			K_H[k_num_] = size, H_K[size] = k_num_;
			k_num_++;
			smaller_h_up(size);
		}
		else if(op == "PM") { std::cout << HEAP[1] << std::endl; }
		else if(op == "DM")
		{
			h_swap(1, size--);
			smaller_h_down(1, size);
		}
		else if(op == "D")
		{
			std::cin >> k;
			node = K_H[k];
			h_swap(node, size--);
			smaller_h_up(node), smaller_h_down(node, size);
		}
		else if(op == "C")
		{
			std::cin >> k >> x;
			node = K_H[k];
			HEAP[node] = x;
			smaller_h_up(node), smaller_h_down(node, size);
		}
	}
}