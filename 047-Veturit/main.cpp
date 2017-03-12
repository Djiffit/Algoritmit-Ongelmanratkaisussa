#include <iostream>
#include <queue>
#include <set>

using namespace std;

set<int> visited;
vector<pair<int, long>> paths[101010];
priority_queue<pair<int, long>> pos;
long n, m, f, s, w, ans(INT32_MAX);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> w;
        paths[f].push_back({w, s});
        paths[s].push_back({w, f});
    }
    for (auto d : paths[1]) pos.push(d);
    visited.insert(1);
    while (visited.size() != n) {
        auto a = pos.top(); pos.pop();
        if (visited.find(a.second) == visited.end()) {
            visited.insert(a.second);
            for (auto d : paths[a.second]) pos.push(d);
            ans = min(ans, (long)a.first);
        }
    }
    cout << ans;
}