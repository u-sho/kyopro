#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<pii> AB(N);
    for (pii &ABi : AB) cin >> ABi.first >> ABi.second;

    sort(AB.begin(), AB.end(),
         [](const pii &p1, const pii &p2) { return p1.second < p2.second; });

    string ans    = "Yes\n";
    int curr_time = 0;
    for (const pii &abi : AB) {
        curr_time += abi.first;
        if (curr_time > abi.second) {
            ans = "No\n";
            break;
        }
    }

    cout << ans;

    return 0;
}
