#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int n, m;
int g[N][N];//邻接矩阵
int dist[N];//距离数组
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) 
            ///条件1: !st[j] -> 这个点还没被确定过
            // 条件2: t==-1 -> 还没找到任何候选点（初始化）
            // 条件3: dist[t] > dist[j] -> 发现了一个更近的点
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            t=j;
        st[t] = true;//标记该点已确定
        for (int j = 1; j <=n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
 }
int main() {
    scanf("%d%d", &n, &m);
    //初始化邻接矩阵 把所有路都设置成不通
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d",& a, &b, &c);
        g[a][b] = min(g[a][b], c);//处理重边
    }
    int t = dijkstra();
    printf("%d ", t);
    return 0;
}