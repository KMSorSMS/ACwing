#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//int r=0;
vector<int> div(vector<int>& A, int B, int& r)
{ //r传入r的地址，便于直接对余数r进行修改
	vector<int> C;
	for(int i = 0; i < A.size(); i++)
	{ //对A从最高位开始处理
		r = r * 10 + A[i]; //将上次的余数*10在加上当前位的数字，便是该位需要除的被除数
		C.push_back(r / B); //所得即为商在这一位的数字
		r = r % B;
	}
	//由于在除法运算中，高位到低位运算，因此C的前导零都在vector的前面而不是尾部，vector只有删除最后一个数字pop_back是常数复杂度，而对于删除第一位没有相应的库函数可以使用，而且删除第一位，其余位也要前移，
	//因此我们将C翻转，这样0就位于数组尾部，可以使用pop函数删除前导0
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main()
{
	string a;
	int B, r = 0; //代表余数
	cin >> a >> B;
	vector<int> A;
	for(int i = 0; i < a.size(); i++)
		A.push_back(
			a[i] - '0'); //注意这次的A是由高为传输至低位，由于在除法的手算过程中，发现从高位进行处理
	//for(int i=0;i<A.size();i++) cout<<A[i];
	//cout<<B;
	auto C = div(A, B, r);
	for(int i = C.size() - 1; i >= 0; i--) cout << C[i]; //将C从最高位传给最低位
	cout << endl << r; //输出余数
	cout << endl;
	return 0;
}