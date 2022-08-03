#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    int ans = A.at(0);
    for (const int Ai : A) {
        ans = __gcd(ans, Ai);
    }

    cout << ans << '\n';

    return 0;
}
