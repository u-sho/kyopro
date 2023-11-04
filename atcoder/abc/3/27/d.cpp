#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, M;
    cin >> N >> M;
    vector<unsigned> A(M);
    for (unsigned &Ai : A) cin >> Ai;
    vector<unsigned> B(M);
    for (unsigned &Bi : B) cin >> Bi;

    // グラフが2色彩色可能か（2部グラフか）判定する
    // https://noshi91.hatenablog.com/entry/2018/04/17/183132

    dsu uf(2 * N + 1);
    REP(i, M) {
        uf.merge(A[i], B[i] + N);
        uf.merge(A[i] + N, B[i]);
    }
    REP(i, M) {
        if (uf.same(A[i], A[i] + N) || uf.same(B[i], B[i] + N)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
