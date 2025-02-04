#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define N 100010

std::vector<std::pair<int, int>> _intervals;

int main()
{
	int n;
	std::cin >> n;
	int l, r;
	for(int i = 0; i < n; i++)
	{
		std::cin >> l >> r;
		_intervals.emplace_back(l, r);
	}
	// sort on pair will first by the first elem and then second elem by default
	std::sort(_intervals.begin(), _intervals.end());
	int count = 1;
	std::pair<int, int> max_inter = _intervals[0];
	for(int i = 1; i < _intervals.size(); i++)
	{
		l = _intervals[i].first, r = _intervals[i].second;
		if(l > max_inter.second) { count++, max_inter = {l, r}; }
		else if(r > max_inter.second) { max_inter.second = r; }
	}
	std::cout << count << std::endl;
	return 0;
}