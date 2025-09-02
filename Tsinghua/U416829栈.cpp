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
    int sum;
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
            stack_now.sum += c*w;
            if(stack_now.op_begin==nullptr){
                stack_now.op_begin = &ops[i];
                stack_now.op_last = &ops[i];
            }else{
                if(stack_now.op_last->op_pre==nullptr) {stack_now.op_last->op_pre = &ops[i];}
                else {stack_now.op_last->op_next = &ops[i];}
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
            int sum=0;
            bool is_pre = true;
            while(c>0){
                if(op_->op==1){
                    // printf("c:%d,x:%d,op_c:%d,op_w:%d\n",c,x,op_->c,op_->w);
                    if(op_->c > c){
                        op_->c -= c;
                        sum += c*op_->w;
                        c=0;
                        // printf("inner c:%d,x:%d,op_c:%d,op_w:%d,sum:%d\n",c,x,op_->c,op_->w,sum);
                    }else{
                        c -= op_->c;
                        sum += op_->c*op_->w;
                        if(op_->op_next==nullptr){
                            is_pre = true;
                        }else if(op_->op_pre==nullptr){
                            is_pre = false;
                        }
                        if(!is_pre)
                        {
                            if(op_->op_next == op_->op_next->op_next) stack_now.op_last = op_->op_pre,is_pre = true;
                            else stack_now.op_last = op_->op_next;
                        }else{
                            if(op_->op_pre == op_->op_pre->op_pre) stack_now.op_last = op_->op_next,is_pre = false;
                            else stack_now.op_last = op_->op_pre;
                        }
                        op_ = stack_now.op_last;
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
            if(sta[y].op_begin != nullptr){
                if(sta[y].op_last->op_next==nullptr) sta[y].op_last->op_next = sta[x].op_last;
                else sta[y].op_last->op_pre = sta[x].op_last;
                if(sta[x].op_last->op_next==nullptr)  sta[x].op_last->op_next = sta[y].op_last;
                else sta[x].op_last->op_pre = sta[y].op_last;
                sta[y].op_last = sta[x].op_begin;
                sta[y].sum += sta[x].sum;
                // printf("x:%d y:%d,y_last_w:%d\n",x,y,sta[y].op_last->w);
            }else{
                sta[y].sum = sta[x].sum;
                sta[y].op_last = sta[x].op_begin;
                sta[y].op_begin = sta[x].op_last;
            }

            cout << sta[y].sum << "\n";
        }
    }
    return 0;
}