/*
给定 N 个区间 [a_i,b_i] 以及一个区间 [s,t]，请你选择尽量少的区间，将指定区间完全覆盖。
输出最少区间数，如果无法完全覆盖则输出 −1。
输入格式
第一行包含两个整数 s 和 t，表示给定区间的两个端点。

第二行包含整数 N，表示给定区间数。

接下来 N 行，每行包含两个整数 a_i,b_i，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。
如果无解，则输出 −1。

数据范围
1≤N≤10^5,
−10^9≤a_i≤b_i≤10^9,
−10^9≤s≤t≤10^9

输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
typedef std::pair<int, int> pii;
int main()
{
	int n, s, t;
	std::cin >> s >> t;
	std::vector<pii> ranges;
	std::cin >> n;
	while(n--)
	{
		int a_i, b_i;
		std::cin >> a_i >> b_i;
		ranges.push_back({a_i, b_i});
	}
	std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.first < b.first; });
	int start = s;
	int max = s, count = 0;
	bool if_cover = false;
	for(pii range : ranges)
	{
		if(range.first > start)
		{
			start = max;
			count++;
		}
		if(range.first <= start && range.second >= max)
		{
			max = range.second;
			if(max >= t)
			{
				count++, if_cover = true;
				break;
			}
		}
		else if(range.first > start) { break; }
	}
	if(if_cover) { std::cout << count << "\n"; }
	else { std::cout << -1 << "\n"; }
}
