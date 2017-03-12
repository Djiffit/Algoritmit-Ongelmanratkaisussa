#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long n, m, f, s, small(INT64_MAX), v;
vector<pair<long long, long long>> stops[101010];
vector<pair<long long, long long>> stopsReverse[101010];

vector<long long> dijkstraSearch(long long start, long long end, vector<pair<long long, long long>> ss[]) {
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
    cin >> n >> m;
    for (long long i = 0; i < m; ++i) {
        cin >> f >> s >> v;
        stops[f].push_back({s, v});
        stopsReverse[s].push_back({f, v});
    }
    auto first = dijkstraSearch(1, n, stops);
    auto second = dijkstraSearch(n, 1, stopsReverse );

    for (long long j = 1; j <= n; ++j) {
        for (auto trip : stops[j]) {
            long long a  = first[j];
            long long b = floor(trip.second/2);
            long long c = second[trip.first];
            small = min(small , a+b+c);
        }
    }

    cout << small;
}