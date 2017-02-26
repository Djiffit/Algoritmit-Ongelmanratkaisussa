#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    cin.sync_with_stdio(false);
    long temp, n; cin >> n;
    vector<long> queue;
    for (int i = 0; i < n; ++i) {
        int q; cin >> q;
        if (q == 1) {
            cin >> temp;
            queue.push_back(temp);
        } else if (q == 2) {
            cin >> temp;
            cout << queue[temp - 1] << '\n';
        } else if (q == 3) {
            queue.erase(queue.begin());
        } else if (q == 4) {
            long l;
            cin >> l;
            queue.erase(queue.begin() + l-1);
        }
    }
}