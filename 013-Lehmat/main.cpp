#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
    cin.sync_with_stdio(false);
    long n, k, min = 1, x;
    cin >> n >> k;
    set<int> missing;
    for (int j = 1; j <= 100000; ++j) {
        missing.insert(j);
    }
    for (int i = 0; i < k; ++i) {
        cin >> x;
        if (x < 100000) {
            missing.erase(x);
        }
        cout << missing.begin().operator*() << ' ';
    }
}