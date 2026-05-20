#include<iostream>
using namespace std;
const int N = 1000010;
int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r)return; //递归，把所有数组分成一个个单独的数字，形成天然有序
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//这里没有数字的交换，在合并时才进行数字大小的比较，并进入tmp

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)//三种情况分别进入不同的while循环
        if (q[i] <= q[j])tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while (i <= mid)tmp[k++] = q[i++];
    while (j <= r)tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];//i和j与上面的无关，是完全不同的用途
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)printf("%d ", q[i]);
    return 0;

}