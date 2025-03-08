/*
输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。
输入格式
第一行包含整数 n 和 m。
第二行包含 n 个整数，表示整数数列。
输出格式
共一行，包含 m个整数，表示整数数列中前 m 小的数。

数据范围
1≤m≤n≤10^5，
1≤数列中元素≤10^9

输入样例：
5 3
4 5 1 3 2
输出样例：
1 2 3
*/

#include <cstdio>
#define N 100010
int HEAP[N];
// sort the smaller heapwe
void small_heap_sort_(int node, int last)
{
	int left = (node << 1) + 1, right = (node << 1) + 2, smaller;
	if(left > last) return;
	right = right > last ? last : right;
	smaller = HEAP[left] < HEAP[right] ? left : right;
	if(HEAP[node] > HEAP[smaller])
	{
		// need to exchange
		int tmp = HEAP[smaller];
		HEAP[smaller] = HEAP[node];
		HEAP[node] = tmp;
		// recursively sort the changed val
		small_heap_sort_(smaller, last);
	}
}

int main()
{
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) { scanf("%d", &HEAP[i]); }
	n--;
	// from down to top, right to left we sort it
	for(int j = ((n - 1) >> 1); j >= 0; j--) { small_heap_sort_(j, n); }
	while(m--)
	{
		// need to show the first m number
		small_heap_sort_(0, n);
		// pop out the first by swap it with last
		printf("%d ", HEAP[0]);
		tmp = HEAP[0];
		HEAP[0] = HEAP[n];
		n--;
		// HEAP[n] = tmp; // no need to change HEAP[n] as we only need to print the res
	}
	printf("\n");
	return 0;
}