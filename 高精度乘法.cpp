#include<iostream>
#include<vector>

using namespace std;

vector<int>mul(vector<int>& A, int b) {//高精度乘低精度
	vector<int>C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {//将判断是否最高位进位放在循环里
		if (i < A.size())t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0)C.pop_back();//去掉前导零
	return C;
}
int main() {
	string a;
	int b;
	cin >> a >> b;
	vector<int>A;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');//反着输入(注意这里是a,不是A)
	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);//反着输出
	return 0;
}