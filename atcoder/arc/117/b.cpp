#include <bits/stdc++.h>

using namespace std;

using lli  = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    // erase dupli
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    lli ans = (lli)(A[0]+1);
    constexpr lli mod = 1'000'000'007; //'
    for (int i=1; i<A.size(); i++){
        ans *= (lli)(A[i]-A[i-1]+1);
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}
