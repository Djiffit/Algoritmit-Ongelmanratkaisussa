#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int b;
int x, t;
int n;

int main() {
    multiset<pair<int,int>> blacks;
    multiset<int> records;

    cin >> n >> b;
    vector<short> fence(n, 0);
    for (int i = 0; i < b; ++i) {
        cin >> t >> x;
        if (t == 1) {
            fence[x-1] = 1;
            if ((x - 2 >= 0) && (x < n) && (fence[x-2] == 1) && (fence[x] == 1)) {
                auto it = blacks.lower_bound({x-1, x-1});
                it--;
                auto it2 = blacks.upper_bound({x, 0});
                blacks.erase(it);
                blacks.erase(it2);
                records.erase(records.find(it.operator*().second - it.operator*().first + 1));
                records.erase(records.find(it2.operator*().second - it2.operator*().first + 1));
                records.insert(it2.operator*().second - it.operator*().first + 1);
                blacks.insert({it.operator*().first, it2.operator*().second});
            } else if ((x - 2 >= 0 && fence[x-2] == 1)) {
                auto it = blacks.upper_bound({x-1, x-1});
                it--;
                blacks.erase(it);
                records.erase(records.find(it.operator*().second - it.operator*().first + 1));
                records.insert(it.operator*().second - it.operator*().first + 2);
                blacks.insert({it.operator*().first, it.operator*().second+1});
            } else if ((x < n) && fence[x] == 1) {
                auto it = blacks.upper_bound({x, 0});
                blacks.erase(it);
                records.erase(records.find(it.operator*().second - it.operator*().first + 1));
                records.insert(it.operator*().second - it.operator*().first + 2);
                blacks.insert({it.operator*().first - 1, it.operator*().second});
            } else {
                blacks.insert({x-1, x-1});
                records.insert(1);
            }
        } else {
            fence[x-1] = 0;
            if (x - 2 >= 0 && fence[x-2] == 1 && x < n && fence[x] == 1) {
                auto it = blacks.upper_bound({x-1, x-1});
                it--;
                int first = it.operator*().first, second = it.operator*().second;
                blacks.erase(it);
                records.erase(records.find(second - first + 1));
                records.insert(second - x + 1);
                records.insert(x-1 - first);
                blacks.insert({first, x-2});
                blacks.insert({x, second});
            } else if (x-2 >= 0 && fence[x-2] == 1) {
                auto it = blacks.upper_bound({x-1, x-1});
                it--;
                blacks.erase(it);
                records.erase(records.find(it.operator*().second - it.operator*().first + 1));
                records.insert(it.operator*().second - it.operator*().first);
                blacks.insert({it.operator*().first, it.operator*().second-1});
            } else if (x < n && fence[x] == 1) {
                auto it = blacks.upper_bound({x-1, 0});
                blacks.erase(it);
                records.erase(records.find(it.operator*().second - it.operator*().first + 1));
                records.insert(it.operator*().second - it.operator*().first);
                blacks.insert({it.operator*().first + 1, it.operator*().second});
            } else {
                auto it = blacks.find({x-1, x-1});
                blacks.erase(it);
                records.erase(records.find(1));
            }
        }
        if (records.size() != 0) {
            auto it = records.end();
            it--;
            cout << *it << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
