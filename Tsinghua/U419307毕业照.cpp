/*

毕业季快到了，小 A、小 B、小 C、小 D、小 E 五个人准备一起去拍毕业照。
他们准备排成一列拍照，但大家也有自己的一点小心思。比如小 A 想和小 B 站相邻位置拍照，小 C 不想和小 D 站相邻位置拍照。
给出同学之间谁和谁站相邻位置拍照，谁不和谁站相邻位置拍照的限制，问有多少种满足条件的拍照站位方案。

从标准输入读入数据。
输入的第一行包含一个整数 m ，表示有 m 条限制。

接下来的 m 行，每行格式为 id x y 。其中 id 为 1 表示 x 和 y 要站相邻位置拍照； id 为 2 ，表示 x 和 y 不能站相邻位置拍照。
x 和 y 为 A 到 E 之间的字符，分别表示小 A 到 小 E 。保证 x 和 y 不同。

示例
1
1 A B

答案
48


*/

#include <iostream>
#include <utility>
#include <vector>
std::vector<std::pair<int, std::pair<char, char>>> condition;
bool st[6];
char photo[7];
int result;

void dfs(int depth)
{
	for(int i = 1; i <= 5; i++)
	{
		if(!st[i])
		{
			st[i] = true;
			photo[depth] = 'A' + i - 1;
			dfs(depth - 1);
			st[i] = false;
		}
	}
	// 检查是否合格
	if(depth == 0)
	{
		for(auto cond : condition)
		{
			if(cond.first == 1)
			{
				for(int i = 1; i <= 5; i++)
				{
					if(photo[i] == cond.second.first)
					{
						if(photo[i + 1] != cond.second.second && photo[i - 1] != cond.second.second)
						{
							return;
						}
					}
				}
			}
			else
			{
				for(int i = 1; i <= 5; i++)
				{
					if(photo[i] == cond.second.first)
					{
						if(photo[i + 1] == cond.second.second || photo[i - 1] == cond.second.second)
						{
							return;
						}
					}
				}
			}
		}
		result++;
	}
}

int main()
{
	int m;
	std::cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int id;
		char x, y;
		std::cin >> id >> x >> y;
		condition.push_back({id, {x, y}});
	}
	dfs(5);
	std::cout << result << "\n";
}
