#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using std::bitset;
using std::cin;
using std::cout;
using std::max;
using std::pair;
using std::size_t;
using std::vector;

int main() {
    // inputs
    size_t N;
    cin >> N;

    vector<int> A(N);
    vector<vector<pair<int, bool>>> xy(N);
    for (size_t i = 0uL; i < N; ++i) {
        cin >> A.at(i);
        for (int j = 0; j < A.at(i); ++j) {
            int x, y;
            cin >> x >> y;
            xy.at(i).push_back({x - 1, (y == 1)});
        }
    }

    // solve 𝑶(N^3)
    size_t ans = 0uL;
    for (int i = 1; i < int(1 << N); ++i) {
        // bit全探索
        bitset<16> bs = i;
        bool possible = true;

        for (size_t j = 0uL; j < N && possible; ++j) {
            // 人jが正直者
            if (!bs[j]) continue;

            for (int k = 0; k < A.at(j); ++k) {
                int xjk  = xy.at(j).at(k).first;
                bool yjk = xy.at(j).at(k).second;
                if (yjk) {  // 正直者j曰く，人xjkは正直者
                    if (!bs[xjk]) {
                        possible = false;
                        break;
                    }
                } else {  // 正直者j曰く，人xjkは不親切
                    if (bs[xjk]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible) ans = max(ans, bs.count());
        // if (possible) cout << i << ' ' << ans << '\n';
    }

    cout << ans << '\n';

    return 0;
}