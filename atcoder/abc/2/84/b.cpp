#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned T;
    cin >> T;
    while (T--) {
        unsigned N;
        cin >> N;
        unsigned count = 0u;
        while (N--) {
            unsigned Ai;
            cin >> Ai;
            if (Ai & 1u) ++count;
        }
        cout << count << '\n';
    }

    return 0;
}
