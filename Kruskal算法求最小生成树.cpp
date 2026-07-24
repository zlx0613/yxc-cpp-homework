#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000010;

int n, m;
int p[N];//并查集数组 用于储存节点的父节点
struct Edge {
    int a, b, w;
    bool operator<(const Edge& W)const {//重载小于运算符 定义按w来排序
        return w < W.w;
    }
}edges[N];

int find(int x) {
    if (p[x] != x)p[x] = find(p[x]);
    return p[x];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a,b,w };
    }
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)p[i] = i;

    int res = 0, cnt = 0;// res: MST总权值, cnt: 已选边的数量
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)puts("impossible");
    else printf("%d\n", res);
    return 0;
}