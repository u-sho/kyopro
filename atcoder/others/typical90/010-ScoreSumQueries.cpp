#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<pair<ushort, ushort>> CP(N);
    for (auto& [C, P] : CP) cin >> C >> P;

    vector<uint> p_sum_with_1(N + 1UL, 0U), p_sum_with_2(N + 1UL, 0U);
    for (uint i = 0U; i < N; i++) {
        const auto [C, P] = CP[i];
        p_sum_with_1[i + 1UL] = p_sum_with_1[i];
        p_sum_with_2[i + 1UL] = p_sum_with_2[i];
        if (C == 1) p_sum_with_1[i + 1U] += uint(P);
        if (C == 2) p_sum_with_2[i + 1U] += uint(P);
    }

    uint Q;
    cin >> Q;
    while (Q--) {
        uint L, R;
        cin >> L >> R;
        cout << p_sum_with_1[R] - p_sum_with_1[L - 1] << ' ';
        cout << p_sum_with_2[R] - p_sum_with_2[L - 1] << '\n';
    }

    return 0;
}