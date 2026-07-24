#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];//邻接矩阵
void floyd() {///算法核心逻辑：经典三重循环
    for (int k = 1; k <= n; k++)//枚举中转点
        for (int i = 1; i <= n; i++)//枚举起点
            for (int j = 1; j <= n; j++)//枚举终点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//更新最短距离
}
int main() {
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)d[i][j] = 0;
            else d[i][j] = INF;
    while (m--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w);//处理重边
    }
    floyd();

    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (d[a][b] > INF / 2)puts("impossible");
        else printf("%d\n", d[a][b]);
    }
    return 0;
}