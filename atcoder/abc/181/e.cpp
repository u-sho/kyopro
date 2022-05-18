#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t N, M;
    cin >> N >> M;
    vector<lli> H(N);
    for (lli &Hi : H) cin >> Hi;
    vector<lli> W(M);
    for (lli &Wi : W) cin >> Wi;

    sort(H.begin(), H.end());
    sort(W.begin(), W.end());

    vector<lli> sum01((N + 1UL) / 2UL), sum12((N + 1UL) / 2UL);
    for (int i = 1; i < N; i += 2)
        sum01[i / 2 + 1] = sum01[i / 2] + H[i] - H[i - 1];
    for (int i = N - 1; i > 0; i -= 2)
        sum12[i / 2] = sum12[i / 2 + 1] + H[i + 1] - H[i];

    int ans = INT_MAX;
    for (size_t henshin = 0UL; henshin <= N; henshin++) {
    }

    return 0;
}
