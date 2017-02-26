#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> bits(n, 0);
    bits[0] = 2;
    bits[1] = 4;
    for (int i = 2; i < n; ++i) {
        bits[i] = (bits[i-1] + bits[i-2]) % (long long)(pow(10, 9)+7);
    }
    cout << bits[n-1];
    return 0;
}
