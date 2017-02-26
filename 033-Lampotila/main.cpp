#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long n, q, temp, start, end;

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    long next = pow(2, ceil(log(n)/log(2)));
    vector<long> treeMin(next*2, INFINITY);
    vector<long> treeMax(next*2, -INFINITY);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        treeMin[next + i] = temp;
        treeMax[next + i] = temp;
    }
    for (int j = next - 1; j >= 1; --j) {
        treeMin[j] = min(treeMin[2 * j] , treeMin[2 * j + 1]);
        treeMax[j] = max(treeMax[2 * j], treeMax[2* j + 1]);
    }
    cin >> q;
    long end;
    for (int k = 0; k < q; ++k) {
        long minv = INFINITY;
        long maxv = -INFINITY;
        cin >> start >> end;
        start+= next - 1;
        end += next - 1;
        while (start <= end && (start != 0 && end != 0)) {
            if (start % 2 == 1) {
                minv = min(minv, treeMin[start]);
                maxv = max(maxv, treeMax[start]);
                start++;
            }
            if (end %2 == 0) {
                minv = min(minv, treeMin[end]);
                maxv = max(maxv, treeMax[end]);
                end--;
            }
            start = start/2;
            end = end/2;
        }
        cout << minv << ' ' << maxv << '\n';
    }
}
/*
 * int a,
a+= N; b += N;
int summa = 0;
while(a<=b) {
	if a pariton {s+= puu[a++]}
	if b parillinen {s+= puu[b--]}
	a /=2, b/=2;"
}
 *
 */