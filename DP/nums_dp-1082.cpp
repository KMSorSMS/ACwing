/*
科协里最近很流行数字游戏。

某人命名了一种不降数，这种数字必须满足从左到右各位数字呈非下降关系，如 123，446。

现在大家决定玩一个游戏，指定一个整数闭区间 [a,b]，问这个区间内有多少个不降数。

注意：不降数不能包含前导零。

输入格式
输入包含多组测试数据。

每组数据占一行，包含两个整数 a 和 b。

输出格式
每行给出一组测试数据的答案，即 [a,b]之间有多少不降数。

数据范围
1≤a≤b≤2^31−1

输入样例：
1 9
1 19
输出样例：
9
18
*/

// #include <cstdio>
#include <iostream>
#include <vector>
#define N 12
int a, b;
int f[10][N];

inline int DP(int x)
{
	if(x == 0) return 0;
	std::vector<int> nums;
	int result = 0;
	// 拆分位数
	while(x != 0)
	{
		nums.push_back(x % 10);
		x /= 10;
	}
	// 进行分类遍历
	int former = 0, i = nums.size() - 1;
	// printf("nums_size:%d\n", i + 1);
	for(; i >= 0; i--)
	{
		int digit = nums[i];
		if(digit < former) break;
		// printf("digit is%d\n", digit);
		if(digit > 0)
		{ //需要分开左右分支
			int index = former;
			// if(index == 0 && i == 0) index = 1;
			for(; index <= digit - 1; index++)
			{
				result += f[index][i + 1];
				// printf("f[%d][%d]=%d\n", index, i + 1, f[index][i + 1]);
			}
		}
		former = digit;
	}
	if(i < 0) result++;
	return result;
}

inline void init()
{
	for(int i = 1; i <= 9; i++) { f[i][1] = 1; }

	for(int j = 2; j <= N - 1; j++)
	{
		for(int i = 0; i <= 9; i++)
		{
			for(int k = i; k <= 9; k++) { f[i][j] += f[k][j - 1]; }
			// printf("f[%d][%d]=%d\n", i, j, f[i][j]);
		}
	}

	// printf("f[0][3] = %d\n",f[0][3]);
}

int main()
{
	init();
	while(std::cin >> a >> b)
	{
		// 进行第一次 DP 的初始化
		std::cout << DP(b) - DP(a - 1) << "\n";
	}
	return 0;
}

/*
思路，同样，要求区间里面有多少的不降数，那我们就得类似前缀和一样处理，分别求 0~a-1 和 0～b 之间的不降数
在寻找过程中，我们需要找到以 i 开头的，长度为 j 的数字的不降数总量，这同样使用 DP 来寻找，我们预处理得到
要求f[i][j]，我们看最高位的下一位，只能是 i+1 ~ 9 长度变为 j-1
f[i][j] = sum(f[i+1][j-1] ... f[9][j-1])
*/