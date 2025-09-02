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
const int M=2e5+10,N=2e5+10;
typedef long long ll;
struct OPS{
    int op;
    int x,w,c;
    // bool if_rev;
    OPS* op_pre;
    OPS* op_next;
};
OPS ops[M];
int idx_op;
struct stack_s{
    ll sum;
    OPS* op_begin;
    OPS* op_last;
};
stack_s sta[N];
int n,m;

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int op;
        int x=0,w=0,c=0;
        cin >> op;
        if(op==1){
            cin >> x >> w >> c;
            ops[i] = {op,x,w,c};
            stack_s& stack_now = sta[x];
            stack_now.sum += (ll)c*w;
            if(stack_now.op_begin==nullptr||stack_now.op_last==nullptr){
                stack_now.op_begin = &ops[i];
                stack_now.op_last = &ops[i];
            }else{
                {stack_now.op_last->op_next = &ops[i];}
                ops[i].op_pre = stack_now.op_last;
                stack_now.op_last = &ops[i];
            }
            cout << stack_now.sum << "\n";
        }
        if(op==2){
            cin >> x >> c;
            ops[i] = {op,x,w,c};
            stack_s& stack_now = sta[x];
            OPS* op_ = stack_now.op_last;
            ll sum=0;
            while(c>0){
                if(op_->op==1){
                    if(op_->c > c){
                        op_->c -= c;
                        sum += (ll)c*op_->w;
                        c=0;
                    }else{
                        c -= op_->c;
                        sum += (ll)op_->c*op_->w;
                        stack_now.op_last = op_->op_pre;
                        op_ = stack_now.op_last;
                        if(op_==nullptr) stack_now.op_begin = nullptr;
                    }
                }else{
                    cout << 1/0;
                }
            }
            sta[x].sum -= sum;
            cout << sum << "\n";
        }
        if(op==3){
            int y;
            cin >> x >> y;
            OPS* op_x;
            if(sta[y].op_begin != nullptr && sta[y].op_last != nullptr){
                op_x = sta[x].op_last;
            }else{
                op_x = sta[x].op_last;
                sta[y].op_last = sta[y].op_begin = op_x;
                if(op_x==nullptr) {cout << sta[y].sum << "\n";continue;}
                op_x = op_x->op_pre;
                sta[y].op_begin->op_pre = nullptr;
            }
            while(op_x!=nullptr){
                sta[y].op_last->op_next = op_x;
                OPS* op_x_pre = op_x->op_pre;
                op_x->op_pre = sta[y].op_last;
                sta[y].op_last = op_x;
                op_x = op_x_pre;
            }
            sta[y].sum += sta[x].sum;
            sta[x].op_begin=sta[x].op_last = nullptr,sta[x].sum=0;
            cout << sta[y].sum << "\n";
        }
    }
    return 0;
}