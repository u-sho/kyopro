#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    size_t n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;

    sort(a.begin(), a.end());

    int l = 1;
    int r = a.at(n - 1);
    while (l < r) {
        int c = (l + r) / 2;
        int K = k;
        for (const int ai : a) {
            if ((ulli)ai > (ulli)c * ((ulli)K + 1UL)) break;
            if (ai > c) K -= (ai / c);  // あまりがんばる
            if (ai == a.at(n - 1)) {
                K = -1;
            }
        }
    }

    return 0;
}
