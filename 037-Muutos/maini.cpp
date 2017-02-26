//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//long long n, q, temp, first(0);
//
//struct Node {
//    long mi;
//    long ma;
//    long ans;
//
//    Node(long mini, long maxi, long answ) {
//        mi = mini;
//        ma = maxi;
//        ans = answ;
//    }
//
//};
//
//
//
//Node merge(Node &a, Node &b) {
//    return Node(min(a.mi, b.mi), max(a.ma, b.ma), max(max(a.ans, b.ans), b.ma - a.mi));
//}
//
//long maxi(vector<Node> &p, int a, int b) {
//    Node ha(p[a]), hb(p[b]);
//    long la, lb;
//    while (a <= b) {
//        if (a%2 == 1) {
//            ha = p[a++];
//            cout << "a  " << a << '\n';
//        }
//        if (b%2 == 0) {
//            hb = p[b--];
//            cout << "b  " << b << '\n';
//        }
//        a /= 2; b /= 2;
//    }
//    return merge(ha, hb).ans;
//}
//
//int main() {
//    cin.sync_with_stdio(false);
//    cin >> n;
//    long long next = pow(2, ceil(log(n)/log(2)));
//    vector<Node> temps(next*2, Node(0,0,0));
//    long prev;
//    for (int j = 0; j < n; ++j) {
//        cin >> temp;
//        temps[next + j] = Node(temp, temp, 0);
//    }
//
//    for (long j = next - 1; j >= 1; --j) {
//        temps[j] = merge(temps[2 * j], temps[2 * j + 1]);
//    }
//
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        long a, b;
//        cin >> a >> b;
//        b += next - 1;
//        a += next - 1;
//        long res;
//        res = (max(maxi(temps, a, b), temps[b].ma - temps[a].ma));
//        cout << res << '\n';
//    }
//}
