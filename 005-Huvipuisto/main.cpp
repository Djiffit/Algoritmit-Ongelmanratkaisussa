#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(false);

    int max, n;
    cin >> n >> max;

    vector<int> kids;
    int temp, left(0), right(n-1), cages(0), current;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        kids.push_back(temp);
    }

    sort(kids.begin(), kids.end());

    while (left <= right) {
        if (left == right) {
            cages++;
            break;
        } else if (kids[left] + kids[right] <= max) {
            left++;
            right--;
            cages++;
        } else {
            right--;
            cages++;
        }
    }

    cout << cages;
}