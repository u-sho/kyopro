#include <bits/stdc++.h>
using namespace std;

int main() {
    uint64_t N;
    cin >> N;
    while (N % 2ULL == 0ULL) N /= 2ULL;
    while (N % 3ULL == 0ULL) N /= 3ULL;
    if (N == 1ULL) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
