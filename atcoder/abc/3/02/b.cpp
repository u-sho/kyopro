#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

const std::string snuke = "snuke";

using CharMatrix = std::vector<std::string>;
std::pair<std::pair<int, int>, std::pair<int, int>> searchSnuke(
    const CharMatrix& S, const unsigned H, const unsigned W) {
    std::vector<std::pair<int, int>> directions = {
        {-1, -1}, // 左上
        {-1,  0}, // 上
        {-1,  1}, // 右上
        { 0, -1}, // 左
        { 0,  1}, // 右
        { 1, -1},
        { 1,  0},
        { 1,  1}
    };
    REP(h, H) REP(w, W) {
        for (const auto& [dh, dw] : directions) {
            if (h + 4 * dh < 0 || h + 4 * dh >= H) continue;
            if (w + 4 * dw < 0 || w + 4 * dw >= W) continue;

            int _h = h, _w = w;
            bool is_snuke = false;
            for (const char c : snuke) {
                if (S[_h][_w] != c) break;
                is_snuke  = (c == snuke.back());
                _h       += dh;
                _w       += dw;
            }
            if (is_snuke) {
                return {
                    { h,  w},
                    {dh, dw}
                };
            }
        }
    }
    return {
        {-1, -1},
        {-1, -1}
    };
}

int main() {
    unsigned H, W;
    std::cin >> H >> W;

    CharMatrix S(H);
    for (auto& Si : S) std::cin >> Si;

    const auto& [hw, dhw] = searchSnuke(S, H, W);
    const auto [h, w]     = hw;
    const auto [dh, dw]   = dhw;
    REP(i, snuke.length()) {
        std::cout << (h + 1 + i * dh) << ' ' << (w + 1 + i * dw) << '\n';
    }
    return 0;
}
