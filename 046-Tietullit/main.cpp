#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long n, m, f, s, big(0), v;
vector<pair<int, int>> stops[101010];
int e[101010];
int z[101010];

void dijkstraSearch(long start, long end) {
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) e[i] = 1e9;
    e[start] = 0;
    q.push({0,start});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (z[a]) continue;
        z[a] = 1;
        for (auto b : stops[a]) {
            if (e[a]+b.second < e[b.first]) {
                e[b.first] = e[a]+b.second;
                q.push({-e[b.first],b.first});
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> v;
        stops[f].push_back({s, v});
        stops[s].push_back({f, v});
    }
    dijkstraSearch(1, n);
    cout << e[n];
}