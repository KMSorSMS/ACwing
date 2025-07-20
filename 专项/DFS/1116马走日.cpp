/*
马在中国象棋以日字形规则移动。
请编写一段程序，给定 n∗m 大小的棋盘，以及马的初始位置 (x，y)
，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

输入格式
第一行为整数 T，表示测试数据组数。

每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标 n,m,x,y。

输出格式
每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，若无法遍历棋盘上的所有点则输出 0。

数据范围
1≤T≤9,1≤m,n≤9,1≤n×m≤28,0≤x≤n−1,0≤y≤m−1
输入样例：
1
5 4 0 0
输出样例：
32
*/
// #include <cstdio>
#include <iostream>
const int N = 11, M = 11;
char chess[N][M];
int n, m;
int dir[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int count;
bool inline check_chess()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(chess[i][j] == 0) return false;
		}
	}
	return true;
}
void dfs(int start_x, int start_y)
{
	chess[start_x][start_y] = '#';
	bool have_next = false;
	// printf("%d,%d\n", start_x, start_y);
	for(int i = 0; i < 8; i++)
	{
		int next_x = start_x + dir[i][0], next_y = start_y + dir[i][1];
		if(next_x >= 1 && next_y >= 1 && next_x <= n && next_y <= m && chess[next_x][next_y] != '#')
		{
			dfs(next_x, next_y);
			have_next = true;
		}
	}
	if(!have_next && check_chess()) count++;
	chess[start_x][start_y] = 0;
}

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		std::cin >> n >> m;
		count = 0;
		// printf("\n");
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= m; j++) { chess[i][j] = 0; }
		}
		int start_x, start_y;
		std::cin >> start_x >> start_y;
		dfs(start_x + 1, start_y + 1);
		std::cout << count << "\n";
	}
	return 0;
}