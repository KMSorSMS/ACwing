#include <iostream>
#include <ostream>
#define N 1010
#define M 1010
int diff_matrix[N][M];
int main()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	// store the sum matrix
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) { std::cin >> diff_matrix[i][j]; }
	}
	// we reverse it to diff matrix
	for(int i = n; i >= 1; i--)
	{
		for(int j = m; j >= 1; j--)
		{
			diff_matrix[i][j] = diff_matrix[i][j] - diff_matrix[i][j - 1] - diff_matrix[i - 1][j] +
								diff_matrix[i - 1][j - 1];
		}
	}
	int c = 0, leftup_x, leftup_y, rightdown_x, rightdown_y;
	for(int i = 1; i <= q; i++)
	{
		std::cin >> leftup_x >> leftup_y >> rightdown_x >> rightdown_y >> c;
		//update the difference matrix
		diff_matrix[leftup_x][leftup_y] += c;
		diff_matrix[leftup_x][rightdown_y + 1] -= c;
		diff_matrix[rightdown_x + 1][leftup_y] -= c;
		diff_matrix[rightdown_x + 1][rightdown_y + 1] += c;
	}
	// give the result
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			diff_matrix[i][j] +=
				diff_matrix[i][j - 1] + diff_matrix[i - 1][j] - diff_matrix[i - 1][j - 1];
			std::cout << diff_matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}