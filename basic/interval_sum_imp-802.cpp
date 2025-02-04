#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#define N 300010

int discrete_nums[N], sum_[N];

int main()
{
	int n = 0, m = 0, c = 0, x = 0;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> add_, query_;
	std::vector<int> index_;
	for(int i = 0; i < n; i++)
	{
		std::cin >> x >> c;
		add_.emplace_back(x, c);
		index_.emplace_back(x);
	}
	int l = 0, r = 0;
	for(int i = 0; i < m; i++)
	{
		std::cin >> l >> r;
		query_.emplace_back(l, r);
		index_.emplace_back(l), index_.emplace_back(r);
	}
	// we sort the discrete index
	std::sort(index_.begin(), index_.end());
	// remove the repeat index
	index_.erase(std::unique(index_.begin(), index_.end()), index_.end());
	// give the sum
	std::unordered_map<int, int> index_val;
	// set the new discrete index mapping
	for(int i = 1; i <= index_.size(); i++) { index_val[index_[i - 1]] = i; }
	// give discrete num
	for(auto item : add_) { discrete_nums[index_val[item.first]] += item.second; }
	// give the prefix sum
	for(int i = 1; i <= index_.size(); i++) { sum_[i] = discrete_nums[i] + sum_[i - 1]; }
	// give the answer
	for(auto item : query_)
	{
		l = index_val[item.first], r = index_val[item.second];
		std::cout << sum_[r] - sum_[l - 1] << std::endl;
	}
	return 0;
}