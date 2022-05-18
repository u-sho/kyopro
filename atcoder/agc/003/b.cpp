#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

int main(void) {
    using std::cin;
    using std::cout;

    int N;
    cin >> N;
    vector<int> A(N);
    for (int &ai : A) cin >> ai;

    if (N == 1) {
        cout << A.at(0) / 2 << '\n';
        return 0;
    }

    long long ans = 0LL;
    for (int i = 0; i < N - 1; ++i) {
        // A[i] を偶数なら使い切る
        int p = A.at(i) / 2;
        A.at(i) -= 2 * p;

        // A[i]が奇数でも，A[i]!=0で使い切る
        int p_diff = std::min(A.at(i), A.at(i + 1));
        A.at(i) -= p_diff;
        A.at(i + 1) -= p_diff;

        ans += (long long)p_diff + (long long)p;
    }

    // A[N] 以外にはカードが残っていない
    // A[N] でペアを作る
    ans += (long long)A.at(N - 1) / 2LL;

    cout << ans << '\n';
    return 0;
}