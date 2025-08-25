/*
1
5
*/
#include <iostream>
using namespace std;
const int N=1e4+10,T=1e4+10, MOD = 7654321;
int n;
// 表示当前是i 号科，总考数量为 j 的方法总数
int f[5][N];
int q[T];

void init(){
    for(int j=3;j<=n;j++){
        f[1][j] = f[3][j-1];
        f[2][j] = f[4][j-1];
        f[3][j] = (f[1][j-1]+f[4][j-1]) % MOD;
        f[4][j] = (f[2][j-1]+f[3][j-1]) % MOD;
    }
}

int main(){
    int t;
    cin >> t;
    f[1][1] = 1,f[2][1] = 1,f[3][1] = 1,f[4][1] = 1;
    f[1][2] = 1,f[2][2] = 1,f[3][2] = 2,f[4][2] = 2;
    for(int i=1;i<=t;i++){
        cin >> q[i];
        if(q[i] >= n){
            n = q[i];
        }
    }
    init();
    for(int i=1;i<=t;i++){
        cout << f[1][q[i]] << "\n";
    }

}