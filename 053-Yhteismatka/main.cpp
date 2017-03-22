#include <iostream>
#include <vector>

using namespace std;

long n, a, b;
vector<vector<long>> children;
vector<long> ss;
vector<long> dd;

void subTrees(long node, long parent, long dist) {
    ss[node] = 1;
    dd[1] += dist;
    for (auto c : children[node]) {
        if (c != parent) {
            subTrees(c, node, dist+1);
            ss[node] += ss[c];
        }
    }
}

void distances(long node, long parent) {
    dd[node] = dd[parent] - ss[node] + ss[1] - ss[node];
    for (auto c: children[node]) {
        if (c != parent) {
            distances(c, node);
        }
    }
}

int main() {
    cin >> n;
    ss = vector<long>(n+1);
    dd = vector<long>(n+1);
    children = vector<vector<long>>(n+1, vector<long>());
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    subTrees(1, 0, 0);
    for (auto c : children[1]) {
        distances(c, 1);
    }
    for (int j = 1; j <= n; ++j) {
        cout << dd[j] << '\n';
    }
}