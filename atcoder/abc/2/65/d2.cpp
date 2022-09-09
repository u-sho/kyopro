#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long;

template <class K>
bool none(const set<K> &S, const K &key) {
    return S.find(key) == S.end();
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    ulli P, Q, R;
    cin >> N >> P >> Q >> R;

    ulli sum_A = 0;
    set<ulli> partial_sum_A({0});
    for (uint Ai, i = 0; i < N; ++i) {
        cin >> Ai;
        partial_sum_A.insert(sum_A += (ulli)Ai);
    }

    for (const ulli &pAx : partial_sum_A) {
        if (none(partial_sum_A, pAx + P)) continue;
        if (none(partial_sum_A, pAx + P + Q)) continue;
        if (none(partial_sum_A, pAx + P + Q + R)) continue;

        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}