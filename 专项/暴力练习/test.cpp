#include <cstdio>
int main()
{
	int t, hour, min, sec, x;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		scanf("%d:%d:%d %d", &hour, &min, &sec, &x);
		int res = 60 * 60 * hour + 60 * min + sec;
		printf("%d\n", res * x);
	}
	return 0;
}