/*
求给定区间 [X,Y] 中满足下列条件的整数个数：这个数恰好等于 K 个互不相等的 B 的整数次幂之和。

例如，设 X=15,Y=20,K=2,B=2，则有且仅有下列三个数满足题意：
17=2^4+2^0
18=2^4+2^1
20=2^4+2^2

输入格式
第一行包含两个整数 X 和 Y，接下来两行包含整数 K 和 B。

输出格式
只包含一个整数，表示满足条件的数的个数。

数据范围
1≤X≤Y≤2^31−1,
1≤K≤20,
2≤B≤10
输入样例：
15 20
2
2
输出样例：
3
*/

// #include <cstdio>
#include <iostream>
#include <vector>
#define N 35
int c[N][N];

inline void init()
{
	for(int i = 0; i < N; i++) { c[i][0] = 1; }
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j <= i; j++) { c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; }
	}
}

inline int DP(int n, int B, int K)
{
	std::vector<int> n_reverse;
	if(n == 0) { return 0; }
	while(n != 0)
	{
		n_reverse.push_back(n % B);
		n /= B;
	}
	int result = 0, last = 0, i = n_reverse.size() - 1;
	for(; i >= 0; i--)
	{
		int x = n_reverse[i]; // 取出当前位的数
		if(x > 0)
		{ // 当前位比 0 大，我们会讨论左右分支的情况
			if(x > 1)
			{ //比 1 大，说明左侧分支分成有 1 和无 1，那么数量就是 c_i^(K-last) + C_i^(K-last-1)
				// printf("x > 1; c[%d][%d]=%d\n", i + 1, K - last, c[i + 1][K - last]);
				result += c[i + 1][K - last];
				break;
			}
			else
			{ //这里就是 x==1的情况，那么数量就是C_i^(K-last)
				// printf("x == 1; c[%d][%d]=%d\n", i, K - last, c[i][K - last]);
				result += c[i][K - last];
				last++;
				if(last > K) break;
			}
		}
	}
	if(last == K && i < 0) result++;

	// for(; i >= 0; i--)
	// {

	// 	int x = n_reverse[i]; //取当前位上的数

	// 	if(x > 0)
	// 	{ //只有x>0的时候才可以讨论左右分支

	// 		//当前位填0，从剩下的所有位（共有i位）中选K-last个数。
	// 		//对应于：左分支中0的情况，合法
	// 		result +=
	// 			c[i][K - last]; //i个数中选K-last个数的组合数是多少，选出来这些位填1，其他位填0

	// 		if(x > 1)
	// 		{
	// 			//当前位填1，从剩下的所有位（共有i位）中选K-last-1个数。
	// 			//对应于：左分支中填1的情况，合法
	// 			if(K - last - 1 >= 0)
	// 				result += c[i][K - last - 1]; //i个数中选K-last-1个数填1的组合数是多少
	// 			//对应于：左分支中其他情况（填大于1的数）和此时右分支的情况（右侧此时也>1），不合法！！！
	// 			//直接break。
	// 			break;
	// 		}

	// 		//上面统计完了**左分支**的所有情况，和右分支大于1的情况，

	// 		//这个else 是x==1，
	// 		//对应于：右分支为1的情况，即限定值为1的情况，也就是左分支只能取0
	// 		//此时的处理是，直接放到下一位来处理
	// 		//只不过下一位可使用的1的个数会少1，体现在代码上是last+1

	// 		else
	// 		{
	// 			last++;
	// 			//如果已经填的个数last > 需要填的个数K，不合法break
	// 			if(last > K) break;
	// 		}
	// 	}
	// 	//上面处理完了这棵树的**所有**左分支，就剩下最后一种右分支的情况
	// 	// 也就是遍历到最后1位，在vector中就是下标为0的地方：i==0；
	// 	// 并且最后1位取0，才算作一种情况res++。因为最后1位不为0的话，已经被上面的ifelse处理了。
	// 	if(i == 0 && last == K) result++;
	// }
	return result;
}

int main()
{
	init();
	int X, Y, K, B;
	std::cin >> X >> Y >> K >> B;
	// 预处理，把 X 和 Y 按照 B 进制进行分解
	std::cout << DP(Y, B, K) - DP(X - 1, B, K) << "\n";
	return 0;
}

/*
定义 c[i][j]是从 i 个候选里面选择 j 个的组合个数,因为 X 即便是 2 进制表示也不超过 35 位数，所以大小可以小于 35
求组合数的公式：
c[i][j] = c[i-1][j] + c[i-1][j-1];
*/