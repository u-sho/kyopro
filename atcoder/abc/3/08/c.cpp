#include <bits/stdc++.h>
using namespace std;

using ui    = uint64_t;
using ABi_t = tuple<ui, ui, ui>;

int main() {
    ui N;
    cin >> N;

    ui i = 1;
    vector<ABi_t> abi(N);
    for (auto& [A, B, id] : abi) {
        id = i++;
        cin >> A >> B;
    }

    sort(abi.begin(), abi.end(), [](const ABi_t& x, const ABi_t& y) {
        const auto& [Ax, Bx, ix] = x;
        const auto& [Ay, By, iy] = y;
        // Ax/(Ax+Bx) > Ay/(Ay+By)  <=>  Ax(Ay+By) > Ay(Ax+Bx)
        return (make_pair(Ay * (Ax + Bx), ix) < make_pair(Ax * (Ay + By), iy));
    });

    for (const auto& [_a, _b, id] : abi) {
        cout << id << ' ';
    }

    return 0;
}
