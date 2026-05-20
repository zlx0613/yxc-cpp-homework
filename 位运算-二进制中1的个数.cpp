#include<iostream>
using namespace std;
int lowbit(int x) {
	return x & -x;//按位与取补码和原码相同的部位
}//提取二进制中最右侧的1以及后面的0
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		int res = 0;
		while (x)x -= lowbit(x), res++;
		cout << res << " ";
	}
	return 0;
}