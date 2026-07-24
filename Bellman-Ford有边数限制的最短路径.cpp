#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, M = 10010;
const int INF = 0x3f3f3f3f;//定义无穷大
int n, m, k;// 图的参数：n=节点总数，m=边总数，k=最短路径最多允许的边数
int dist[N], backup[N];//dist[i] 表示“当前迭代下”从 1 到 i 的最短距离
//backup[i] 是上一轮迭代的 dist 备份
struct Edge {//结构体：储存一条有向边的起点终点和权重
    int a, b, w;
}edges[M];//数组：储存所有m条边

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);//备份 防止松弛时用的是更新后的
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > INF / 2) return INF;
    return dist[n];
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a,b,w };
    }
    int t = bellman_ford();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}