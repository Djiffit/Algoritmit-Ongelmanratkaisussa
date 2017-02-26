#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long n, temp, q, l;
    cin >> n;
    vector<long> mult(1000010, 0);
    vector<long> nrs(1000010, 0);
    vector<long> less(1000010, 0);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nrs[temp]++;
    }
    for (int j = 1; j < nrs.size(); ++j) {
        less[j] = nrs[j]+ less[j-1];
    }
    cin >> q;
    int j = 0;
    for (int i = 1; i <= 1000000; ++i) {
        for (j = 1; j <= (1000000/i); ++j) {
            if (nrs[i] > 0 && nrs[j] > 0) {
                if (i == j) {
                    if ((nrs[i] -1 ) * (nrs[j]) > 0) {
                        mult[i * j] += (nrs[i] - 1) * (nrs[j]);
                    }
                } else {
                    // cout << mult[i*j] << ' ' << i << ' ' << j << '\n';
                    mult.at(i*j) += (nrs[i]) * (nrs[j]);
                }
            }
        }
        if (nrs[i] > 0 || nrs[j] > 0) {
            if (j <= i) {
                if (nrs[i] > 0) {
                    auto sum = (nrs[i]) * (n - less[j - 1]-1);
                    mult[1000001] += sum;
                }
            } else {
                // cout << mult[i*j] << ' ' << i << ' ' << j << '\n';
                mult.at(1000001) += (nrs[i]) * (n - less[j-1]);
            }
        }
    }
    for (int m = mult.size(); m >= 0; --m) {
        mult[m-1] += mult[m];
    }
    for (int k = 0; k < q; ++k) {
        cin >> l;
        cout << mult[l] << '\n';
    }
    exit(0);
    return 0;
}