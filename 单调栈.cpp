#include<iostream>

using namespace std;

const int N = 100010;
int n;
int stk[N], tt;
int main() {
	cin >> n;
	//值得注意，两重循环，但是每个数只进出栈一次，所以是O(n)
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (tt && stk[tt] >= x)tt--;//从栈顶开始判断，如果大于0且tt不为零，则从栈中弹出，x本身也被弹出
		if (tt)cout << stk[tt] << ' ';//只要不是第一个数，就弹出stk[tt]
		else cout << -1 << ' ';//如果是第一个数，那就是-1

		stk[++tt] = x;//再将该值压入栈中，作为下一个数的候选值
	}
	return 0;
}