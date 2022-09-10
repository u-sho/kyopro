#include <bits/stdc++.h>
using namespace std;
using ullong = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;

    vector<uint> squares;
    for (ullong i = 0ULL; i * i <= (ullong)N; i++) squares.push_back(i * i);
    squares.push_back(UINT_MAX);

    ullong ans = 0ULL;
    for (uint i = 1U; i <= N; i++) {  // O(N√N)
        uint k = i;
        for (uint h = 2; squares[h] <= k; h++) {  // < O(√i)
            while (k % squares[h] == 0U) k /= squares[h];
        }
        // k := i を割り切れる最大の平方数で割ったもの
        all_of(next(squares.begin()), squares.end(),  // O(√N)
               [k, N, &ans](const uint &square) {
                   if ((ullong)k * (ullong)square > (ullong)N) return false;
                   ++ans;  // (i, k * square)
                   return true;
               });
    }

    cout << ans << '\n';
    return 0;
}
