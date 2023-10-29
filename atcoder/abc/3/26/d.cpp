#include <bits/stdc++.h>
using namespace std;

#define SORT(v)  std::ranges::sort(v)
#define ALL(v)   (v).begin(), (v).end()
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string R;
    cin >> R;
    string C;
    cin >> C;

    vector<string> A(N, ".....");
    for (auto &Ai : A) Ai.resize(N);

    vector<uint> counter_C(3, 0);  // A,B,C
    vector<uint> counter_R(3, 0);  // A,B,C
    for (const auto &Ci : C) {
        counter_C[Ci - 'A']++;
    }
    for (const auto &Ri : R) {
        counter_R[Ri - 'A']++;
    }
    if (counter_C[0] == 0 || counter_C[1] == 0 || counter_C[2] == 0) {
        cout << "No\n";
        return 0;
    }
    if (counter_R[0] == 0 || counter_R[1] == 0 || counter_R[2] == 0) {
        cout << "No\n";
        return 0;
    }

    // 全探索
    if (N == 3U) {
        if (R[0] == C[0]) {
            A[0]    = C;
            A[1][0] = R[1];
            A[2][0] = R[2];
            if (R[1] == C[1]) {
                A[1][1] = R[2];
                A[2][2] = R[1];
                A[1][2] = A[2][1] = R[0];
            } else {
                A[1][2] = R[2];
                A[2][1] = R[1];
                A[1][1] = A[2][2] = R[0];
            }
            cout << "Yes\n";
            cout << A[0] << "\n" << A[1] << "\n" << A[2] << "\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }

    return 0;
}
