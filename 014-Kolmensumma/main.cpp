#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    bool found = false;
    long long n,x, temp, min = INFINITY;
    cin >> n >> x;
    vector<long long> nrs;
    for (long long i = 0; i < n; ++i) {
        cin >> temp;
        if (temp < min) {
            min = temp;
        }
        nrs.push_back(temp);
    }
    if (min < 0) {
        x += 3 * (abs(min));
        for (long long k = 0; k < n; ++k) {
            nrs[k] += abs(min);
        }
    } else {
        min = 0;
    }
    sort(nrs.begin(), nrs.end());
    for (long long j = 0; j < n; ++j) {
        long long l = j + 1, r = n-1;
        while (r != l) {
            auto sum = nrs[j] + nrs[l] + nrs[r];
            if (sum == x) {
                cout << nrs[j] + min  << ' ' << nrs[l] + min << ' ' << nrs[r]+min;
                found = true;
                break;
            }
            if (sum > x) {
                r--;
            } else {
                l++;
            }
        }
        if (found) break;
    }
    return 0;
}