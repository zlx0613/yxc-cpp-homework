#include<iostream>//特别之处在于浮点数二分是连续的实数，整数二分是离散的整数
using namespace std;
int main() {
    double x;
    cin >> x;
    double l = 0, r = x;
    while (r - l > 1e-6) {//在一定的精确度之下，近似算找到该值
        double mid = (l + r) / 2;//所以不存在边界问题，每次都能准确减去一半
        if (mid * mid >= x)r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
    return 0;
}