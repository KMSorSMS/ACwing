#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define N 300010

int query_[N], sum_[N];

int main()
{
	int n = 0, m = 0, c = 0, x = 0;
	std::vector<int> index_;
	std::cin >> n >> m;
	std::unordered_map<int, int> index_val;
	for(int i = 0; i < n; i++)
	{
		std::cin >> x >> c;
		if(index_val.count(x) == 0)
		{
			index_val[x] = c;
			index_.emplace_back(x);
		}
		else
			index_val[x] += c;
	}
	int l = 0, r = 0;
	for(int i = 0; i < m; i++)
	{
		std::cin >> l >> r;
		query_[2 * i] = l, query_[2 * i + 1] = r;
		if(index_val.count(l) == 0) index_.emplace_back(l), index_val[l] = 0;
		if(index_val.count(r) == 0) index_.emplace_back(r), index_val[r] = 0;
	}
	// we sort the discrete index
	std::sort(index_.begin(), index_.end());
	// give the sum
	int i = 1;
	for(std::vector<int>::iterator it = index_.begin(); it != index_.end(); it++, i++)
	{
		sum_[i] = sum_[i - 1] + index_val[*it];
		// change the meaning of index_val from val to the corresponding index in sum_;
		index_val[*it] = i;
	}
	// give the answer
	for(int i = 0; i < m; i++)
	{
		l = index_val[query_[2 * i]], r = index_val[query_[2 * i + 1]];
		std::cout << sum_[r] - sum_[l - 1] << std::endl;
	}
	return 0;
}