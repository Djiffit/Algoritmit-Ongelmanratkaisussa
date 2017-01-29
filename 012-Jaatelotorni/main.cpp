#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long n, h, temp;

vector<long> balls;

bool test(long k) {
    long x = 0, y = 0;
    vector<vector<long>> towers(k, vector<long>(h, 0));
    for (auto l : balls) {
        bool placed = false;
        if (y == 0) {
            towers[x][y] = l;
            placed = true;
        } else if (towers[x][y-1]*2 <= l) {
            towers[x][y] = l;
            placed = true;
        }
        if (placed) {
            if (x == k - 1) {
                y++;
                x = 0;
                if (y == h) return true;
            } else {
                x++;
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        balls.push_back(temp);
    }
    sort(balls.begin(), balls.end());
    long t = 0;
    for (long b = n/h; b >= 1; b /= 2) {
        while (test(t+b)) t += b;
    }
    cout << t;
}