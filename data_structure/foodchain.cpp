/*
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。

A 吃 B，B 吃 C，C 吃 A。
现有 N 个动物，以 1∼N 编号。
每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这 N 个动物所构成的食物链关系进行描述：
第一种说法是 1 X Y，表示 X 和 Y 是同类。
第二种说法是 2 X Y，表示 X 吃 Y。

此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。
当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
当前的话与前面的某些真的话冲突，就是假话；
当前的话中 X 或 Y 比 N 大，就是假话；
当前的话表示 X 吃 X ，就是假话。
你的任务是根据给定的 N 和 K句话，输出假话的总数。
输入格式
第一行是两个整数 N 和 K ，以一个空格分隔。

以下 K 行每行是三个正整数 D，X，Y ，两数之间用一个空格隔开，其中 D表示说法的种类。
若 D=1，则表示 X和 Y是同类。
若 D=2 ，则表示 X 吃 Y。
输出格式
只有一个整数，表示假话的数目。

数据范围
1≤N≤50000, 0≤K≤100000

输入样例：
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
输出样例：
3
*/
#include <iostream>
#include <sys/types.h>
#define N 50010
uint Nums[N], Prio[N], count;

inline uint find(uint x)
{
	if(x != Nums[x]) Nums[x] = find(Nums[x]);
	return Nums[x];
}

uint eat(uint x, uint y) { 
    x = find(x);
    y = find(y);
    if(x==y) return 1;
    if(find(Prio[y]) == x) return 1;
    

}

uint merge(uint x, uint y)
{
	x = find(x);
	y = find(y);
	if(x == y) return 0;
	uint x_eat = find(Prio[x]), y_eat = find(Prio[y]);
	// 无法合并
	if(x_eat == y || y_eat == x) return 1;
	uint result = merge(x_eat, y_eat);
	if(result == 0) { Nums[y] = x; }
	return result;
	// if(x_eat==0 && y_eat== 0){
	//     Nums[y] = x;
	// }else if(x_eat == 0){
	//     Nums[y] = x;
	//     Prio[x] = y_eat;
	// }else if(y_eat == 0){
	//     Nums[y] = x;
	//     Prio[x] = x_eat;
	// }else{

	// }
	// 先检验这样会不会x吃x
	// if(Prio[x] == y || Prio[y] == x) { count++; }
	// else
	// {
	// 	// 查找被吃的所属
	// 	x_eat = find(Prio[x]);
	// 	y_eat = find(Prio[y]);
	// 	// 不会自己吃自己，那么被吃的应该是在同一个类别，或者两者没有吃与被吃的关系，则能说明两者同一个类别
	// 	if(Prio[x_eat] != y_eat && Prio[y_eat] != x_eat) {

	//     }
	// 	Nums[y] = x;
	// }
}

int main()
{
	int n, k;
	uint op, x, y;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) { Nums[i] = i; }
	while(k--)
	{
		std::cin >> op >> x >> y;
		if(x > n || y > n) count++;
		continue;
		switch(op)
		{
		case 1:
			count += merge(x, y);
			break;
		case 2:
		}
	}
}