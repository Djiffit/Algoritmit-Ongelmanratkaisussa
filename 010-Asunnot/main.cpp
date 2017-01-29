#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int mainss() {
    cin.sync_with_stdio(false);
    long n,k,x,y, t= 0;
    cin >> n >> k;
    multiset<pair<long, long>> apartments;
    multiset<pair<long, long>> applicants;
    multiset<long> pool;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        applicants.insert({x, y});
    }
    for (int j = 0; j < k; ++j) {
        cin >> x >> y;
        apartments.insert({x, y});
    }
    for (auto a : applicants) {
        auto it = apartments.lower_bound(a);
        for (auto i = apartments.begin(); i != it; ++i) {
            pool.insert(i.operator*().second);
        }
        auto ite = pool.lower_bound(a.second);
        if (ite != pool.end()) {
            t++;
            cout << ite.operator*() << ' ' << a.second <<'\n';
            pool.erase(ite.operator*());
        }
        cout << ' ';
    }
    cout << t;
}

int main() {
    cin.sync_with_stdio(false);
    long n = 0, k= 0, y= 0, x= 0, t = 0;
    cin >> n >> k;
    multiset<pair<long, long>> apps;
    multiset<pair<long, long>> apls;
    multiset<pair<long, long>> pool;
    for (long i = 0; i < n; ++i) {
        cin >> y >> x;
        apls.insert({y, x});
    }
    for (long i = 0; i < k; ++i) {
        cin >> y >> x;
        apps.insert({y, x});
    }
    for (auto p : apls) {
        auto it = apps.lower_bound({p.first, 0});
        if (it != apps.begin()) {
            it--;
        }
        while (apps.size() > 0 && it.operator*().first <= p.first) {
            pool.insert({it.operator*().second, it.operator*().first});
            apps.erase(it.operator*());
            it--;
        }
        auto a = pool.lower_bound({p.second, 0});

        if (a != pool.end() && a.operator*().first >= p.second) {
            t++;
            pool.erase(a);
        }
    }
    cout << t;
}