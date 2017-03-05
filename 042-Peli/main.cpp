#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

long n, t1, t2, t3;
vector<long> a;
set<long> xcompress;
set<long> ycompress;
map<long, long> mx;
map<long, long> my;
vector<long> segment;

multiset<pair<long, pair<long, long>>> coins;

long findMax(long start, long end) {
    long maxv = -INFINITY;
    while (start <= end && (start != 0 && end != 0)) {
        if (start % 2 == 1) {
            maxv = max(maxv, segment[start]);
            start++;
        }
        if (end %2 == 0) {
            maxv = max(maxv, segment[end]);
            end--;
        }
        start = start/2;
        end = end/2;
    }
    return maxv;
}

void replace(long long x, long long k) {
    segment[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        segment[x] = max(segment[x*2], segment[x * 2 + 1]);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2 >> t3;
        xcompress.insert(t1);
        ycompress.insert(t2);
        coins.insert({t1, {t2, t3}});
    }
    int c = 0;
    for (const long & x : xcompress) {
        c++;
        mx[x] = c;
    }
    c = 0;
    for (const long & x : ycompress) {
        c++;
        my[x] = c;
    }
    long next = (long) pow(2, ceil(log(my.size()) / log(2)));
    segment = vector<long>(2 * next + 1, 0);
    for (auto &a : coins) {
        auto maxim = findMax(0+next, my[a.second.first] + next - 1);
        if (maxim + a.second.second > segment[next+my[a.second.first] - 1]) {
            replace(next + my[a.second.first] - 1, maxim + a.second.second);
        }
    }
    cout << segment[1];

}