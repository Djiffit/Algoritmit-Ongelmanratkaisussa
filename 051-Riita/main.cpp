#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> paths(20100, vector<int>());
int n, s, e, maxi(0), high(0);

int breadthSearch(int j) {
    queue<int> q;
    int last(j);
    q.push(j);
    vector<int> visited(20101, 0);
    vector<int> costs(20101, 0);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : paths[s]) {
            if (visited[u]) continue;
            last = u;
            visited[u] = 1;
            q.push(u);
            costs[u] = costs[s] + 1;
            maxi = max(maxi, costs[u]);
            if (q.empty()) return u;
        }
    }
    return last;
}


int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> s >> e;
        paths[s].push_back(e);
        paths[e].push_back(s);
        high = max(high, max(s, e));
    }
    auto farthest = breadthSearch(high/2);
    breadthSearch(farthest);
    cout << maxi;
}