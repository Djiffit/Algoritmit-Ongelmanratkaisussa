#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n, q, temp, total(0);

void add(vector<long long> &playlist, long long x, long long k) {
    playlist[x] += k;
    for (x /= 2; x >= 1; x/=2) {
        playlist[x] = playlist[x*2] + playlist[x*2 +1];
    }
}

long long sum(vector<long long> &playlist, long long a, long long b) {
    long long s = 0;
    while (a <= b) {
        if (a%2 == 1) s += playlist[a++];
        if (b%2 == 0) s += playlist[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    long long next = pow(2, ceil(log(n)/log(2)));
    vector<long long> playlist(next*2, 0);
    for (int j = 0; j < n; ++j) {
        cin >> temp;
        playlist[next+j] = temp;
    }
    for (int j = next - 1; j >= 1; --j) {
        playlist[j] = playlist[2 * j] + playlist[2 * j + 1];
    }
    cin >> q;
    long a, b, t;
    for (int i = 0; i < q; ++i) {
        cin >> t;
        bool angry = true;
        if (t == 1) {
            cin >> a;
            cin >> t;
            a += next - 1;
            auto alku = a;
            b = playlist.size() - 1;
            while (a <= b) {
                long k = (a+b)/2;
                auto summ = sum(playlist, alku, k);
                if (summ == t) {
                    angry = false;
                    break;
                }
                if (summ > t) b = k-1;
                else a = k+1;
            }
            if (angry) total++;
        } else {
            cin >> a >> b;
            a+= next - 1;
            add(playlist, a, b - playlist[a]);
        }
    }
    cout << total;
}