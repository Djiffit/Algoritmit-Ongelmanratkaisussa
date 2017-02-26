#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio();
    long n, t = 0, a, b, temp, an = 0;
    cin >> n >> a >> b;
    int ca = b-a;
    vector<long> nrs;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nrs.push_back(temp);
    }
    map<pair<long, long>, long> answers;
    if (b == 1) answers[{0,0,}]++;
    int l1 = 0, l2 = 0, r1{0}, r2{0};
    map<long, int> left;
    map<long, int> right;
    left[nrs[0]]++;
    right[nrs[0]]++;
    while (l1 != n) {
        while (left.size() < b && l2 != n-1) {
            l2++;
            left[nrs[l2]]++;
        }
        while (l2 != n-1 && left.find(nrs[l2+1]) != left.end()) {
            l2++;
            left[nrs[l2]]++;
        }
        if (left.size() <= b) t+= l2-l1+1;
        left[nrs[l1]]--;
        if (left[nrs[l1]] == 0) left.erase(nrs[l1]);
        l1++;
    }
    while (r1 != n) {
        while (right.size() < a - 1 && r2 != n-1) {
            r2++;
            right[nrs[r2]]++;
        }
        while (r2 != n-1 && right.find(nrs[r2+1]) != right.end()) {
            r2++;
            right[nrs[r2]]++;
        }
        if (right.size() < a) t-= (r2-r1+1);
        right[nrs[r1]]--;
        if (right[nrs[r1]] == 0) right.erase(nrs[r1]);
        r1++;
    }
//    while (l1 < n - 1) {
//        int c = left.size();
//        if ((c < b && l2 != n - 1) || (c == b && l2 != n - 1 && left.find(nrs[l2 + 1]) != left.end())) {
//            l2++;
//            left[nrs[l2]]++;
//        } else {
//            left[nrs[l1]]--;
//            if (left[nrs[l1]] == 0) left.erase(nrs[l1]);
//            l1++;
//        }
//        if (left.size() == b && left.find(nrs[l2 + 1]) == left.end()) an += l2 -l1-b+1;
//    }
//        while (r1 != n-1) {
//            int c = right.size();
//            if ((c > a) || (c == a && right[nrs[r1]] != 1)) {
//                right[nrs[r1]]--;
//                if (right[nrs[r1]] == 0) right.erase(nrs[r1]);
//                r1++;
//                if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//            } else {
//                if (r2 != n-1) {
//                    r2++;
//                    right[nrs[r2]]++;
//                    if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//                } else {
//                    right[nrs[r1]]--;
//                    if (right[nrs[r1]] == 0) right.erase(nrs[r1]);
//                    r1++;
//                    if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//                }
//            }
//            int c = right.size();
//            if (c < a && r1 != 0) {
//                r1--;
//                right[nrs[r1]]++;
//                if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//            } else {
//                if ((right[nrs[r2]] > 1 || c > a) || r1 == 0) {
//                    right[nrs[r2]]--;
//                    if (right[nrs[r2]] == 0) right.erase(nrs[r2]);
//                    r2--;
//                    if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//                } else {
//                    r1--;
//                    right[nrs[r1]]++;
//                    if (right.size() >= a && right.size() <= b) answers.insert({{r1, r2}, r2});
//                }
//            }


    cout << t;
}

int firstmain() {
    cin.sync_with_stdio(false);
    long n, t= 0, a, b, temp, l= 0, r = 0;
    cin >> n >> a >> b;
    vector<long> nrs;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nrs.push_back(temp);
    }
    bool firstset;
    map<long, int> un;
    long first;
    map<long, int> uniques;
    long prev = 0;
    for (int j = 0; j < n; ++j) {
        r = j;
        if (firstset) {
            r = first;
            for (int i = r; i < prev; ++i) {
                int l = uniques.find(nrs[i]).operator*().second;
                l--;
                uniques.erase(nrs[i]);
                if (l > 0) {
                    uniques.insert({nrs[i], l});
                }
            }
            prev = r;
        }
        firstset = false;
        while (r < n) {
            for (int i = prev; i <= r; ++i) {
                if (uniques.find(nrs[i]) == uniques.end()) {
                    uniques.insert({nrs[i], 1});
                } else {
                    int l = uniques.find(nrs[i]).operator*().second;
                    l++;
                    uniques.erase(nrs[i]);
                    uniques.insert({nrs[i], l});
                }
            }
            auto c = uniques.size();
            if (c >= a && c <= b) {
                if (!firstset) {
                    firstset = true;
                    first = r;
                }
                t++;
            }
            if (c > b) {
                int l = uniques.find(nrs[r]).operator*().second;
                l--;
                uniques.erase(nrs[r]);
                if (l > 0) {
                    uniques.insert({nrs[r], l});
                }
                break;
            }
            r++;
            prev = r;
        }
        int l = uniques.find(nrs[j]).operator*().second;
        l--;
        uniques.erase(nrs[j]);
        if (l > 0) {
            uniques.insert({nrs[j], l});
        }
    }
    cout << t;
    return 0;
}