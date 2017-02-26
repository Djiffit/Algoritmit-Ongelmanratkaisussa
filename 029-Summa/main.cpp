#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<long> first, second;
vector<long> leftsums, rightsums;
vector<long> v;

void haku(int k, int n, bool left) {
    if (k == n) {
        if (left) {
            long sum = 0;
            for (auto num : v) {
                sum += first[num];
            }
            leftsums.push_back(sum);
        } else {
            long sum = 0;
            for (auto num : v) {
                sum += second[num];
            }
            rightsums.push_back(sum);
        }

    } else {
        haku(k+1, n, left);
        v.push_back(k);
        haku(k+1, n, left);
        v.pop_back();
    }
}
long counter = 0;
int main() {
    cin.sync_with_stdio(false);
    int n;
    long x, temp;
    cin >> n >> x;
    int i;
    for (i = 0; i < n/2; ++i) {
        cin >> temp;
        first.push_back(temp);
    }
    for (; i < n; ++i) {
        cin >> temp;
        second.push_back(temp);
    }
    haku(0, n/2, true);
    v = vector<long>();
    haku(0, n- n/2, false);
    sort(leftsums.begin(), leftsums.end());
    sort(rightsums.begin(), rightsums.end());

    for (auto s : leftsums) {
        long index = 0;
        long target = x- s;
        int a = 0, b = rightsums.size();
        while (a <= b) {
            int k = (a+b)/2;
            if (rightsums[k] == target) {
                counter++;
                index = k;
                break;
            }
            if (rightsums[k] > target) b = k-1;
            else a = k+1;
        }
        if (index != 0) {
            int i = 1, j = 1;
            while (index-i >= 0 && rightsums[index-i] == rightsums[index]) {
                counter++;
                i++;
            }
            while (index+j < rightsums.size() && rightsums[index+j] == rightsums[index]) {
                counter++;
                j++;
            }
        }
    }

    cout << counter;
}

