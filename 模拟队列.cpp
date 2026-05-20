//push x – 向队尾插入一个数 x
//pop – 从队头弹出一个数；
//empty – 判断队列是否为空；
//query – 查询队头元素。
#include<iostream>
using namespace std;
const int N = 100010;
int m, hh, tt = -1;//hh默认为0
int q[N];
int main() {
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        }
        else if (op == "pop") {
            hh++;
        }
        else if (op == "empty") {
            cout << (hh <= tt ? "NO" : "YES") << endl;
        }
        else {
            cout << q[hh] << endl;
        }
    }
    return 0;
}