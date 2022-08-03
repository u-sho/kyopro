#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    lli X, K, D;
    cin >> X >> K >> D;

    if (X < 0LL) X = -X;

    lli t = X / D;
    X -= D * min(K, t);
    K -= min(K, t);
    if (K % 2) X -= D;

    cout << llabs(X) << "\n";
    return 0;
}
