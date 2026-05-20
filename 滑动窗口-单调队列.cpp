#include<iostream>
using namespace std;
const int N = 1000010;
int n, k;
int a[N], q[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int hh = 0, tt = -1;//tt=-1表示队列为空
	for (int i = 0; i < n; i++) {
		if (hh <= tt && i-k+1  >q[hh])hh++;//判断是否滑出窗口，滑出则需要删除
		//维护队列的单调递增，队列尾数大于等于当前值则删去
		while (hh <= tt && a[q[tt]] >= a[i])tt--;
		q[++tt] = i;//当前元素下标i加入队列
		if (i >=k - 1)printf("%d ",a[q[hh]]);//窗口形成时再输出头值即最小值
	}
	puts("");//输出一个换行
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && i - k + 1>q[hh])hh++;
        //维护队列的单调递减，队列尾数小于等于当前数则删去
		while (hh <= tt && a[q[tt]] <= a[i])tt--;
		q[++tt] = i;
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	puts("");
	return 0;
}