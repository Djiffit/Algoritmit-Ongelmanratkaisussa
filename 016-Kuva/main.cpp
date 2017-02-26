#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, temp;
    cin >> n;
    vector<vector<int>> nrs(n, vector<int>(n));
    vector<vector<int>> nrsmax;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            nrs[i][j] = temp;
        }
    }
    nrsmax = nrs;
    cout << 0 << '\n';
    for (int k = 1; k < n; ++k) {
        vector<vector<int>> ns(n-k, vector<int>(n-k));
        vector<vector<int>> nsmax(n-k, vector<int>(n-k));
        long sum = 0;
        for (int i = 0; i < nrs.size()-1; ++i) {
            for (int j = 0; j < nrs.size()-1; ++j) {
                ns[i][j] = min(min(nrs[i][j], nrs[i+1][j]), min(nrs[i+1][j+1], nrs[i][j+1]));
                nsmax[i][j] = max(max(nrsmax[i][j], nrsmax[i+1][j]),max(nrsmax[i][j+1], nrsmax[i+1][j+1]));
                sum+= nsmax[i][j] - ns[i][j];
            }
        }
        cout << sum << '\n';
        nrs = ns;
        nrsmax = nsmax;
    }

    return 0;
}