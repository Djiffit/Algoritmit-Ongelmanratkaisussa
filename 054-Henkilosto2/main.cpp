#include <iostream>
#include <vector>

using namespace std;

long n, a;
vector<vector<long>> tree;
vector<long> superior;
vector<long> wages;
vector<long> z;
vector<long> yes;
vector<long> no;

void handleNode(int s) {
    if (z[s]) return;
    z[s] = 1;
    for (auto u: tree[s]) {
        handleNode(u);
    }
    long noChildren = 0;
    long yesChildren = 0;
    for (auto c: tree[s]) {
        if (c == superior[s]) continue;
        noChildren += no[c];
        yesChildren += max(no[c], yes[c]);
    }
    yes[s] = noChildren + wages[s];
    no[s] = yesChildren;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    tree = vector<vector<long>>(n+5, vector<long>()) ;
    z = vector<long>(n+5, 0);
    yes = vector<long>(n+5, 0);
    no = vector<long>(n+5, 0);
    superior = vector<long>(n+5, 0);
    wages = vector<long>(n+5, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a;
        wages[i] = a;
    }
    for (int i = 2; i <= n; ++i) {
        cin >> a;
        superior[i] = a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    handleNode(1);
    cout << max(yes[1], no[1]);
}