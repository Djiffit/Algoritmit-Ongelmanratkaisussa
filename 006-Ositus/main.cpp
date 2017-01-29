#include <iostream>
#include <vector>

using namespace std;

bool testValue(long limit, int k, vector<long> &t) {
    long sum = 0;
    int ks = 1;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] > limit) {
            return false;
        }
        if (ks > k) {
            break;
        }

        if (sum + t[i] > limit) {
            ks++;
            sum = t[i];
        } else {
            sum += t[i];
        }
    }
    return ks <= k;
}

int main() {
    cin.sync_with_stdio(false);
    int n, k;
    long max = 0, temp, value = 0;
    long min = 0;
    long totalSum = 0;
    cin >> n >> k;
    vector<long> t;

    for (long i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > min) min = temp;
        t.push_back(temp);
        totalSum += temp;
    }

    max = totalSum/k;

    long x = 0;
    for (long b = min; b >= 1; b /= 2) {
        while (!testValue(x+b, k, t)) x += b;
    }
    long result = x+1;

    cout << result;
}