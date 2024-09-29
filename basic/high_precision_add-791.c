#include <stdio.h>

#define N 200000

char long_int_a[N];
char long_int_b[N];
char long_int_r[N + 2];

int main()
{
	// long_int_r[0] = 'h';
	// long_int_r[1] = 'e';
	// long_int_r[2] = 'l';
	// long_int_r[3] = 'l';
	// long_int_r[4] = 'o';
	// long_int_r[5] = '\n';
	// printf("%s",long_int_r);

	scanf("%s", long_int_a);
	scanf("%s", long_int_b);
	int len_a = 0, len_b = 0;
	while(long_int_a[len_a] != '\0') len_a++;
	while(long_int_b[len_b] != '\0') len_b++;
	// printf("get a= %s,b= %s len_a is %d len_b is %d\n", long_int_a, long_int_b,len_a,len_b);
	int index = 0, carry = 0;
	while(long_int_a[len_a - index - 1] != '\0' && long_int_b[len_b - index - 1] != '\0')
	{
		int tmp =
			(long_int_a[len_a - index - 1] - '0') + (long_int_b[len_b - index - 1] - '0') + carry;
		long_int_r[N - index] = tmp % 10 + '0';
		carry = tmp / 10;
		index++;
	}
	// printf("%s\n", &long_int_r[N - index + 1]);
	while(len_a > len_b && long_int_a[len_a - index - 1] != '\0')
	{
		int tmp = (long_int_a[len_a - index - 1] - '0') + carry;
		long_int_r[N - index] = tmp % 10 + '0';
		carry = tmp / 10;
		index++;
	}
	while(len_a < len_b && long_int_b[len_b - index - 1] != '\0')
	{
		int tmp = (long_int_b[len_b - index - 1] - '0') + carry;
		long_int_r[N - index] = tmp % 10 + '0';
		carry = tmp / 10;
		index++;
	}
	if(carry != 0)
	{
		long_int_r[N - index] = '1';
		index++;
	}
	long_int_r[N - index] = '\0';
	// printf("carry is %d index is %d\n", carry, index);
	printf("%s\n", &long_int_r[N - index + 1]);
}