/*
3 7
1 1 3 2
1 2 2 3
1 2 4 1
3 2 3
2 3 2
3 3 1
2 1 4
*/

#include <iostream>
using namespace std;
const int M=2e5+10,N=2e5+10;
struct OPS{
    int op;
    int x,w,c;
    bool if_rev;
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
                if(stack_now.op_last->if_rev) {stack_now.op_last->op_pre = &ops[i]; ops[i].op_next = stack_now.op_last;}
                else {stack_now.op_last->op_next = &ops[i]; ops[i].op_pre = stack_now.op_last;}
                stack_now.op_last = &ops[i];
            }
            cout << stack_now.sum << "\n";
        }
        if(op==2){
            cin >> x >> c;
            ops[i] = {op,x,w,c};
            stack_s& stack_now = sta[x];
            OPS* op = stack_now.op_last;
            int sum=0;
            while(c>0){
                if(op->op==1){
                    if(op->c > c){
                        op->c -= c;
                        c=0;
                        sum += c*op->w;
                    }else{
                        c -= op->c;
                        sum += op->c*op->w;
                        if(op->if_rev){
                            stack_now.op_last = op->op_next;
                        }else{
                            stack_now.op_last = op->op_pre;
                        }
                        stack_now.op_last->if_rev = op->if_rev;
                        op = stack_now.op_last;
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
                sta[y].op_last->if_rev = !sta[y].op_last->if_rev;
                if(sta[y].op_last->if_rev) sta[y].op_last->op_next = sta[x].op_last;
                else sta[y].op_last->op_pre = sta[x].op_last;
                sta[y].op_last = sta[x].op_begin;
                sta[y].sum += sta[x].sum;
            }else{
                sta[y] = sta[x];
            }
            sta[x].op_begin->if_rev = !sta[x].op_begin->if_rev;

            cout << sta[y].sum << "\n";
        }
    }
    return 0;
}