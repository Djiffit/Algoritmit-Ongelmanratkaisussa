#include <vector>
#include <iostream>
#include <bitset>
#include <chrono>
#include <cmath>

using namespace std;


string s[21];
vector<vector<int>> dp(1049000, vector<int>(26));
vector<int> num;

int logger[1<<21];

int n;
void generate(int current, int after, int to, int sz, int count) {
    if (sz == count) {
        num.push_back(current);
        return;
    }
    int t;
    
    if (after == 0) {
        t = 1;
    } else {
        t = 1<<after;
    }
    for (int i = after; i<=to; ++i, t<<=1) {
        generate(current|t, i+1, to, sz+1, count);
    }
}

int main() {

    for (int k = 1, i = 1; i<=20; ++i, k<<=1) {
        logger[k] = i;
    }
    cin >> n;
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    for (int i = 1, k = 1; i<=n; ++i, k<<=1) {
        dp[k][s[i].back() - 65] = 1;
    }

    for (int i = 2 ;i<=n; ++i) {
        generate(0,0,n-1,0,i);
        for (int current : num) {
            int copy = current;
            while (copy != 0) {
                int bit = copy & -copy;
                copy = copy & ~bit;

                int pos = logger[bit];
                int off = current & ~bit;
                char begi = s[pos].front();
                char end = s[pos].back();

                dp[current][end - 65] = dp[current][end - 65] % (long)(pow(10, 9) +7);
                dp[current][end - 65] += (dp[off][begi - 65]% (long)(pow(10, 9) +7));
            }
        }
        num.clear();
    }
    
    long long ans = 0LL;
    
    for (int i = 'A'; i <='Z'; ++i) {
        ans = ans % ((long)pow(10, 9) +7);
        ans += (dp[(1<<n)-1][i - 65]% ((long)pow(10, 9) +7));
    }
    auto t2 = chrono::high_resolution_clock::now();
  //  cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
  //       << " milliseconds\n";
    cout << ans << endl;
    return 0;
}