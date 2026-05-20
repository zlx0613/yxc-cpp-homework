#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int>PII;
void merge(vector<PII>& segs) {
	vector<PII> res;//储存合并的最后区间结果
	sort(segs.begin(), segs.end());//先把所有区间按左端点升序排序
	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
		if (ed < seg.first) {//两个数组完全不重合
			if (st != -2e9)res.push_back({ st,ed });//不重叠触发保存
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);//如果重合那就更新右端点，不保存
	if (st != -2e9)res.push_back({ st,ed });//for循环中只有遇到不重叠区域时才会保存，最后一个区间后面没有新区间，不会触发保存
	segs = res;//单独加一行，使最后一个区间保存
}
int main() {
	int n;
	scanf("%d", &n);
	vector<PII>segs;
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		segs.push_back({ l,r });
	}
	merge(segs);
	cout << segs.size() << endl;
	return 0;
}