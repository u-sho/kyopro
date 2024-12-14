#include <bits/stdc++.h>
using namespace std;

bool isRated(int rate, uint division) {
    if (division == 1) {
        return (1600 <= rate && rate <= 2799);
    }
    if (division == 2) {
        return (1200 <= rate && rate <= 2399);
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, R;
    cin >> N >> R;

    int T = R;
    for (uint i = 1; i <= N; ++i) {
        uint Di;
        int Ai;
        cin >> Di >> Ai;
        if (isRated(T, Di)) {
            T += Ai;
        }
    }

    cout << T << '\n';
    return 0;
}
