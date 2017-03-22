#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
long n, a, b;
map<vector<int>, int> hashes;
vector<vector<int>> mol1;
vector<vector<int>> mol2;
vector<int> names1;
vector<int> names2;

void hashIt(int node, vector<vector<int>> &mol, vector<int> &visited, vector<int> &names) {
    if (visited[node] == 1) return;
    visited[node] = 1;
    vector<int> children;
    for (auto c : mol[node]) {
        if (visited[c]) continue;
        hashIt(c, mol, visited, names);
        children.push_back(names[c]);
    }
    sort(children.begin(), children.end());
    if (hashes.find(children) == hashes.end()) {
        hashes.insert({children, hashes.size()+1});
        names[node] = hashes.size();
    } else {
        names[node] = hashes.find(children).operator*().second;
    }
}

int main() {
    cin >> n;
    mol1 = vector<vector<int>>(n+5, vector<int>());
    mol2 = vector<vector<int>>(n+5, vector<int>());
    names1 = vector<int>(n+5, 0);
    names2 = vector<int>(n+5, 0);
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        mol1[a].push_back(b);
        mol1[b].push_back(a);
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        mol2[a].push_back(b);
        mol2[b].push_back(a);
    }
    vector<int> v1(n+5, 0);
    vector<int> v2(n+5, 0);
    hashIt(1, mol1, v1, names1);
    hashIt(1, mol2, v2, names2);

    names1[1] == names2[1] ? cout << "YAY" : cout << "QAQ";
}