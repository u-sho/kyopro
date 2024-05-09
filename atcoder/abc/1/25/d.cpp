#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    bool isOddMinusAi = false;
    for (const int &Ai : A) isOddMinusAi ^= Ai < 0;

    for (int &Ai : A)
        if (Ai < 0) Ai *= -1;

    int64_t sum_A = reduce(A.begin(), A.end(), 0LL);
    int64_t min_A = isOddMinusAi ? ranges::min(A) : 0LL;
    cout << sum_A - 2 * min_A << '\n';

    return 0;
}
