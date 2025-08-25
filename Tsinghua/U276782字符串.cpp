/*
10 3
0111011110
*/

#include <iostream>
// #include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
char s[N];
int n,m;

int main(){

    cin >> n >> m;
    // printf("fin1\n");
    cin >> s;
    // printf("fin\n");
    ll res = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            // printf("in find\n");
            int j=i;
            for(;j<n;j++){
                if(s[j] != '1'){
                    break;
                }
            }
            if(j-i>=m){
                res += (ll)(j-m-i+2) * (ll)(j-m-i+1) / 2;
            }
            i = j;
        }
    }
    cout << res << "\n";
    return 0;

}