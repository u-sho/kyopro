#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int C = A - B;
    A *= 100;
    C *= 10'000;

    cout << fixed << setprecision(8);
    cout << (double)C / (double)A << "\n";

    return 0;
}
