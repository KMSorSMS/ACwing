/*
3 7
1 1 3 2
1 2 2 3
1 2 4 1
3 2 3
2 3 2
3 3 1
2 1 4

6
6
10
10
4
12
12
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int N=2010,M=2010;
typedef long long ll;
struct NUMS{
    int num,c;
};
NUMS stack_s[N][M];
int idx_s[M];
ll sum[M];
int n,m;
int main(){
    cin >> n >> m;
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int s_i,num,c;
            cin >> s_i >> num >> c;
            stack_s[s_i][++idx_s[s_i]] = {num,c};
            sum[s_i] += (ll)num*c;
            cout << sum[s_i] << "\n";
        }else if(op==2){
            int s_i,c;
            cin >> s_i >> c;
            ll add_sum=0;
            while(c>0){
                NUMS& num = stack_s[s_i][idx_s[s_i]];
                if(num.c > c){
                    num.c -= c;
                    add_sum += (ll)c*num.num;
                    c=0;
                }else{
                    c -= num.c;
                    add_sum += (ll)num.c*num.num;
                    idx_s[s_i]--;
                }
            }
            sum[s_i] -= add_sum;
            cout << add_sum << "\n";
        }else if(op==3){
            int x,y;
            cin >> x >> y;
            for(int i=idx_s[x];i>=1;i--){
                stack_s[y][++idx_s[y]] = stack_s[x][i];
            }
            sum[y] += sum[x];
            sum[x] = 0,idx_s[x]=0;
            cout << sum[y] << "\n";
        }
    }
    return 0;
}