#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    long sum = 0;
    int n;
    long temp;
    cin >> n;
    vector<long> values;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        values.push_back(temp);
    }
    sort(values.begin(), values.end());
    for (auto value : values) {
        if (value <= sum+1) {
            sum += value;
        } else {
            break;
        }
    }
    cout << sum+1;
    return 0;
}