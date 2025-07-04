/*
有 n 个人排队到 1 个水龙头处打水，第 i 个人装满水桶所需的时间是 t_i，请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？
输入格式
第一行包含整数 n。
第二行包含 n 个整数，其中第 i 个整数表示第 i 个人装满水桶所花费的时间 t_i。
输出格式
输出一个整数，表示最小的等待时间之和。

数据范围
1≤n≤10^5,
1≤t_i≤10^4

输入样例：
7
3 6 1 4 2 5 7
输出样例：
56
*/

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
int main()
{
	int n;
	std::cin >> n;
	std::priority_queue<int, std::vector<int>, std::greater<int>> time;
	while(n--)
	{
		int t;
		std::cin >> t;
		time.push(t);
	}
	unsigned long count = 0;
	n = time.size();
	for(int i = n - 1; i > 0; i--)
	{
		count += time.top() * i;
		time.pop();
	}
	std::cout << count << "\n";
	return 0;
}