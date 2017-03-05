#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long n, k, temp, val, pos;
vector<long> lt, rt, at, st;

void replaceSum(long long x, long long k) {
    st[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        st[x] = st[x*2] + st[x * 2 + 1];
    }
}

void replaceLeft(long long x, long long k) {
    lt[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        lt[x] = max(lt[x*2], st[x*2] + lt[x * 2 + 1]);
    }
}

void replaceRight(long long x, long long k) {
    rt[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        rt[x] = max(rt[x*2] + st[x * 2 + 1], rt[x * 2 + 1]);
    }
}

void calculateAns(long long x, long long k) {
    at[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        at[x] = max(max(at[x*2], at[x*2+1]), rt[2*x] + lt[2*x +1]);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> k;
    long next = (long) pow(2, ceil(log(n) / log(2)));
    st = vector<long>(2 * next, -INT32_MAX);
    lt = vector<long>(2 * next, -INT32_MAX);
    at = vector<long>(2 * next, -INT32_MAX);
    rt = vector<long>(2 * next, -INT32_MAX);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        replaceSum(next+i, temp);
        replaceRight(next+i, temp);
        replaceLeft(next+i, temp);
    }
    for (int j = 0; j < n; ++j) {
        calculateAns(next + j, st[next+j]);
    }
    for (int l = 0; l < k; ++l) {
        cin >> pos >> val;
        replaceSum(next+pos-1, val);
        replaceRight(next+pos-1, val);
        replaceLeft(next+pos-1, val);
        calculateAns(next+pos-1, val);
        cout << at[1] << '\n';
    }
}