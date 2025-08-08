/*
数独 是一种传统益智游戏，你需要把一个 9×9 的数独补充完整，使得数独中每行、每列、每个 3×3 的九宫格内数字 1∼9 均恰好出现一次。
请编写一个程序填写数独。

输入格式
输入包含多组测试用例。
每个测试用例占一行，包含 81 个字符，代表数独的 81 个格内数据（顺序总体由上到下，同行由左到右）。
每个字符都是一个数字（1−9）或一个 .（表示尚未填充）。
您可以假设输入中的每个谜题都只有一个解决方案。
文件结尾处为包含单词 end 的单行，表示输入结束。
输出格式
每个测试用例，输出一行数据，代表填充完全后的数独。
输入样例：
4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
输出样例：
417369825632158947958724316825437169791586432346912758289643571573291684164875293
416837529982465371735129468571298643293746185864351297647913852359682714128574936

输入样例：
.2738..1..1...6735.......293.5692.8...........6.1745.364.......9518...7..8..6534.
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
输出样例：
527389416819426735436751829375692184194538267268174593643217958951843672782965341
416837529982465371735129468571298643293746185864351297647913852359682714128574936

*/

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")


#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Position
{
	int x, y, cell;
};

const int N = 10;
int row_bits[N], col_bits[N], nine_bits[N], map[512];
char graph[100];
int count_ones[1024];

int lowbit(int x)
{
	return x & -x;
}

Position find_x_y(int i)
{
	return {i / 9 + 1, i % 9 + 1, ((i / 9) / 3) * 3 + ((i % 9) / 3) + 1};
}

int count_ones_func(int num)
{
	int res = 0;
	while(num != 0)
	{
		num -= lowbit(num);
		res++;
	}
	return res;
}

int get_state(int i)
{
	Position pos = find_x_y(i);
	// printf("i:%d,x:%d,y:%d,cell:%d\n", i, pos.x, pos.y, pos.cell);
	return row_bits[pos.x] & col_bits[pos.y] & nine_bits[pos.cell];
}

void update_graph(int i, int num, bool if_reset)
{
	int mask = ~(1 << (num - 1));
	Position pos = find_x_y(i);
	int x = pos.x, y = pos.y, cell = pos.cell;
	if(!if_reset)
	{
		row_bits[x] = row_bits[x] & mask;
		col_bits[y] = col_bits[y] & mask;
		nine_bits[cell] = nine_bits[cell] & mask;
	}
	else
	{
		row_bits[x] = row_bits[x] | ~mask;
		col_bits[y] = col_bits[y] | ~mask;
		nine_bits[cell] = nine_bits[cell] | ~mask;
	}
}

bool dfs(int depth)
{
	if(depth == 0) return true;
	// 剪枝，找可能性最少的
	int minv = 10, start = 0, state_save = 0;
	for(int i = 1; i <= 81; i++)
	{
		if(graph[i] == '.')
		{
			int state = get_state(i - 1);
			if(count_ones[state] <= minv)
			{
				// printf("count_ones:%d,minv:%d\n", count_ones[state], minv);
				minv = count_ones[state], start = i, state_save = state;
			}
		}
	}
	// Position pos = find_x_y(start - 1);
	// printf("x:%d,y:%d,z:%d,start:%d,minv:%d,state:%x,count_onse:%d\n",
	// 	   pos.x,
	// 	   pos.y,
	// 	   pos.cell,
	// 	   start,
	// 	   minv,
	// 	   state_save,
	// 	   count_ones[state_save]);
	while(state_save != 0)
	{
		int next = lowbit(state_save);
		state_save -= next;
		int num_add = map[next];
		graph[start] = num_add + '0';
		update_graph(start - 1, num_add, false);
		if(dfs(depth - 1)) { return true; }
		update_graph(start - 1, num_add, true);
		graph[start] = '.';
	}
	return false;
}

int main()
{

	for(int i = 0; i <= 511; i++) { count_ones[i] = count_ones_func(i); }
	for(int i = 1; i <= 9; i++) map[1 << (i-1)] = i;
	while(true)
	{
		for(int i = 1; i <= 9; i++) { row_bits[i] = 511, col_bits[i] = 511, nine_bits[i] = 511; }
		cin >> (graph + 1);
		if(graph[1] == 'e') break;
		int count = 0;
		for(int i = 1; i <= 81; i++)
		{
			if(graph[i] != '.')
			{
				// Position pos = find_x_y(i);
				// int row_idx = pos.x, col_idx = pos.y, cell_idx = pos.cell;
				// int mask = ~(1 << (s[i] - '1'));
				// printf("row_bits:%x,col_bits:%x,nine_bits:%x,s[i]-'1':%x\n",
				// 	   row_bits[row_idx],
				// 	   col_bits[col_idx],
				// 	   nine_bits[cell_idx],
				// 	   mask);
				// row_bits[row_idx] = row_bits[row_idx] & mask;
				// col_bits[col_idx] = col_bits[col_idx] & mask;
				// nine_bits[cell_idx] = nine_bits[cell_idx] & mask;
				// printf("row:%d,col:%d,cell:%d\n", row_idx, col_idx, cell_idx);
				// printf("row_bits:%x,col_bits:%x,nine_bits:%x\n",
				// 	   row_bits[row_idx],
				// 	   col_bits[col_idx],
				// 	   nine_bits[cell_idx]);
				update_graph(i - 1, graph[i] - '0', false);
			}
			else { count++; }
		}
		// printf("count is:%d\n", count);
		if(dfs(count))
		{
			// for(int i = 1; i <= 81; i++) { cout << graph[i]; }
			// cout << "\n";
			puts(graph + 1);
		}
		else
		{
			for(int i = 1; i <= 81; i++) { cout << graph[i]; }
			cout << "\n";
			cout << "impossible\n";
		}
	}
	return 0;
}

/*
剪枝的关键：
1. 优化搜索顺序：大部分情况下，我们应该优先搜索分支较少的节点
2. 可行性剪枝

特殊：位运算优化
*/