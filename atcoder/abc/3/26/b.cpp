#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    for (uint i = N; i <= 919; i++) {
        if ((i / 100U) * ((i % 100U) / 10U) == (i % 10U)) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
