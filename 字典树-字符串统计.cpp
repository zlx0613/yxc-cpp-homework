#include<iostream>
using namespace std;
const int N = 100010;
//son[p][u]表示节点p的第u个字母对应的子节点编号
//cnt[p]表示以节点p为结尾的字符串数量
//idx节点编号分配器
int son[N][26], cnt[N], idx;
//str[N]临时储存输入的字符串
char str[N];
//插入函数
void insert(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;//如果能够遍历完成，结尾节点计数加一，表示这个单词出现一次
}
//查询函数
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I')insert(str);
		else printf("%d\n", query(str));
	}
	return 0;
}