#include <bits/stdc++.h>
using namespace std;

uint T;
uint N;
vector<int64_t> A;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for (uint t = 1; t <= T; t++) {
        cin >> N;
        for (A.resize(N); int64_t &Ai : A) cin >> Ai;

        // Ai != 0.
        // 公比が -1 のとき
        ranges::sort(A);
        if (A[0] == -A[N - 1]) {
            if (N & 1) {  // N が奇数
                if (A[0] == A[N / 2 - 1] && A[N / 2 + 1] == A[N - 1] &&
                    llabs(A[0]) == llabs(A[N / 2])) {
                    cout << "Yes" << endl;
                    continue;
                }
            } else if (A[0] == A[N / 2 - 1] && A[N / 2] == A[N - 1]) {
                cout << "Yes" << endl;
                continue;
            }
            cout << "No" << endl;
            continue;
        }

        ranges::sort(A, [](const auto &Ai, const auto &Aj) {
            return llabs(Ai) > llabs(Aj);
        });

        int64_t A0 = A[0], A1 = A[1];
        auto it =
            ranges::adjacent_find(A, [A1, A0](const auto &Ai, const auto &Aj) {
                // Aが等比数列ならば，A0 : A1 = Ai : Aj
                return Ai * A1 != Aj * A0;
            });
        if (it == A.end()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
