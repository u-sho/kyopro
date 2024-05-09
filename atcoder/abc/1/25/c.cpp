#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using atcoder::segtree;

uint ugcd(uint n, uint m) { return gcd(n, m); }
uint UINT_GCD_E() { return 0U; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    segtree<uint, ugcd, UINT_GCD_E> A(N);
    for (int i = 0; i < N; i++) {
        uint Ai;
        cin >> Ai;
        A.set(i, Ai);
    }

    uint ans = A.prod(1, N);
    for (int i = 1; i < N - 1; i++)
        ans = max(ans, gcd(A.prod(0, i), A.prod(i + 1, N)));
    ans = max(ans, A.prod(0, N - 1));

    std::cout << ans << '\n';

    return 0;
}
