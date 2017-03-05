#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n, nn, nns, m, nxt(1), mod(pow(10,9) + 7);

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    vector<long long> s(n+1); vector<long long> ss(n+1);
    s[0] = 1; ss[0] = 1;
    for (long long i = 1; i <= m; ++i) {
        s[i] = nxt;
        nxt = nxt*2 % mod;
        ss[i] = nxt;
    }
    for (long long j = m+1; j <= n; ++j) {
        nn = (ss[j-1] - ss[j - 1 - m]) % mod;
        s[j] = nn;
        nns = (ss[j-1] % mod + nn % mod) % mod;
        ss[j] = nns;
    }
    s[n] >= 0 ? cout << s[n] : cout << s[n] + mod;
}