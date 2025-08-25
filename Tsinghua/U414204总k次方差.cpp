/*
3 1
1 7 2
为了避免输出规模过大，我们要求你输出这个答案除以 998244353 的余数。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll MOD = 998244353;
int a[N],n,k;

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int res = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         ll tmp = a[j] - a[i];
    //         printf("tmp:%lld,a[i]:%lld,a[j]:%lld\n",tmp,a[i],a[j]);
    //         res += (tmp % MOD) * 2;
    //         res %= MOD;
    //         printf("res:%lld\n",res);
    //     }
    // }
    
    for(int i=2;i<=n;i++){
        res += ((ll)a[i]*(i-1)) % MOD;
        res %= MOD;
    }
    for(int i=1;i<=n-1;i++){
        res -= (ll)a[i] * (n-i) % MOD;
        res %= MOD;
    }
    res = ((res % MOD) * 2) % MOD;
    if(res < 0) res += MOD;
    cout << res << "\n";
    return 0;
}