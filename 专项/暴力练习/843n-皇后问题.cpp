/*
n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，
即任意两个皇后都不能处于同一行、同一列或同一斜线上。
每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。
其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
*/

#include <cstring>
#include <iostream>
using namespace std;

const int N = 11;
bool col[N], udia[N * 2], ddia[N * 2];
char chess[N][N];
int n;

void init_chess()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) { chess[i][j] = '.'; }
	}
}

void print_chess()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) { cout << chess[i][j]; }
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int i)
{
	if(i > n) return;
	for(int j = 1; j <= n; j++)
	{
        // 剪枝(对于不满足要求的点，不再继续往下搜索)
		if(!col[j] && !udia[i + j] && !ddia[i + n - j])
		{
			col[j] = true, udia[i + j] = true, ddia[i + n - j] = true;
			chess[i][j] = 'Q';
			dfs(i + 1);
			if(i == n) { print_chess(); }
			chess[i][j] = '.';
			col[j] = false, udia[i + j] = false, ddia[i + n - j] = false;
		}
	}
}

int main()
{
	cin >> n;
	init_chess();
	dfs(1);
}
