/*
小 A 和小 B 在下五子棋。

五子棋是在一个由网格构成的棋盘内进行的。

网格有 15 行 15 列，共有 225 个交叉点。

小 A 先手执黑棋，小 B 后手执白棋。

两人轮流下棋，每次下棋都将一个自己的棋子放在棋盘上一个空白的交叉点上。

然而，由于小 A 和小 B 都不知道五子棋的胜利条件，所以即使有一方已经胜利了，他们仍然会继续下棋。

现在想请你帮忙分析一下，所下的棋局是在第几步结束的。

当然，也有可能他们最终仍然没有分出胜负，这时请判定他们平局。

五子棋的胜利条件是这样的：当同一行或同一列或同一斜线（即与网格线成 45° 角的直线）上连续的五个或五个以上交叉点放有同色棋子的时候，立即判定使用该颜色棋子的玩家获得胜利，游戏结束。

输入格式
第一行输入一个正整数 n，表示双方总共下了多少步棋。

接下来 n 行，每行两个正整数。其中，第 i 行的两个数 x,y 表示第 i 步的棋子下在了第 x 条横线和第 y 条竖线的交叉点上。若 i 为奇数，则这个棋子是黑棋，否则是白棋。

输出格式
若没有人获得胜利，你需要输出“Tie”（不含引号）。

否则，若小 A 获胜，输出 “A”（不含引号），若小 B 获胜，输出 “B”（不含引号）；并输出一个正整数 w 表示第 w 步下完后游戏应当结束，字母与整数间用一个空格隔开。

数据范围
对于 20% 的数据，游戏结果是平局。
对于 30% 的数据，游戏在最后一手结束。
对于 100% 的数据，0≤n≤225，1≤x,y≤15。

输入样例：
9
1 1
2 1
1 2
2 2
1 3
2 3
1 4
2 4
1 5
输出样例：
A 9

10
1 1
2 1
1 2
2 2
1 3
2 3
1 4
2 4
1 6
2 5
*/
// #include <cstdio>
#include <iostream>
using namespace std;
const int N = 17;
int chess[N][N];

// inline void print_chess()
// {
// 	printf("\n");
// 	for(int i = 0; i < N; i++)
// 	{
// 		for(int j = 0; j < N; j++) { printf("%d ", chess[i][j]); }
// 		printf("\n");
// 	}
// 	printf("\n");
// }

bool judge_win(int x, int y)
{
	int count = 1, num = chess[x][y];
	int x_check = x, y_check = y;
	// print_chess();
	// printf("x:%d,y:%d\n", x, y);
	// 竖着看
	while(chess[x_check - 1][y_check] == num) { x_check--, count++; }
	// printf("count1:%d\n", count);
	x_check = x, y_check = y;
	while(chess[x_check + 1][y_check] == num) { x_check++, count++; }
	// printf("count2:%d\n", count);
	if(count >= 5) return true;
	count = 1, x_check = x, y_check = y;
	// 横着看
	while(chess[x_check][y_check - 1] == num) { y_check--, count++; }
	x_check = x, y_check = y;
	// printf("count3:%d\n", count);
	while(chess[x_check][y_check + 1] == num) { y_check++, count++; }
	// printf("count4:%d\n", count);
	if(count >= 5) return true;
	count = 1, x_check = x, y_check = y;
	// 斜着看
	while(chess[x_check - 1][y_check - 1] == num) { y_check--, x_check--, count++; }
	// printf("count5:%d\n", count);
	x_check = x, y_check = y;
	while(chess[x_check + 1][y_check + 1] == num) { y_check++, x_check++, count++; }
	// printf("count6:%d\n", count);
	if(count >= 5) return true;
	count = 1, x_check = x, y_check = y;
	// 斜着看
	while(chess[x_check - 1][y_check + 1] == num) { y_check++, x_check--, count++; }
	// printf("count5:%d\n", count);
	x_check = x, y_check = y;
	while(chess[x_check + 1][y_check - 1] == num) { y_check--, x_check++, count++; }
	// printf("count6:%d\n", count);
	if(count >= 5) return true;
	return false;
}

int main()
{
	// 奇数 1，黑子，偶数 2，白子
	int point = 1;
	int n;
	cin >> n;
	bool finded_win = false;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(!finded_win)
		{
			chess[x][y] = point;
			if(judge_win(x, y))
			{
				finded_win = true;
				if(point == 1) { cout << "A " << i << "\n"; }
				else { cout << "B " << i << "\n"; }
			}
			point = point == 1 ? 2 : 1;
		}
	}
	if(!finded_win) { cout << "Tie\n"; }
	return 0;
}