#include<iostream>
#include<cstring>
#include<algorithm>
//topsort解决有向无环图节点排序问题
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;//h[N]头指针数组
int q[N], d[N];//q[N]队列数组 存储入度为0的点
//d[N] 入度数组，记录i节点有多少边指向它

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//想象成排队时插到最前面
//e[idx]=b 新人过来登记名字b号
//ne[idx] = h[a] 新人问我后面是谁 我跟着原来的老大
//h[a] = idx++ 成功站到第一位 老大指向我，并迎接下一个新人
bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)q[++tt] = j;
        }
    }
    return tt == n - 1;//最终判决有没有环
}
int main() {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (topsort()) {
        for (int i = 0; i < n; i++)printf("%d ", q[i]);
    }
    else puts("-1");

    return 0;
}
