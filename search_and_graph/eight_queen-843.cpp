/*
n−
皇后问题是指将 n 个皇后放在 n×n
的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
现在给定整数 n，请你输出所有的满足条件的棋子摆法。
输入格式共一行，包含整数 n。

输出格式每个解决方案占 n行，每行输出一个长度为
n的字符串，用来表示完整的棋盘状态。 其中 . 表示某一个位置的方格状态为空，Q
表示某一个位置的方格上摆着皇后。 每个方案输出完成后，输出一个空行。
注意：行末不能有多余空格。
输出方案的顺序任意，只要不重复且没有遗漏即可。
数据范围
1≤n≤9
输入样例：
4
输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/

#include <iostream>
#define N 10
char chess[N][N];
int n;
bool col[N], dia[N], adia[N];
void dfs(int u)
{
	if(u >= n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++) std::cout << chess[i][j];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	for(int i = 0; i < n; i++)
	{ // range cols
		if(!col[i] && !dia[u + i] && !adia[n + i - u])
		{
			chess[u][i] = 'Q';
			col[i] = dia[u + i] = adia[n + i - u] = true;
			dfs(u + 1);
			col[i] = dia[u + i] = adia[n + i - u] = false;
			chess[u][i] = '.';
		}
	}
}

int main()
{
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) { chess[i][j] = '.'; }
	}
	dfs(0);
}