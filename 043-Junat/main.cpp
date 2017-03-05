#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long> dp;
vector<long> eps;
vector<pair<long, long>> segment;
long n, temp;

pair<long, long> findMax(long start, long end) {
    pair<long, long> maxv = {-INFINITY, -INFINITY};
    while (start <= end && (start != 0 && end != 0)) {
        if (start % 2 == 1) {
            maxv.first < segment[start].first ? maxv = segment[start] : maxv = maxv;
            start++;
        }
        if (end %2 == 0) {
            maxv.first < segment[end].first ? maxv = segment[end] : maxv = maxv;
            end--;
        }
        start = start/2;
        end = end/2;
    }
    return maxv;
}

void replace(long long x, pair<long, long> k) {
    segment[x] = k;
    for (x /= 2; x >= 1; x/=2) {
        segment[x*2].first > segment[x * 2 + 1].first ? segment[x] = segment[x*2] : segment[x] = segment[x*2+1];
    }
}

int main() {
    cin >> n;
    eps.push_back(0);
    for (int i = 0; i < n-1; ++i) {
        cin >> temp;
        eps.push_back(temp);
    }
    dp = vector<long>(eps.size(), 0);
    dp[dp.size() - 1] = 1;
    long next = (long) pow(2, ceil(log(dp.size()) / log(2)));
    segment = vector<pair<long, long>>(2 * next + 1, {0,0});
    for (long k = 1; k < eps.size(); ++k) {
        replace(next+k, {eps[k], k});
    }
    for (long j = eps.size()-2; j > 0; --j) {
        auto i = findMax(next + j + 1, next + eps[j]);
        dp[j] = dp[i.second] + (n-i.second) + (i.second-j) - (eps[j] - i.second);
    }
    long sum = 0;
    for (int l = 0; l < dp.size(); ++l) {
        sum += dp[l];
    }
    cout << sum;
}