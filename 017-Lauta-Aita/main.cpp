#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    long n,temp, maxs = 0;
    cin >> n;
    vector<pair<long, long>> nrs;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nrs.push_back({temp, i});
    }
    stack<pair<long, long>> blocks;
    for (auto fen : nrs) {
        if (blocks.size() == 0 || fen.first >= blocks.top().first) {
            blocks.push(fen);
        } else {
            auto prev = fen;
            while (blocks.size() > 0 && fen.first < blocks.top().first) {
                auto nb = blocks.top();
                blocks.pop();
                if (blocks.size() > 0) {
                    if ( prev.first > nb.first) {
                        maxs = max(maxs, nb.first * (prev.second - blocks.top().second));
                    } else {
                        maxs = max(maxs, nb.first * (nb.second - blocks.top().second));
                    }
                } else {
                    maxs = max(maxs, nb.first * 1);
                }
                if (nb.first > prev.first) {
                    prev = nb;
                }
            }
            blocks.push(fen);
        }
    }
    while (blocks.size() > 0) {
        auto nb = blocks.top();
        blocks.pop();
        if (blocks.size() > 0) {
            maxs = max(maxs, nb.first * (n -1 - blocks.top().second));
        } else {
            maxs = max(maxs, nb.first * (n));
        }
    }
    cout << maxs;
}