#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

long n, a, l, rew;

int main() {
    cin >> n;
    set<long> packed;
    unordered_map<long, long> inds;
    unordered_map<long, long> indsR;
    multiset<pair<long, pair<long, long>>> events;
    for (int i = 0; i < n; ++i) {
        cin >> a >> l >> rew;
        packed.insert(a);
        packed.insert(l);
        events.insert({l, {a, rew}});
    }
    long i = 0;
    for (auto j = packed.begin(); j != packed.end(); ++j) {
        long s = j.operator*();
        inds.insert({i, s});
        indsR.insert({s, i});
        i++;
    }
    i = 0;
    vector<long> dp(packed.size(), 0);
    for (int m = 0; m < inds.size(); ++m) {
        while (true) {
            auto curr = events.lower_bound({inds[m], {0, 0}});
            if (curr != events.end() && curr.operator*().first == inds[m]) {
                auto current = curr.operator*();
                if (dp[indsR[current.second.first]] > 0) {
                    dp[m] = max(max(dp[indsR[current.second.first] - 1] + current.second.second, dp[m - 1]), dp[m]);
                } else {
                    dp[m] = max(current.second.second, dp[m]);
                }
            } else {
                if (m != 0) dp[m] = max(dp[m - 1], dp[m]);
                break;
            }
            events.erase(events.find(curr.operator*()));
        }

    }
    cout << dp[dp.size() - 1];
    exit(0);
}