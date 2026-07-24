#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int colour[N];// 染色数组：0表示未染色，1和2表示两种不同的颜色

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {
    colour[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!colour[j]) {
            if (!dfs(j, 3 - c))return false;
        }
        else if (colour[j] == c)return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);// 无向图，必须双向建边
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!colour[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    if (flag)puts("Yes");
    else puts("No");

    return 0;
}