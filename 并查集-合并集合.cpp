#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int p[N];
//递归寻找祖宗节点+路径压缩
int find(int x) {
	if (p[x] != x)p[x] = find(p[x]);//路径压缩：每一个节点直接连接祖宗节点
	return p[x];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)p[i] = i;
	while (m--) {
		char op[2];//有字符串结束标志
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		if (op[0] == 'M')p[find(a)] = find(b);//a的集合挂在b的下面，将ab集合并在一起
		//判断ab的祖宗节点是否一致
		else {
			if (find(a) == find(b))puts("Yes");
			else puts("No");
		}
	}
	return 0;
}