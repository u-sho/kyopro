#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    // inputs
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int &ci : c) cin >> ci;
    vector<pair<int, int>> lr(q);
    for (pair<int, int> &lri : lr) cin >> lri;

    vector<bitset<500000>> ruiseki(n);
    bitset<500000> initRuiseki(0);
    fill(ruiseki.begin(), ruiseki.end(), initRuiseki);

    for (int i = 0; i < n; ++i) {
        ruiseki.at(i).at()
    }

    return 0;
}
