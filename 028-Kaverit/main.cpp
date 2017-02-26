#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<string> pps;
long total = 0;

void countFriends(set<pair<int, string>> &fs, set<pair<int, string>> &group) {
    auto fscopy = fs;
    for (auto f : fs) {
        bool valid = true;
        for (auto ff : group) {
            if (ff.second[f.first] != '1') {
                valid = false;
                break;
            }
        }
        if (valid) {
            total++;
            fscopy.erase(f);
            group.insert(f);
            countFriends(fscopy, group);
            group.erase(f);
        }
    }
}

int main() {
    cin >> n;
    string pp;
    vector<string> pps;
    for (int i = 0; i < n; ++i) {
        cin >> pp;
        pps.push_back(pp);
    }
    for (int j = 0; j < pps.size(); ++j) {
        total++;
        set<pair<int, string>> friends;
        for (int i = j; i < pps.size(); ++i) {
            if (pps[j][i] == '1') {
                friends.insert({i, pps[i]});
            }
        }
        auto s = set<pair<int, string>>();
        countFriends(friends, s);
    }
    cout << total;
}