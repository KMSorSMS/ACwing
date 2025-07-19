/*
一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由 n∗n
的格点组成，每个格点只有2种状态，.和#，前者表示可以通行后者表示不能通行。
同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。
如果起点或者终点有一个不能通行(为#)，则看成无法办到。
注意：A、B不一定是两个不同的点。
输入格式
第1行是测试数据的组数 k，后面跟着 k 组输入。
每组测试数据的第1行是一个正整数 n，表示迷宫的规模是 n∗n 的。
接下来是一个 n∗n 的矩阵，矩阵中的元素为.或者#。
再接下来一行是 4 个整数 ha,la,hb,lb，描述 A 处在第 ha 行, 第 la 列，B 处在第 hb
行, 第 lb 列。

注意到 ha,la,hb,lb 全部是从 0 开始计数的。

输出格式
k行，每行输出对应一个输入。
能办到则输出“YES”，否则输出“NO”。
数据范围
1≤n≤100
输入样例：
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
输出样例:
YES
NO
*/
// #include <cstdio>
#include <cstring>
#include <iostream>
#define N 110
char map[N][N];
bool st[N][N];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(int start_x, int start_y, int end_x, int end_y)
{
	// printf("start_x:%d,start_y:%d\n", start_x, start_y);
	st[start_x][start_y] = true;
	if(start_x == end_x && start_y == end_y && map[start_x][start_y] == '.') { return true; }
	for(int i = 0; i < 4; i++)
	{
		int next_x = start_x + dir[i][0], next_y = start_y + dir[i][1];
		if(!st[next_x][next_y] && map[next_x][next_y] == '.' && dfs(next_x, next_y, end_x, end_y))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int k;
	std::cin >> k;
	while(k--)
	{
		int n;
		std::cin >> n;
		memset(map, 0, sizeof(map));
		memset(st, 0, sizeof(st));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++) { std::cin >> map[i][j]; }
		}
		// check map
		// std::cout << "\n==========\n";
		// for(int i = 1; i <= n; i++)
		// {
		// 	for(int j = 1; j <= n; j++) { std::cout << map[i][j]; }
		// 	std::cout << "\n";
		// }
		// std::cout << "\n==========\n";
		int start_x, start_y, end_x, end_y;
		std::cin >> start_x >> start_y >> end_x >> end_y;
		if(map[start_x + 1][start_y + 1] == '.' &&
		   dfs(start_x + 1, start_y + 1, end_x + 1, end_y + 1))
		{
			std::cout << "YES\n";
		}
		else { std::cout << "NO\n"; }
	}
	return 0;
}
