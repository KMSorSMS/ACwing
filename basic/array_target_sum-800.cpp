// #include <cstdio>
// #include <iostream>
// #define N 100010

// int A[N], B[N];

// int main()
// {
// 	int n = 0, m = 0, x = 0;
// 	std::cin >> n >> m >> x;
// 	for(int i = 0; i < n; i++) { std::cin >> A[i]; }
// 	for(int j = 0; j < m; j++) { std::cin >> B[j]; }
// 	int a = 0, b = 0;
// 	while(a < n && A[a] < x)
// 	{
// 		while(b < m && A[a] + B[b] <= x)
// 		{
// 			if(A[a] + B[b] == x) { printf("%d %d\n", a, b); }
// 			b++;
// 		}
// 		a++;
// 		b = 0;
// 	}
// 	return 0;
// }

#include <cstdio>
#include <iostream>
#define N 100010

int A[N], B[N];

int main()
{
	int n = 0, m = 0, x = 0;
	std::cin >> n >> m >> x;
	for(int i = 0; i < n; i++) { std::cin >> A[i]; }
	for(int j = 0; j < m; j++) { std::cin >> B[j]; }
	int a = 0, b = m - 1;
	while(b >= 0 && a <= m - 1) { 
        if(A[a] + B[b] == x){
            printf("%d %d\n",a,b);
            break;
        }
        if(A[a] + B[b] > x){
            b--;
        }else{
            a++;
        }
    }
	return 0;
}