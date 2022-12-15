#include <iostream>
#include <map>
#include <vector>

using namespace std;
using Coordinates = pair<int, int>;
using Picture = multimap<int, int>;

int main(void) {
    // 探したい星座を構成する星の個数.
    unsigned m;
    cin >> m;
    // 探したい星座を構成する星の座標.
    vector<Coordinates> constellation(m);
    for (Coordinates &xyi : constellation) cin >> xyi.first >> xyi.second;

    // 写真に写っている星の個数.
    unsigned n;
    cin >> n;
    Picture stars;
    for (unsigned i = 0u; i < n; i++) {
        int x, y;
        cin >> x >> y;
        stars.emplace(x, y);
    }

    // 探したい星座を構成する星の座標をα星(適当)からの相対座標に変換.
    for (unsigned i = 1u; i < m; i++) {
        constellation.at(i).first -= constellation.at(0).first;
        constellation.at(i).second -= constellation.at(0).second;
    }

    // 写真に写っている星各々が、探したい星座のα星であるかどうかを判定.
    for (const Coordinates &maybe_alpha : stars) {
        bool is_alpha = true;
        for (unsigned i = 1u; i < m; i++) {
            bool is_matched = false;
            const Coordinates &xy = constellation.at(i);
            auto range = stars.equal_range(maybe_alpha.first + xy.first);
            for (auto it = range.first; it != range.second; it++) {
                if (it->second == maybe_alpha.second + xy.second) {
                    is_matched = true;
                    break;
                }
            }
            if (!is_matched) {
                is_alpha = false;
                break;
            }
        }
        if (is_alpha) {
            cout << maybe_alpha.first - constellation.at(0).first << " "
                 << maybe_alpha.second - constellation.at(0).second << "\n";
        }
    }
    return 0;
}