#include <algorithm>
#include <iostream>
#include <vector>

using AB = std::pair<int, int>;
std::istream &operator>>(std::istream &is, AB &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    using std::cin;
    using std::cout;
    using std::vector;

    int H, N;
    cin >> H >> N;

    vector<AB> ab(N);
    for (AB &aibi : ab) cin >> aibi;
    // 消費魔力の昇順にソート
    std::sort(ab.begin(), ab.end(),
              [](const AB &p1, const AB &p2) { return p1.second < p2.second; });

    int max_A = 0;
    for (const AB abi : ab) max_A = std::max(abi.first, max_A);
    constexpr int INF = 2000000000;
    // dp[i] : iのダメージを与えるのに必要な最小消費魔力
    vector<int> dp(H + max_A);  // dp.size() <= 2e4
    std::fill(dp.begin(), dp.end(), INF);
    dp.at(0) = 0;
    for (const AB abi : ab) {  // ab.size() <=1e3
        int Ai = abi.first;
        int Bi = abi.second;
        for (int i = 1; i <= std::min(Ai, H + max_A - 1); ++i) {
            dp.at(i) = std::min(dp.at(i), Bi);
        }
        for (int i = Ai + 1; i < H + max_A; ++i) {
            dp.at(i) = std::min(dp.at(i), dp.at(i - Ai) + Bi);
        }
    }

    cout << dp.at(H) << '\n';
    return 0;
}