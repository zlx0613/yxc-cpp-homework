#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];//每个顶点到已选集合的最小距离
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;//记录当前找到的、距离已选集合最近的顶点的编号
        if (i && dist[t] == INF)return INF;
        if (i)res += dist[t];

        for (int j = 1; j <= n; j++)dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);//无向图+重边取最小权值
    }
    int t = prim();
    if (t == INF)puts("impossible");//不连通
    else printf("%d\n", t);
    return 0;
}