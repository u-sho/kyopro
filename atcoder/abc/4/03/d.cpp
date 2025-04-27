#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, D;
    cin >> N >> D;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;
    ranges::sort(A);

    if (D == 0) {
        A.erase(unique(begin(A), end(A)), end(A));
        cout << N - A.size() << '\n';
        return 0;
    }

    uint sum = 0;
    for (auto i = A.begin(); i != A.end();) {
        // A[i] == A[j - 1] && A[j - 1] < A[j] である j を探す．
        const auto j = ranges::upper_bound(A, *i);

        // A[i] + D == A[k] && A[k-1] < A[k] である k を探す．
        const auto k = ranges::lower_bound(A, *i + D);
        // A[i] + D == A[m - 1] && A[m-1] < A[m] である m を探す．
        const auto m = ranges::upper_bound(A, *i + D);

        const int count_ij = j - i;
        const int count_km = m - k;
        if (count_km <= count_ij) {
            A.erase(k, m);
            sum += count_km;
        } else {
            // ここの操作は最適じゃない気がするけど投げる
            A.erase(i, j);
            sum += count_ij;
        }

        i = j;
    }

    cout << sum << '\n';
    return 0;
}
