#include<iostream>

using namespace std; 

const int N = 1e6 + 10;
int q[N];
int n;

void quick_sort(int q[], int l, int r) {
    if (l >= r)return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;//基准值取中间减少时间
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);//基准值向零取整，x偏左，用左侧j,基准值向上取整（l+r+1)/2，用右侧i；保证区间变小
    quick_sort(q, j + 1, r);//i-1和i一组；j和j+1一组,如果写成i和i+1，会使(i+1,r)变成非法的eg(i+1>r)
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)printf("%d ", q[i]);//注意输出需要空格
    return 0;
}