#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    double radius;
    cin >> radius;
    double volume = (pow(radius, 3) * 4 * M_PI) / 3;
    printf("%.6lf", volume);
}