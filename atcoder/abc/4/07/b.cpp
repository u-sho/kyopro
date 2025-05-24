#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    uint X, Y;
    cin >> X >> Y;

    uint pattern_num = 0u;
    for (uint i = 1u; i <= 6u; i++) {
        for (uint j = 1u; j <= 6u; j++) {
            if (i + j >= X || i >= Y + j || j >= i + Y) ++pattern_num;
        }
    }

    cout << setprecision(11) << fixed << (double(pattern_num) / 36.0) << '\n';
    return 0;
}
