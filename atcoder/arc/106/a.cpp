#include <iostream>
using namespace std;
using ulli = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ulli N;
    cin >> N;

    int A = 0, B;
    for (ulli three_pow_A = 1ULL; ; A++, three_pow_A *= 3ULL) {
        ulli five_pow_B = 1ULL;
        for (B = 0; B < 26 && three_pow_A + five_pow_B <= N; B++, five_pow_B *= 5ULL) {
            if (three_pow_A + five_pow_B == N) goto END_FOR;
        }
        if (A == 37 || three_pow_A * 3ULL >= N) {
            cout << "-1\n";
            return 0;
        }
    }

    END_FOR:
    cout << A << " " << B << "\n";
    return 0;
}
