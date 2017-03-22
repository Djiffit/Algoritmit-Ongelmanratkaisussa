#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

long n, s, e;
vector<vector<long>> parents;
vector<vector<long>> children;

void addParents(int node) {
    int i;
    for (i = 1; parents[parents[node][i-1]].size() > i - 1 ; ++i) {
        parents[node].push_back(parents[parents[node][i-1]][i-1]);
    }
    for (auto c : children[node]) {
        addParents(c);
    }
}


void getParents() {
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        cin >> s >> e;
        int numberUp = (int) (log2(e) / log2(2));
        e -= pow(2, numberUp);
        while (e > 0) {
            if (parents[s].size() <= numberUp) break;
            s = parents[s][numberUp];
            numberUp = (int) (log2(e) / log2(2));
            e -= pow(2, numberUp);
        }
        if (parents[s].size() > numberUp) {
            cout << parents[s][numberUp] << '\n';
        } else {
            cout << "QAQ\n";
        }
    }
}

void makeTree() {
    parents = vector<vector<long>>(n+1, vector<long>());
    children = vector<vector<long>>(n+1, vector<long>());
    for (int i = 2; i <= n; ++i) {
        cin >> s;
        parents[i].push_back(s);
        children[s].push_back(i);
    }
    for (auto c: children[1]) {
        addParents(c);
    }
}



int main() {
    cin >> n;
    makeTree();
    getParents();
}

