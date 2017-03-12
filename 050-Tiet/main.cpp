#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long n, m, f, s, small(INT64_MAX), v, x, y, z;
vector<pair<long long, long long>> paths[101010];

vector<long long> dijkstraSearch(long long start, vector<pair<long long, long long>> ss[]) {
    vector<long long> z(101010, 0);
    vector<long long> e(101010, 1e15);
    priority_queue<pair<long long, long long>> q;
    e[start] = 0;
    q.push({0,start});
    while (!q.empty()) {
        long long a = q.top().second; q.pop();
        if (z[a]) continue;
        z[a] = 1;
        for (auto b : ss[a]) {
            if (e[a]+b.second < e[b.first]) {
                e[b.first] = e[a]+b.second;
                q.push({-e[b.first],b.first});
            }
        }
    }
    return e;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m >> x >> y >> z;
    for (long long i = 0; i < m; ++i) {
        cin >> f >> s >> v;
        paths[f].push_back({s, v});
        paths[s].push_back({f, v});
    }
    auto first = dijkstraSearch(x, paths);
    auto second = dijkstraSearch(y, paths);
    auto third = dijkstraSearch(z, paths);

    for (long long j = 1; j <= n; ++j) {
        small = min(small , first[j]+second[j]+third[j]);
    }

    cout << small;
}