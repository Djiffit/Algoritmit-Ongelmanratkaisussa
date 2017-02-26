#include <iostream>
#include <cmath>

using namespace std;
int main() {
    std::string s = "";
    long long result = 8;
    for (int i = 0; i < 8; ++i) {
        result = result*26 % ((long long)pow(10,9) + (long)7);
    }
    cout << (result) % ((long long)pow(10,9) + (long)7);
    return 0;
}