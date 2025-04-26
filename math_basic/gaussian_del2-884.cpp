/*
输入一个包含 n 个方程 n 个未知数的异或线性方程组。
方程组中的系数和常数为 0 或 1 ，每个未知数的取值也为 0 或 1。
求解这个方程组。
异或线性方程组示例如下：
M[1][1]x[1] ^ M[1][2]x[2] ^ … ^ M[1][n]x[n] = B[1]
M[2][1]x[1] ^ M[2][2]x[2] ^ … ^ M[2][n]x[n] = B[2]
…
M[n][1]x[1] ^ M[n][2]x[2] ^ … ^ M[n][n]x[n] = B[n]
其中 ^ 表示异或(XOR)，M[i][j] 表示第 i 个式子中 x[j] 的系数，B[i] 是第 i 个方程右端的常数，取值均为 0 或 1 。

输入格式
第一行包含整数 n 。

接下来 n 行，每行包含 n+1 个整数 0 或 1 ，表示一个方程的 n 个系数以及等号右侧的常数。
输出格式
如果给定线性方程组存在唯一解，则输出共 n 行，其中第 i 行输出第 i 个未知数的解。
如果给定线性方程组存在多组解，则输出 Multiple sets of solutions。
如果给定线性方程组无解，则输出 No solution。
数据范围
1≤n≤100
输入样例：
3
1 1 0 1
0 1 1 0
1 0 0 1
输出样例：
1
0
0
*/

#include <iostream>
#include <utility>
const int N = 110;
int a[N][N];
int n;
inline void print_all()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++) { std::cout << a[i][j] << " "; }
		std::cout << "\n";
	}
	std::cout << "\n";
}
inline int guassian_()
{
	int row = 0, col = 0, rank = 0;
	for(col = 0; col < n; col++, row++)
	{
		// 找非 0 的数字
		int one_row_index = row;
		for(int r = row; r < n; r++)
		{
			if(a[r][col] != 0)
			{
				one_row_index = r;
				break;
			}
		}
		// print_all();
		// 进行交换
		// printf("exange: one_row: %d, row: %d",one_row_index,row);
		for(int col_chage = col; col_chage <= n; col_chage++)
		{
			std::swap(a[one_row_index][col_chage], a[row][col_chage]);
		}
		// print_all();
		// 判断秩
		if(a[row][col] == 0) { continue; }
		rank++;
		// 更新其它
		for(int row_update = row + 1; row_update < n; row_update++)
		{
			if(a[row_update][col] == 0) continue;
			for(int col_update = col; col_update <= n; col_update++)
			{
				a[row_update][col_update] ^= a[row][col_update];
			}
		}
		// print_all();
	}
	// 此时已经是上三角矩阵
	// std::cout << "After upper\n";
	// print_all();
	for(row = n - 1; row >= 0; row--)
	{
		for(int row_former = row + 1; row_former < n; row_former++)
		{
			a[row][n] ^= (a[row][row_former] * a[row_former][n]);
			a[row][row_former] = 0;
		}
		// print_all();
		if(a[row][row] == 0 && a[row][n] == 1) return -1;
	}
	// print_all();
	return rank;
}

int main()
{
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++) { std::cin >> a[i][j]; }
	}
	// std::cout << "\n\n";
	int res = guassian_();
	if(res < 0)
		std::cout << "No solution\n";
	else if(res < n)
		std::cout << "Multiple sets of solutions\n";
	else
	{
		for(int i = 0; i < n; i++) { std::cout << a[i][n] << "\n"; }
	}
	return 0;
}