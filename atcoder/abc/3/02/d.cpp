#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

int main() {
    // fast io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // inputs: N, M, D, A, B
    int64_t N, M, D;
    cin >> N >> M >> D;
    vector<int64_t> A(N);
    for (int64_t &Ai : A) cin >> Ai;
    vector<int64_t> B(M);
    for (int64_t &Bi : B) cin >> Bi;

    // 尺とりで調べる
    SORT(A);
    SORT(B);
    int64_t ans = -1LL;
    int64_t ai = 0, bi = 0;
    while (ai < N && bi < M) {  // N+M回繰り返す
        if (abs(A[ai] - B[bi]) <= D) {
            ans = max(ans, A[ai] + B[bi]);
            if (A[ai] <= B[bi]) {
                if (bi + 1LL < M && abs(B[bi + 1] - A[ai]) <= D) bi++;
                else ai++;
            } else {
                if (ai + 1LL < N && abs(A[ai + 1] - B[bi]) <= D) ai++;
                else bi++;
            }
        } else {
            if (A[ai] <= B[bi]) {
                if (ai + 1LL < N) ai++;
                else bi++;
            } else {
                if (bi + 1LL < M) bi++;
                else ai++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
