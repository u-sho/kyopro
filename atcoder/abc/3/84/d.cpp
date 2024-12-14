#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    uint64_t S;
    cin >> N >> S;
    vector<uint64_t> A(N);
    for (auto &Ai : A) cin >> Ai;

    // 昇順にして重複削除
    ranges::sort(A);
    A.erase(unique(begin(A), end(A)), end(A));
}
