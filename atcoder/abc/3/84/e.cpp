#include <bits/stdc++.h>
using namespace std;

using ul = uint64_t;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    uint H, W, X;
    cin >> H >> W >> X;
    uint P, Q;
    cin >> P >> Q;
    vector<vector<ul>> S(H, vector<ul>(W, 0));
    for (auto &Si : S)
        for (ul &Sij : Si) cin >> Sij;

    // 初期位置
    vector<vector<uint>> is_Takahashi(H, vector<uint>(W, 0));
    uint i = P - 1U, j = Q - 1U;
    __uint128_t T            = S[i][j];
    is_Takahashi.at(i).at(j) = 1;

    // 4方向を追加
    queue<pair<uint, uint>> dp;
    if (i > 0) dp.push({i - 1, j});
    if (j > 0) dp.push({i, j - 1});
    if (i + 1 < H) dp.push({i + 1, j});
    if (j + 1 < W) dp.push({i, j + 1});

    while (!dp.empty()) {
        auto [i, j] = dp.front();
        dp.pop();

        if (is_Takahashi.at(i).at(j)) {
            // 髙橋くんで，かつ周辺は新しい値で調査済み
            if (T == S[i][j]) continue;

            // 髙橋くんの周辺を再調査
            S[i][j] = T;
            if (i > 0)
                if (!is_Takahashi.at(i - 1).at(j)) dp.push({i - 1U, j});
            if (i + 1U < H)
                if (!is_Takahashi.at(i - 1U).at(j)) dp.push({i + 1U, j});
            if (j > 0)
                if (!is_Takahashi.at(i).at(j - 1U)) dp.push({i, j - 1U});
            if (j + 1U < W)
                if (!is_Takahashi.at(i).at(j + 1U)) dp.push({i, j + 1U});

            std::cout << (ul)T << ": " << i << ", " << j << "\n";
            for (const auto &Si : S) {
                for (const ul &Sij : Si) std::cout << Sij << ' ';
                std::cout << '\n';
            }

            continue;
        }

        // 髙橋くんじゃない
        std::cout << (ul)T << ": " << i << ", " << j << "\n";
        for (const auto &Si : S) {
            for (const ul &Sij : Si) std::cout << Sij << ' ';
            std::cout << '\n';
        }

        if (S[i][j] * X < T) {
            // 髙橋くんに吸収される
            T                        += S[i][j];
            is_Takahashi.at(i).at(j)  = 1;

            // 新しい高橋くんの値で周辺を調査
            S[i][j] = T;
            if (i > 0) dp.push({i - 1U, j});
            if (i + 1U < H) dp.push({i + 1U, j});
            if (j > 0) dp.push({i, j - 1U});
            if (j + 1U < W) dp.push({i, j + 1U});

            continue;
        }

        // 高橋君にはまだ吸収されない
        if (i > 0)
            if (is_Takahashi.at(i - 1).at(j)) {
                if (S[i - 1][j] == T) continue;
                else dp.push({i - 1, j});
            }
        if (i + 1U < H)
            if (is_Takahashi.at(i - 1U).at(j)) {
                if (S[i + 1][j] == T) continue;
                else dp.push({i + 1, j});
            }
        if (j > 0)
            if (is_Takahashi.at(i).at(j - 1U)) {
                if (S[i][j - 1] == T) continue;
                else dp.push({i, j - 1});
            }
        if (j + 1U < W)
            if (is_Takahashi.at(i).at(j + 1U)) {
                if (S[i][j + 1] == T) continue;
                else dp.push({i, j + 1});
            }
    }

    std::cout << (ul)T << '\n';
    for (const auto &Si : S) {
        for (const ul &Sij : Si) std::cout << Sij << ' ';
        std::cout << '\n';
    }
}
