#include <iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	int length, value;
	long sum = 0;
	cin >> length;
	for (int i = 0; i < length; ++i) {
		cin >> value;
		sum += value;
		cout << sum << "\n";
	}
}