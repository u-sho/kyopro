#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    // 入力
    size_t N;
    cin >> N;
    vector<pair<int, int>> wh(N);
    for (pair<int, int> &whi : wh) cin >> whi;

    // wの昇順にソート
    sort(wh.begin(), wh.end());

    // ans: h_i_1 < h_i_2 < … < h_i_m を満たす最大の m
    int ans = 1;
    // TODO: BITで求める

    // 出力
    cout << ans << "\n";

    return 0;
}
