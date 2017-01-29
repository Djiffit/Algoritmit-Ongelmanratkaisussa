#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);

    long a;
    cin >> a;
    cout << a << "\n";

    while (a != 1) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a *= 3;
            a++;
        }
        cout << a << "\n";
    }
}