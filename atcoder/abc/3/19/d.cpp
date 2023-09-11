#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint_fast32_t N, M;
    cin >> N >> M;
    vector<uint_fast32_t> L(N);
    for (uint_fast32_t& Li : L) cin >> Li;

    const auto maxL = uint_fast64_t(ranges::max(L));
    const auto maxW = reduce(L.begin(), L.end(), uint_fast64_t(N - 1U));

    // 画面幅が W のとき，M 行を超えるか
    const auto is_over_M = [&L, &M](const uint_fast64_t W) -> bool {
        uint_fast32_t lines  = 1U;
        uint_fast64_t cursor = 0U;
        for (const auto& Li : L) {
            if (cursor + Li > W) {  // 画面幅を超えるなら改行
                ++lines;
                cursor = 0U;
            }
            cursor += Li + 1U;  // 行末に単語（＋空白）を追加
        }
        return (lines > M);
    };

    const auto minW =
        ranges::partition_point(views::iota(maxL, maxW), is_over_M);
    cout << *minW << '\n';

    return 0;
}
