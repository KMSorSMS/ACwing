/*
输入一个包含 n 个方程 n 个未知数的线性方程组。方程组中的系数为实数。

求解这个方程组。

输入格式
第一行包含整数 n 。

接下来 n 行，每行包含 n+1 个实数，表示一个方程的 n 个系数以及等号右侧的常数。

输出格式
如果给定线性方程组存在唯一解，则输出共 n 行，其中第 i 行输出第 i 个未知数的解，结果保留两位小数。
注意：本题有 SPJ，当输出结果为 0.00 时，输出 -0.00 也会判对。在数学中，一般没有正零或负零的概念，所以严格来说应当输出 0.00，但是考虑到本题作为一道模板题，考察点并不在于此，在此处卡住大多同学的代码没有太大意义，故增加 SPJ，对输出 -0.00 的代码也予以判对。

如果给定线性方程组存在无数解，则输出 Infinite group solutions。

如果给定线性方程组无解，则输出 No solution。

数据范围
1≤n≤100,
所有输入系数以及常数均保留两位小数，绝对值均不超过 100。

输入样例：
3
1.00 2.00 -1.00 -6.00
2.00 1.00 -3.00 -9.00
-1.00 -1.00 2.00 7.00
输出样例：
1.00
-2.00
3.00
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
const int N = 110;
const double eps = 1e-6;
int n;

double a[N][N + 1];

inline void print_all()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++) { printf("%f ", a[i][j]); }
		printf("\n");
	}
}

inline int gauss()
{
	int row = 0, rank = 0;
	// printf("n is %d\n", n);
	for(int c = 0; c < n; c++)
	{
		int max_row_idx = row;
		double max_row = fabs(a[row][c]);
		for(int r = row; r < n; r++)
		{
			if(fabs(a[r][c]) > max_row) max_row = fabs(a[r][c]), max_row_idx = r;
		}
		// printf("the max_row is%f , the max_row_idx is: %d\n", max_row, max_row_idx);
		// 交换到最新的 row
		for(int col_change = c; col_change <= n; col_change++)
			std::swap(a[row][col_change], a[max_row_idx][col_change]);
		// print_all();
		// printf("\n");
		// leading 1 为 0的情况，就走到下一个
		if(max_row < eps)
		{
			// printf("max row is:%f\n", max_row);
			row++;
			continue;
		}
		rank++; //秩+1
		// printf("rank is %d\n", rank);
		// 更新本行
		double div = a[row][c];
		for(int c_update = c; c_update <= n; c_update++)
		{
			// printf("row %d,c_update %d,a[row][c_update] %f,a[row][c] %f \n", row, c_update, a[row][c_update],a[row][c]);
			a[row][c_update] /= div;
			// printf("row %d,c_update %d,a[row][c_update] %f,a[row][c] %f \n", row, c_update, a[row][c_update],a[row][c]);
		}
		// print_all();
		// printf("\n");
		// 更新剩下的
		for(int r = row + 1; r < n; r++)
		{
			double mul = a[r][c];
			for(int c_update = c; c_update <= n; c_update++)
			{
				a[r][c_update] -= a[row][c_update] * mul;
			}
		}
		// print_all();
		// printf("\n");
		row++; // 到下一行
	}
	// 从下到上重新更新
	for(int r = n - 1; r >= 0; r--)
	{
		for(int r_former = n - 1; r_former > r; r_former--)
		{
			a[r][n] -= a[r_former][n] * a[r][r_former];
		}
		if(fabs(a[r][r]) < eps && fabs(a[r][n]) > eps) return -1;
	}
	return rank;
}

int main()
{
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++) { std::cin >> a[i][j]; }
	}
	int res = gauss();
	// printf("res is %d\n", res);
	if(res < 0)
		printf("No solution\n");
	else if(res < n)
		printf("Infinite group solutions\n");
	else
	{
		for(int i = 0; i < n; i++) { printf("%.2f\n", a[i][n]); }
		// printf("\n");
	}
	return 0;
}

/*
思路：简单，就是纯的高斯消元法，通过基本行列式变换到leading 1的上三角形式，然后再从下到上解答案即可，注意这里面判断为 0 只需要小于 1e-6 即可
*/