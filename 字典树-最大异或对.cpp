#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010,M=31*N;
int n;
int a[N], son[M][2], idx;

void insert(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		int& s = son[p][x >> i & 1];//需要修改son数组里的值，&s可以直接操作数组元素
		if (!s)s = ++idx;
		p = s;
	}
}
int search(int x) {
	int p = 0, res = 0;
	for (int i = 30; i >= 0; i--) {
		int s = x >> i & 1;//只需要读取数组的值，无需修改
		if (son[p][!s]) {
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}
	int res = 0;
	for (int i = 0; i < n; i++)res = max(res,search(a[i]));
	printf("%d\n", res);
	return 0;
}