#include<iostream>
#include<algorithm>
//“边乘边取余”，并且最终结果和“先全部乘完再取余”完全一样，是因为数学上有一个极其重要的性质：
//乘法的同余性质（积的取模等于取模的积）
using namespace std;
typedef long long LL;
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {//把这个数通过指数拆开的方式 分成好几个部分取余数再将余数相乘取模
        if (k & 1)res = (LL)res * a % p;//计算余数取模
        k >>= 1;//指数转换成二进制计算
        a = (LL)a * a % p;//防止溢出
    }
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        printf("%d\n", qmi(a, k, p));
    }
    return 0;
}