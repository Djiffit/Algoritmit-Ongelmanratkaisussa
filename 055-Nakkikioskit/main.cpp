#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long n, a, b, total;
int p[20][202020];
int depth[202020];
int nakkidepth[202020];
vector<vector<int>> paths;
int z[202020];
int nakki[202020];
int q;

void handleNode(int s, int d, int nakkid, int node) {
    if (z[s]) return;
    z[s] = 1;
    depth[s] = d;
    nakkidepth[s] = nakkid + nakki[s];
    p[0][s] = node;
    for (auto u: paths[s]) {
        handleNode(u, d+1, nakkid + nakki[s], s);
    }
}

void processTree() {
    queue<int> nodes;
    nodes.push(1);
    int v[202020];
    while (!nodes.empty()) {
        auto node = nodes.front(); nodes.pop();
        if (v[node] == 1) return;
        v[node] = 1;
        for (auto c : paths[node]) {
            if (v[node] == 0) nodes.push(c);
        }
    }
}

int getDepth(int x, int k) {
    for (int po = 20; po >= 0; po--) {
        while (k >= (1<<po)) {
            x = p[po][x];
            k -= (1<<po);
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    total = n;
    paths = vector<vector<int>>(202020, vector<int>());
    for (int j = 0; j < n-1; ++j) {
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    cin >> n;
    for (int k = 0; k < n; ++k) {
        cin >> a;
        nakki[a] = 1;
    }
    handleNode(1, 0, 0, 0);
    for (int b = 1; b < 20; b++) {
        for (int i = 1; i <= total; i++) {
            p[b][i] = p[b-1][p[b-1][i]];
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        long origa = a;
        long origb = b;
        if (a == b) return nakki[a];
        int k = abs(depth[a] - depth[b]);
        int x;
        if (depth[a] != depth[b]) {
            depth[a] > depth[b] ? x = a : x = b;
            for (int po = 20; po >= 0; po--) {
                while (k >= (1<<po)) {
                    x = p[po][x];
                    k -= (1<<po);
                }
            }
            if (x == b || x == a) {
                cout << nakkidepth[a] + nakkidepth[b] - 2 * nakkidepth[x] + nakki[x] << '\n';
                continue;
            }
            depth[a] > depth[b] ? a = x : b = x;
        }
        int start = 0, end = depth[a];
        while (start <= end) {
            int k = (start+end)/2;
            int node = getDepth(b, k);
            if (getDepth(a, k) == node) {
                if ((getDepth(a, k-1) != getDepth(b, k-1))) {
                    cout << nakkidepth[origa] + nakkidepth[origb] - 2 * nakkidepth[node] + nakki[node] << '\n';
                    break;
                } else {
                    end = k-1;
                }
            } else {
                start = k+1;
            }
        }
    }
}