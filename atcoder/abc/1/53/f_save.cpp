#include <bits/stdc++.h>

int main() {
    using namespace std;
    using ll = long long;

    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, int>> xh;
    for (auto &i:xh) cin >> i.first >> i.second;

    sort(xh.begin(), xh.end());  // xの昇順

    int min_range  = xh[0].first + 2 * d;
    ll sum_damage  = 0LL;
    ll ans         = 0LL;
    vector<pair<int, int>> que;  // (爆破範囲, 爆破回数)
    // 端っこだけばくは
    for (int i = 0; i < n; i++) {
        pair<int, int> left = xh[i];
        while (left.first > min_range) {
            if (!que.empty()) {
                sum_damage -= que[0].second * a;
                que.erase(que.begin());  // que.pop()
                min_range = que[0].first;
            } else {
                min_range  = left.first + 2 * d;
                sum_damage = 0;
            }
        }
        if (left.second > sum_damage) {
            left.second -= sum_damage;
            int bakuhahannni = left.first + 2 * d;
            int bakuhakaisuu = left.second / a + ((left.second % a) ? 1 : 0);
            que.push_back(make_pair(bakuhahannni, bakuhakaisuu));
            sum_damage += bakuhakaisuu * a;
            ans += bakuhakaisuu;
        }
    }
    cout << ans << endl;
    return 0;
}
