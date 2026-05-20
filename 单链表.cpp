#include<iostream>
using namespace std;

const int N = 100010;
//head表示头节点下标
//e[i]表示节点i的值
//ne[i]储存下标为i的节点的下一个节点的下标
//idx储存当前用到了哪个点
int head, e[N], ne[N], idx;
//初始化
void init() {
	head = -1;
	idx = 0;
}
//将x插入头节点
void add_to_head(int x) {
	e[idx] = x;//开辟空间
	ne[idx] = head;//原来的头节点为新的下一个节点
	head = idx;//当前位置是原来的头节点
	idx++;
}
//将x插入到k节点后面
void add(int k, int x) {
	e[idx] = x;//开辟空间
	ne[idx] = ne[k];//原来k的下一个节点为新的下一个节点
	ne[k] = idx;//当前位置是原来的k的下一个节点
	idx++;
}
//将下标是k的点后面的点删掉
void remove(int k) {
	ne[k] = ne[ne[k]];//将箭头指向下下个值
}
int main() {
	int m;
	cin >> m;
	init();
	while (m--) {
		int k, x;
		char op;
		cin >> op;
		if (op == 'H') {
			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D') {
			cin >> k;
			if (!k)head = ne[head];//删除头节点的做法
			remove(k - 1);
		}
		else {
			cin >> k >> x;
			add(k - 1, x);//k-1是因为数组储存从0开始
		}
	}
	//i=ne[i]是实现链表自动遍历的核心
	for (int i = head; i != -1; i = ne[i])cout << e[i] << ' ';
	cout << endl;
	return 0;
}