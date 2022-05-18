#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 3;
int nC[400005];

/* 𝑶(n log(MOD)) */
void set_comb(int n) {
    //--------Valid Error------------------
    if (n <= 0 || r < 0) assert(false);
    if (n < r) assert(false);
    //-------------------------------------

    nC[0] = nC[n] = 1;
    if (n == 1) return;

    // MOD上での逆元(モジュラ逆数)を求める
    int inverse[MOD] = {-1, 1, 2};

    for (int i = 1; i < n; ++i) {
        nC[i] = nC[i - 1] * (n - i + 1);
        nC[i] %= MOD;
        nC[i] *= inverse[i];
        nC[i] %= MOD;
    }

    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string c;
    cin >> c;

    vector<int> C;
    const string kv = "WRB";
    for (const char ci : c) {
        for (int i = 0; i < 3; ++i)
            if (ci == kv[i]) C.push_back(i);
    }
    set_comb(N - 1);
    for (int i = 0; i < N; ++i) cout << nC[i] << " ";
    cout << "\n";

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ret += nC[i] * C[i];
        ret %= MOD;
    }
    cout << ret << "\n";
    if (N & 1) ret = (MOD - ret) % MOD;

    cout << kv[ret] << "\n";
    return 0;
}
