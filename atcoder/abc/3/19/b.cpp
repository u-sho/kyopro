#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint16_t N;
    cin >> N;

    string s(N + 1, '-');
    for (uint16_t i = 0; i <= N; i++)
        for (uint16_t j = 1; j <= 9; j++) {
            if (N % j == 0 && i % (N / j) == 0) {
                s.at(i) = j + '0';
                break;
            }
        }

    cout << s << '\n';

    return 0;
}
