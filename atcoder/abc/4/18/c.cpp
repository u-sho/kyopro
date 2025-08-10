#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, Q;
    cin >> N >> Q;
    vector<uint64_t> A(N);
    for(uint64_t & Ai : A) cin >> Ai;

    ranges::sort(A);
    vector<uint64_t> psum_A(N);
    partial_sum(A.begin(), A.end(), psum_A.begin());

    for(uint j=0; j<Q; j++) {
        uint Bj;
        cin >> Bj;

        if (A[N-1] < Bj) {
            cout << "-1\n";
            continue;
        }
        if (A[0] >= Bj - 1) {
            uint64_t x = (Bj - 1) * N + 1;
            cout << x << '\n';
            continue;
        }

        auto it = ranges::lower_bound(A, Bj);
        size_t idx = it - A.begin() - 1ull;
        size_t cnt = A.end() - it;
        uint64_t x = psum_A[idx];
        x += (Bj - 1ll) * cnt + 1ull;
        cout << x << '\n';
    }

    return 0;
}
