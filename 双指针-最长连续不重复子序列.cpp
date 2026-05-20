#include<iostream>
using namespace std;
int const N = 100010;
int a[N], q[N];
int n;
int res = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0, j = 0; i < n; i++) {
		q[a[i]]++;//起到计数器的作用
		while (q[a[i]] > 1) {
			q[a[j]]--;
			j++;
		}//出现重复就左端右移，直到重复数字消失
		res = max(res, i - j + 1);
	}
	cout << res << endl;
	return 0;
}