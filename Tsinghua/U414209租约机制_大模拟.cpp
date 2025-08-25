/*
3 22 10 3
R 0 2
R 0 3
R 1 2
R 1 3
R 10 2
R 10 3
R 11 2
W 12 2
R 20 3
R 21 3
R 24 2
R 24 3
R 25 2
R 25 3
W 40 2
R 43 2
R 43 3
W 43 2
R 46 2
R 46 3
R 56 2
R 56 3


RWB
RWB
B
B
B
B
RWB
RWB
B
RB
RB
RWB
RWB
RB
RB
RWB
RWB
B
B
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10, M = 1e6+10;
struct Center{
    int exp_t;
    int write_t;
    // bool has_write;
};
struct Query{
    char op;
    int t,x;
};
int cli[N];
Query qw[M],qr[M];
Center center;
int n,m,k,d,idxw_qh,idxw_qb,idxr_qh,idxr_qb;

bool write_q(int i,int t,int t_q){
    if(t > center.exp_t && t >= center.write_t){
        int t_begin = max(center.exp_t+1,max(t_q,center.write_t));
        center.write_t = t_begin + d;
        idxw_qh++;
        return true;
    }
    return false;
}

void read_q(int i,int t){
    idxr_qh++;
    if(cli[i] >= t){
        cout << "B\n";
        return;
    }
    if(t >= center.write_t && idxw_qh == idxw_qb){
        cout << "RWB\n";
        center.exp_t = max(center.exp_t,t+k);
        cli[i] = center.exp_t;
        return;
    }else{
        if(t <= center.exp_t){
            cout << "RWB\n";
            cli[i] = center.exp_t;
        }else
            cout << "RB\n";
    }


}

int main(){
    cin >> n >> m >> k >> d;
    for(int i=1;i<=n;i++){
        cli[i] = -1;
    }
    int last_t = 0;
    for(int turn=1;turn<=m;turn++){
        char op;
        int t,x;
        cin >> op >> t >> x;
        if(t != last_t){
            // 先处理写请求
            // printf("tackle:%d,idxw_qh:%d,sidxw_qb:%d,idxr_qh:%d,idxr_qb:%d,center.exp_t:%d,center.write_t:%d\n",last_t,idxw_qh,idxw_qb,idxr_qh,idxr_qb,center.exp_t,center.write_t);
            for(int i=idxw_qh;i<idxw_qb;i++){
                if(!write_q(qw[i].x,last_t,qw[i].t)) break;
            }
            // 再处理读请求
            for(int i=idxr_qh;i<idxr_qb;i++){
                read_q(qr[i].x,qr[i].t);
            }
        }
        if(op == 'R') qr[idxr_qb++] = {op,t,x};
        else if(op == 'W') qw[idxw_qb++] = {op,t,x};
        last_t = t;
    }
    // 处理最后的
    // 先处理写请求
    // printf("tackle:%d,idxw_qh:%d,idxw_qb:%d,idxr_qh:%d,idxr_qb:%d,center.exp_t:%d,center.write_t:%d\n",last_t,idxw_qh,idxw_qb,idxr_qh,idxr_qb,center.exp_t,center.write_t);
    for(int i=idxw_qh;i<idxw_qb;i++){
        if(!write_q(qw[i].x,last_t,qw[i].t)) break;
    }
    // 再处理读请求
    for(int i=idxr_qh;i<idxr_qb;i++){
        read_q(qr[i].x,qr[i].t);
    }
    return 0;
}
