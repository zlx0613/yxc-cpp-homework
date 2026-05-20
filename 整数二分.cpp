#include<iostream>
using namespace std;
int n, m;
const int N=100010;
int q[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);
	while (m--) {
		int x;
		scanf("%d", &x);
		int l = 0, r = n - 1;
		while (l < r) {//找第一次出现x的位置
			int mid = l + r >> 1;
			if (q[mid] >=x)r = mid;//if (q[mid] < x)l= mid+1;原来更好理解，重点在于mid取=时向左边界查找
			else l = mid +1;//else r = mid;如果把下面的用到这里，取=时会忽略左边的x值而向右边找
		}
		if (q[l] != x) cout << "-1 -1" << endl;
		else {
			cout << l << " ";//输出左边界
			int l = 0, r = n - 1;
			while (l < r) {//找最后一次出现x的位置
				int mid = l + r + 1 >> 1;
				if (q[mid] <= x)l = mid;//mid取=时，向右边界查找
				else r = mid - 1;
			}
			cout << l << endl;//输出右边界
		}
	}
	return 0;
}