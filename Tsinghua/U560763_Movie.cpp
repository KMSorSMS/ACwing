/*
Ecrade_ 正在观看一个影片。
给定影片的时长，并假设该影片以恒定的 x 帧每秒的帧率播放，问该影片一共显示了几帧？
从标准输入读入数据。
第一行一个整数 T，表示测试数据组数。
对于每组测试数据，一行一个形如 AB:CD:EF 的字符串和一个整数 x，表示该影片时长为 AB 时 CD 分 EF 秒，帧率为 x 帧每秒。
输出到标准输出。
对于每组测试数据，输出一行一个整数表示答案。
2
00:00:01 1
06:06:06 120
===========
1
2635920
*/

#include <cstdio>
int main()
{
	unsigned long hour, min, sec, n, x;
	scanf("%lu", &n);
	while(n--)
	{
		scanf("%lu:%lu:%lu", &hour, &min, &sec);
		scanf("%lu", &x);
		printf("%lu\n", (hour * 3600 + min * 60 + sec) * x);
	}
    return 0;
}