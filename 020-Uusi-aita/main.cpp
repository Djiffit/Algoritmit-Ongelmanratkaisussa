#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    vector<int> fence;
    vector<int> indexes;
    long n, k;
    long long t = 1;
    cin >> n;
    vector<vector<long long>> fences(n, vector<long long>(10000, 0));
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k != 0) {
            indexes.push_back(i);
            fences[i][k]++;
        }
        fence.push_back(k);
    }
    for (int j = 1; j < n; ++j) {
        if (abs(fence[j] - fence[j-1] ) == 0 && fence[j] != 0) {
            cout << 0;
            exit(0);
        }
    }
    sort(indexes.begin(), indexes.end());
    long long sum = 0;
    for (auto in : indexes) {
        int left = -1, right = -1;
        if (in != 0) left = in -1;
        if (in != n-1) right = in+1;
        while (left != -1 && fence[left-1] == 0 && fence[left] == 0 && left > -1 && left < n) {
            for (int i = 0; i < 10000; ++i) {
                if (fences[left+1][i] != 0) {
                    if (i > 1) fences[left][i - 1]+= fences[left+1][i];
                    fences[left][i + 1]+= fences[left+1][i];
                }
            }
            if (left == 0) {
                for (int i = 0; i < 10000; ++i) {
                    sum += fences[left][i];
                    sum = sum %((long)pow(10, 9) + 7);
                }
                if (sum > 0) {
                    sum = sum %((long)pow(10, 9) + 7);
                    t *= sum;
                    t = t %((long)pow(10, 9) + 7);
                }
                sum = 0;
            }
            left--;
        }
        while (right != n && fence[right] == 0 && right >= 0 && right < n) {
            for (int i = 0; i < 10000; ++i) {
                if (fences[right-1][i] != 0) {
                    if (i > 1) fences[right][i - 1]+= fences[right-1][i];
                    fences[right][i + 1]+= fences[right-1][i];
                }
            }
            if ((right == n-1) ||fence[right+1] != 0) {
                if (right == n-1) {
                    for (int i = 0; i < 10000; ++i) {
                        sum += fences[right][i];
                        sum = sum %((long)pow(10, 9) + 7);
                    }
                } else {
                    for (int i = 0; i < 10000; ++i) {
                        if (fences[right +1][i+1] != 0 ||fences[right+1][i-1] != 0) {
                            sum += fences[right][i];
                            sum = sum %((long)pow(10, 9) + 7);
                        }
                    }
                }
                if (sum > 0) {
                    sum = sum %((long)pow(10, 9) + 7);
                    t *= sum;
                    t = t %((long)pow(10, 9) + 7);
                } if (sum == 0 && right != n-1) {
                    cout << 0;
                    exit(0);
                }
                sum = 0;
            }
            right++;
        }
    }

    if (indexes.size() != n && t == 1) cout << 0;
    else cout << t;
    exit(0);
    return 0;
}