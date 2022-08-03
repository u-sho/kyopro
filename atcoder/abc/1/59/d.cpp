#include <bits/stdc++.h>
int main() {
    using namespace std;

    int n;
    cin >> n;
    int A[n + 1], b[n + 1];
    fill(b, b + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        b[a]++;
        A[i] = a;
    }

    long long sum = 0LL;
    for (int i = 1; i <= n; i++) {
        sum += ((long long)b[i] * (b[i] - 1)) / 2LL;
    }

    for (int i = 1; i <= n; i++) {
        int diff      = (b[A[i]] == 0) ? 0 : (b[A[i]] - 1);
        long long ans = (sum <= diff) ? 0LL : (sum - (long long)diff);
        cout << ans << endl;
    }
    return 0;
}