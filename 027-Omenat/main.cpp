#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <chrono>
#include <unordered_map>

using namespace std;

long total = INT32_MAX;
vector<long> apples;
vector<pair<long, vector<long>>> j;
vector<long> b;
long nn;
vector<long> persons;

void haku(int k) {
    if (k == nn+1) {
        total = abs(min(abs(min(min(persons[0], persons[1]), persons[2]) - max(max(persons[0], persons[1]), persons[2])), total));
    } else {
        persons[0]+= apples[k];
        haku(k+1);
        persons[0]-= apples[k];
        persons[1]+= apples[k];
        haku(k+1);
        persons[1]-= apples[k];
        persons[2]+= apples[k];
        haku(k+1);
        persons[2]-= apples[k];
    }
}

int main() {
    long best = INFINITY;
    cin.sync_with_stdio(false);
    vector<long> people;
    people.push_back(0);
    people.push_back(0);
    people.push_back(0);

    long n, k;
    cin >> n;
    nn = n;
    apples.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        apples.push_back(k);
    }
    persons.push_back(0);
    persons.push_back(0);
    persons.push_back(0);
    haku(1);
    cout << total;

}