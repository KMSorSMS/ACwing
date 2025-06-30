/*
给定 N 个闭区间 [a_i,b_i]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。
输入格式
第一行包含整数 N，表示区间数。
接下来 N 行，每行包含两个整数 a_i,b_i，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

数据范围
1≤N≤10^5,−10^9≤a_i≤b_i≤10^9

输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/
#include <algorithm>
// #include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
typedef std::pair<int, int> pii;

int main()
{
	int n, n_;
	std::vector<pii> ranges;
	std::cin >> n;
	n_ = n;
	while(n_--)
	{
		int a, b;
		std::cin >> a >> b;
		ranges.push_back({a, b});
	}
	std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.first < b.first; });
	std::priority_queue<int, std::vector<int>, std::greater<int>> s;
	s.push(ranges.begin()->second);
	for(int i = 1; i < n; i++)
	{
		if(ranges[i].first > s.top())
		{
			s.pop();
			s.push(ranges[i].second);
		}
		else { s.push(ranges[i].second); }
	}
	std::cout << s.size() << "\n";
	return 0;
}