#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, D;
    cin >> N >> D;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    vector<uint> sub_ceq(N, 0u), sub_ceq_b(N, 0u);
    for (uint i = 1u; i < N; i++) {
        if (abs(A[i] - A[i - 1]) <= D) {
            sub_ceq[i] = sub_ceq[i - 1] + 1u;
        }
    }
    for (int i = N - 2u; i; i--) {
        if (abs(A[i] - A[i + 1]) <= D) {
            sub_ceq_b[i] = sub_ceq_b[i - 1] + 1u;
        }
    }

    return 0;
}
