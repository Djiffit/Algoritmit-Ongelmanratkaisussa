#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long n, m;
vector<vector<long>> dp;


int main() {
    cin >> n >> m;
    dp = vector<vector<long>>(n, vector<long>(m, 0));
    vector<vector<char>> map(n, vector<char>(m));
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            cin >> map[k][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.') {
                if (i > 0 && j > 0) {
                    dp[i][j] = (long)((dp[i - 1][j] + dp[i][j - 1]) % (long)(pow(10, 9) + 7));
                } else if (i == 0 && j > 0) {
                    dp[i][j] = (long)(dp[i][j - 1] % (long)(pow(10, 9) + 7));
                } else if (j == 0 && i > 0) {
                    dp[i][j] = (long)(dp[i - 1][j] % (long)(pow(10, 9) + 7));
                } else {
                    dp[i][j] = 1;
                }
                dp[i][j] = (long)(dp[i][j] % (long)(pow(10, 9) +7));
            }
        }
    }
    cout << dp[n-1][m-1];
}