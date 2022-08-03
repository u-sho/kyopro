#include <bits/stdc++.h>

int main() {
    using namespace std;

    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, int>> monsters(n);
    for (auto) {
        int x, h;
        cin >> x >> h;
        monsters.push_back(make_pair(x, h));
    }

    sort(monsters.begin(), monsters.end());  // xの昇順

    deque<pair<int, int>> que;  // (爆破範囲, 爆破回数)
    pair<int, int> left = monsters[0];
    int min_range       = left.first + 2 * d;  // que.front().first
    int sum_damage      = left.second / a + ((left.second % a) ? 1 : 0);
    long long ans       = (long long)sum_damage; // 左端を倒すのに必要な最小爆破回数
    que.push_back(make_pair(min_range, sum_damage));
    sum_damage *= a;  // 爆破ダメージ

    // 端っこから爆破していく
    for (int i = 1; i < n; i++) {
        left = monsters[i];
        if (left.first > min_range) {
            if (!que.empty()) {
                cout << "upper start\n";
                decltype(que)::iterator it = upper_bound(que.begin(), que.end(), make_pair(min_range,0));
                cout << "upper end\n";
                cout << (*it).first << endl;
                cout << (*(que.end()-1)).first << endl;
                while (it != que.end()-1) { // ここが平均500以内に収まれば良い？
                    sum_damage -= que.front().second * a;
                    que.pop_front();
                }
                cout << "while end\n";
            }
            if (!que.empty()) {
                min_range = que.front().first;
            } else {
                min_range  = left.first + 2 * d;
                sum_damage = left.second / a +
                             ((left.second % a) ? 1 : 0);  // tmp爆破回数
                que.push_back(make_pair(min_range, sum_damage));
                ans += sum_damage;
                sum_damage *= a;
                left = monsters[++i];
            }
            cout << "update end\n";
        }
        if (left.second > sum_damage) {
            left.second -= sum_damage;
            int bakuhahannni = left.first + 2 * d;
            int bakuhakaisuu = left.second / a + ((left.second % a) ? 1 : 0);
            que.push_back(make_pair(bakuhahannni, bakuhakaisuu));
            sum_damage += bakuhakaisuu * a;
            ans += bakuhakaisuu;
        }
        cout << "updates end\n";
    }
    cout << ans << endl;
    return 0;
}