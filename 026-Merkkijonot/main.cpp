#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

set<string> words;

void listEm(multiset<char> v, string word){
    if (v.size() == 0) {
        words.insert(word);
    }
    auto d = v;
    for (auto c : v) {
        word+= c;
        if (v.find(c) != v.end()) {
            d.erase(d.find(c));
            listEm(d, word);
            word.erase(word.size() - 1);
            d.insert(c);
        }
    }
}
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    string temp;
    cin.sync_with_stdio(false);
    multiset<char> letters;
    unordered_map<char, int> count;
    cin >> temp;
    for (auto c : temp) {
        letters.insert(c);
        if (count.find(c) == count.end()) {
            count.insert({c,1});
        } else {
            count[c]++;
        }
    }
    long sum= 1;
    for (auto i = count.begin(); i != count.end(); ++i) {
        sum*= factorial(i.operator*().second);
    }
    cout << factorial(letters.size()) / sum << '\n';
    listEm(letters, "");
    for (auto j= words.begin(); j != words.end() ; ++j) {
        cout << j.operator*() << '\n';
    }
}
