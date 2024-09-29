#include <stdio.h>

#define N 100000
#define M 100000 + 4

char long_int_a[N], long_int_b[N], long_int_r[M];

int main()
{
	scanf("%s", long_int_a);
	scanf("%s", long_int_b);
	int len_a = 0, len_b = 0;
	while(long_int_a[len_a] != '\0') len_a++;
	while(long_int_b[len_b] != '\0') len_b++;
	int a_index = len_a - 1, b_index = len_b - 1, index = M - 1, carry = 0;
	while(a_index >= 0 && b_index >= 0)
	{
		int tmp = long_int_a[a_index] - long_int_b[b_index] - carry;
		if(tmp < 0)
		{
			carry = 1;
			tmp = 10 + tmp;
		}
		else { carry = 0; }
		long_int_r[index] = tmp + '0';
		index--, a_index--, b_index--;
	}
	while(a_index >= 0)
	{
		// printf("in a :%c\n",long_int_a[a_index]);
		int tmp = long_int_a[a_index] - '0' - carry;
		if(tmp < 0)
		{
			carry = 1;
			tmp = 10 + tmp;
		}
		else { carry = 0; }
		long_int_r[index] = tmp + '0';
		index--, a_index--;
	}
	// printf("%s\n", &long_int_r[index + 1]);
	while(b_index >= 0)
	{
		int tmp = -(long_int_b[b_index] - '0') - carry;
		if(tmp < 0)
		{
			carry = 1;
			tmp = 10 + tmp;
		}
		else { carry = 0; }
		long_int_r[index] = tmp + '0';
		index--, b_index--;
	}
	// printf("%s\n", &long_int_r[index + 1]);
	if(carry == 1)
	{
		carry = 0;
		// long_int_r[index + 1] = '-';
		int i = M - 1;
		for(; i > index; i--)
		{
			// printf("%c\n", long_int_r[i]);
			int tmp = '0' - long_int_r[i] - carry;
			if(tmp < 0)
			{
				carry = 1;
				tmp = 10 + tmp;
			}
			long_int_r[i] = tmp + '0';
		}
		while(index + 1 != M - 1 && long_int_r[index + 1] == '0') index++,i++;
		long_int_r[i] = '-';
		index--;
	}
	while(index + 1 != M - 1 && long_int_r[index + 1] == '0') index++;
	printf("%s\n", &long_int_r[index + 1]);
}