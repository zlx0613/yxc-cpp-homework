#include<iostream>
using namespace std;
int num_prime(int x) {
    int count = 0;
    for (int i = 2; i <= x; i++) {
        bool prime = true;
        for (int j = 2; j <= i / j; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) count++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    cout << num_prime(n) << endl;
    return 0;
}