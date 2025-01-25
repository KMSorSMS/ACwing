#include <iostream>
#define N 100010

int diff[N];
int main()
{
	int m = 0, n = 0;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) { std::cin >> diff[i]; }
	// calculate the difference array
	for(int i = n; i >= 1; i--) { diff[i] = diff[i] - diff[i - 1]; }
	// we process the query to add the number
	int l = 0, r = 0, c = 0;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> l >> r >> c;
		diff[l] += c;
		diff[r + 1] -= c; // as the index r number still needs to add c
	}
	// add prefix sum to get the result
	for(int i = 1; i <= n; i++)
	{
		diff[i] = diff[i] + diff[i - 1];
		std::cout << diff[i] << ' ';
	}
}