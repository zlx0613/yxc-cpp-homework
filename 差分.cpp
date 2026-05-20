#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];
void insert(int l, int r, int c) {//同一个函数两个作用 1）a数组一正一负构造b数组差分2）lr范围内前缀和加c
	b[l] += c;
	b[r + 1] -= c;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)insert(i, i, a[i]);//1）
	while(m--) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);//2）
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)b[i] += b[i - 1];
	for (int i = 1; i <= n; i++)printf("%d ", b[i]);
	return 0;
}