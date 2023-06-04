#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    if (N < 1'000U) cout << N << '\n';
    else if (N < 10'000U) cout << N - N % 10U << '\n';
    else if (N < 100'000U) cout << N - N % 100U << '\n';
    else if (N < 1'000'000U) cout << N - N % 1'000U << '\n';
    else if (N < 10'000'000U) cout << N - N % 10'000U << '\n';
    else if (N < 100'000'000U) cout << N - N % 100'000U << '\n';
    else if (N < 1'000'000'000U) cout << N - N % 1'000'000U << '\n';

    return 0;
}
