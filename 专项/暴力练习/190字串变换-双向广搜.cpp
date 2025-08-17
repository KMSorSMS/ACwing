/*
已知有两个字串 A, B 及一组字串变换的规则（至多 6 个规则）:
A1→B1
A2→B2
…
规则的含义为：在 A 中的子串 A1 可以变换为 B1、A2 可以变换为 B2…。
例如：A＝abcd B＝xyz
变换规则为：
abc → xu ud → y y → yz
则此时，A 可以经过一系列的变换变为 B，其变换的过程为：
abcd → xud → xy → xyz
共进行了三次变换，使得 A 变换为 B。
注意，一次变换只能变换一个子串，例如 A＝aa B＝bb
变换规则为：
a → b
此时，不能将两个 a 在一步中全部转换为 b，而应当分两步完成。
输入格式
输入格式如下：
A B
A1 B1
A2 B2
… …

第一行是两个给定的字符串 A 和 B。
接下来若干行，每行描述一组字串变换的规则。
所有字符串长度的上限为 20。

输出格式
若在 10 步（包含 10 步）以内能将 A 变换为 B ，则输出最少的变换步数；否则输出 NO ANSWER!。
输入样例：
abcd xyz
abc xu
ud y
y yz
输出样例：
3
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
string a[6],b[6];
string A,B;
int op_count;

int extend(queue<string> &q,unordered_map<string,int> &q_d,unordered_map<string,int> &q_down_d,string *a_c,string *b_c){
    // 按层来扩展，所以这里需要保证把同等 dep 的都扩展完
    int d = q_d[q.front()];
    while(q.size() && q_d[q.front()] == d){
        string item = q.front();
        q.pop();
        int dep = q_d[item];
        for(int i=0;i<item.size();i++){
            for(int j=0;j<op_count;j++){
                if(item.substr(i,a_c[j].size()) == a_c[j]){
                    string new_str = item.substr(0,i) + b_c[j] + item.substr(i+a_c[j].size());
                    // printf("new_str:%s\n",new_str.c_str());
                    if(q_d.count(new_str)==0){
                        q_d[new_str] = dep+1;
                        if(q_down_d.count(new_str) != 0){
                            return q_d[new_str] + q_down_d[new_str];
                        }
                        q.push(new_str);
                    }
                }
            }
        }
    }
    return 11;
}

int bfs(string& A,string& B){
    // 因为扩展都是带操作的，完全不变的情况得特殊处理一下
    if(A==B) return 0;
    queue<string> qa,qb;
    unordered_map<string,int> deptha;
    unordered_map<string,int> depthb;
    deptha[A] = 0,depthb[B] = 0;
    qa.push(A),qb.push(B);
    int step=0;
    while(qa.size() && qb.size()){
        // printf("qa_size:%lu,qb_size:%lu\n",qa.size(),qb.size());
        int t;
        if(qa.size() < qb.size()){
            // printf("extend a\n");
            t = extend(qa,deptha,depthb,a,b);
        }else{
            // printf("extend b\n");
            t = extend(qb,depthb,deptha,b,a);
        }
        if(t <= 10) return t;
        // 这个 step 一定要放到下面，一层层扩展，这里表示到头了
        if(++step == 10) return 11;
    }
    return 11;
}


int main(){
    cin >> A >> B;
    while(cin >> a[op_count] >> b[op_count]) op_count++;
    int step = bfs(A,B);
    if(step > 10) cout << "NO ANSWER!\n";
    else cout << step << "\n";
}
