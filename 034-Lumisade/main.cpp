#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n, q, temp, first(0);

void add(vector<long long> &yards, long long x, long long k) {
    yards[x] += k;
    for (x /= 2; x >= 1; x/=2) {
        yards[x] = yards[x*2] + yards[x*2 +1];
    }
}

long long sum(vector<long long> &yards, long long a, long long b) {
    long long s = 0;
    while (a <= b) {
        if (a%2 == 1) s += yards[a++];
        if (b%2 == 0) s += yards[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    cin >> q;
    long long next = pow(2, ceil(log(n)/log(2)));
    vector<long long> yards(next*2, 0);
    for (int i = 0; i < q; ++i) {
        long long a, b, amt;
        cin >> temp;
        if (temp == 1) {
            cin >> a >> b >> amt;
            b+= next - 1;
            add(yards, b+1, -amt);
            if ( a != 1) {
                a += next - 1;
                add(yards, a, amt);
            } else {
                first+=amt;
            }
        } else {
            cin >> temp;
            cout << sum(yards, 1 + next - 1, temp + next - 1) + first << '\n';
        }
    }
}

