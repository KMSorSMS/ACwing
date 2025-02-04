#include <iostream>
#define N 1010

int matrix[N][N];

int main()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	// receive matrix input
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) { std::cin >> matrix[i][j]; }
	}
	// precompute prefix sum
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			matrix[i][j] += matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1];
		}
	}
	// then answer the queries
	int lux = 0, luy = 0, rdx = 0, rdy = 0;
	for(int i = 1; i <= q; i++)
	{
		std::cin >> lux >> luy >> rdx >> rdy;
		std::cout << (matrix[rdx][rdy] - matrix[rdx][luy - 1] - matrix[lux - 1][rdy] +
					  matrix[lux - 1][luy - 1])
				  << std::endl;
	}
}