#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int n, k, s, e;
    int t = 0;
    cin >> n >> k;
    multiset<pair<int, int>> programs;
    multiset<pair<int, int>> recordings;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        programs.insert({e, s});
    }

    for (auto j = programs.begin(); j != programs.end(); ++j) {
        bool ins = false;
        auto p = j.operator*();
        if (recordings.size() > 0) {
            auto it = recordings.upper_bound({p.second, p.first});
            it--;
            if (it != recordings.end() && it.operator*().first <= p.second) {
                recordings.erase(recordings.find(it.operator*()));
                recordings.insert(p);
                t++;
                ins = true;
            }
        }
        if (!ins && recordings.size() < k) {
            recordings.insert(p);
            t++;
        }
    }
    cout << t;
    return 0;
}