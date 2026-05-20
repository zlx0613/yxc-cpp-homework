#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;

int n, m;
int h[N], sz;
//保持由小到大的堆
void down(int u) {
    int t = u;//t是最小节点，先假设u是当前子树中的最小节点
    if (u * 2 <= sz && h[u * 2] < h[t])t = u * 2;//左儿子u*2 右儿子u*2+1
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])t = u * 2 + 1;
    if (u != t) {//如果最小节点不是u
        swap(h[u], h[t]);//把u 和最小节点交换 然后做下沉操作 直到堆性质恢复
        down(t);
    }
}
//非叶子节点的索引范围是0~n/2(没有孩子的节点）  叶子节点（有孩子的节点）
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);//注意堆数组从1开始计数，便于计算孩子节点
    sz = n;
    for (int i = n / 2; i; i--)down(i);//非叶子节点个数为n/2，倒序对每一个节点做down操作，把数组调成跟堆
    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[sz];//把最后一个元素移动到根节点位置，相当于删除根节点也就是最小值
        sz--;
        down(1);//对新的根节点做下沉操作，下一次循环就能得到新的最小值
    }
    return 0;
}