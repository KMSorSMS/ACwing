/*
4
0 1 1 1
-1 0 1 1
-1 -1 0 1
-1 -1 -1 0

2
0  1
-1 0
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 9;
int prio[N][N];
int n;
bool st[N];
int que[N];
int count_res;

int if_win(int nth,int l,int r){
    if(nth==2){
        // printf("que[l]:%d,que[r]:%d\n",que[l],que[r]);
        if(prio[que[l]][que[r]] == 1){
            return que[l];
        }else{
            return que[r];
        }
    }
    else{
        int mid = (l+r) >> 1;
        int l_win = if_win(nth/2,l,mid),r_win = if_win(nth/2,mid+1,r);
        if(prio[l_win][r_win]==1){
            return l_win;
        }else{
            return r_win;
        }
    }
}

void dfs(int depth){
    // printf("depth:%d\n",depth);
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i] = true;
            que[depth] = i;
            dfs(depth+1);
            st[i] = false;
        }
    }
    if(depth>n) {
        // printf("judge depth:%d\n",depth);
        if(if_win(n,1,n) == 1){
            count_res++;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> prio[i][j];
        }
    }
    // printf("start dfs\n");
    dfs(1);
    int n_div=1;
    for(int i=1;i<=(n/2);i++){
        n_div *=2;
    }
    cout << count_res/n_div << "\n";
}
