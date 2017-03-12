#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long n, m, f, s, big(0);
vector<int> stops[101010];
int visited[101010];

long breadthSearch(int j, long counter) {
    queue<int> q;
    q.push(j);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : stops[s]) {
            if (visited[u]) continue;
            visited[u] = 1; counter++;
            q.push(u);
        }
    }
    return counter;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        stops[f].push_back(s);
        stops[s].push_back(f);
    }
    for (int j = 0; j < n; ++j) {
        big = max(big, breadthSearch(j, 0));
    }
    cout << big;
}