#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int STR_LEN = 10000;
vector<string> S;
char tmp_str[STR_LEN];
int n;

int main(){
	cin >> n;
	string op,s,s_end;
	for(int i=1;i<=n;i++){
		cin >> op >> s;
		if(op == "ADD"){
			int len;
			cin >> len;
			for(int i=0;i<=s.size()-len;i++){
				for(int j=0;j<len;j++){
					tmp_str[j] = s[i+j];
				}
				tmp_str[len] = 0;
				S.push_back(tmp_str);
			}
		}
		else{
			int res = 0;
			cin >> s_end;
			for(string str : S){
				if(str >= s && str <= s_end){
					res++;
				}
			}
			cout << res << "\n";
		}
	}
	// // debug
	// for(string str: S){
	// 	cout << str << "\n";
	// }
	return 0;
}
/*
4
ADD aacab 2
QUERY aa ab
ADD abc 1
QUERY a b

4
ADD aacab 2
QUERY aa ac
ADD abc 1
QUERY a b

*/