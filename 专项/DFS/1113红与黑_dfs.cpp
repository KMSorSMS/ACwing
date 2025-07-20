/*
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
你站在其中一块黑色的瓷砖上，只能向相邻（上下左右四个方向）的黑色瓷砖移动。
请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入格式
输入包括多个数据集合。
每个数据集合的第一行是两个整数 W 和 H，分别表示 x 方向和 y 方向瓷砖的数量。

在接下来的 H 行中，每行包括 W 个字符。每个字符表示一块瓷砖的颜色，规则如下
1）‘.’：黑色的瓷砖；
2）‘#’：红色的瓷砖；
3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
当在一行中读入的是两个零时，表示输入结束。
输出格式
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
数据范围
1≤W,H≤20
输入样例：
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
输出样例：
45
*/

// #include <cstdio>
#include <iostream>
const int W = 30, H = 30;
int w, h;

char map[W][H];
// bool st[W][H];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int start_x, int start_y)
{
	if(map[start_x][start_y] == '#') return 0;
	map[start_x][start_y] = '#';
	int count = 1;
	// printf("%d,%d\n", start_x, start_y);
	for(int i = 0; i < 4; i++)
	{
		int next_x = start_x + dir[i][0], next_y = start_y + dir[i][1];
		if(next_x >= 1 && next_x <= h && next_y >= 1 && next_y <= w && map[next_x][next_y] != '#')
			count += dfs(next_x, next_y);
	}
	return count;
}

int main()
{
	int start_x, start_y;
	while(1)
	{
		std::cin >> w >> h;
		if(w == 0 && h == 0) break;
		for(int i = 1; i <= h; i++)
		{
			for(int j = 1; j <= w; j++)
			{
				std::cin >> map[i][j];
				if(map[i][j] == '@') { start_x = i, start_y = j; }
			}
		}
		for(int i = 1; i <= h; i++) { map[i][w + 1] = 0; }
		for(int j = 1; j <= w; j++) { map[h + 1][j] = 0; }
		std::cout << dfs(start_x, start_y) << "\n";
	}
	return 0;
}
