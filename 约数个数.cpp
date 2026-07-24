#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	unordered_map<int, int>primes;//哈希表
//有一个特性，当你访问一个不存在的 Key 时，它会自动创建这个 Key，并将对应的 Value 初始化为 0。
	while (n--) {
		int x;
		cin >> x;
		for(int i=2;i<=x/i;i++)
			while (x%i==0){
				x /= i;
				primes[i]++;
			}
		if (x > 1)primes[x]++;
	}
	LL res = 1;
	for (auto prime : primes)res = res * (prime.second + 1) % mod;
	cout << res << endl;
	return 0;
}