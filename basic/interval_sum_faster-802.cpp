#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define N 300010

std::vector<int> all;
int a[N];

inline int find_index(int x);

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> add_, query_;
	int x, c;
	for(int i = 0; i < n; i++)
	{
		std::cin >> x >> c;
		add_.emplace_back(x, c);
		all.emplace_back(x);
	}
	int l, r;
	for(int i = 0; i < m; i++)
	{
		std::cin >> l >> r;
		query_.emplace_back(l, r);
		all.emplace_back(l), all.emplace_back(r);
	}
	// sort and remove repeate in `all`
	all.erase(std::unique(all.begin(), all.end()), all.end());
	std::sort(all.begin(), all.end());
	// give the discrete array a
	for(auto item : add_) { a[find_index(item.first)] += item.second; }
	// get the prefix sum
	for(int i = 1; i <= all.size(); i++) a[i] = a[i - 1] + a[i];
	// get the answer
	for(auto item : query_)
	{
		l = find_index(item.first), r = find_index(item.second);
		std::cout << a[r] - a[l - 1] << std::endl;
	}
	return 0;
}

int find_index(int x)
{
	int l = 0, r = all.size() - 1, mid;
	while(l <= r && r >= 0)
	{
		mid = (l + r) >> 1;
		if(all[mid] == x) return mid + 1;
		if(all[mid] < x)
			l = mid + 1;
		else // if(all[mid] > x)
			r = mid - 1;
	}
	// indicate that no find
	return -1;
}