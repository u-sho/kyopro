#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> T(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tij;
            cin >> tij;
            T[i].push_back(tij);
        }
    }

    int ans = 0;

    vector<int> route;
    for (int i = 2; i <= N; i++) route.push_back(i);
    do {
        unsigned int sum_time = T[0][route[0] - 1];
        for (int i = 0; i < route.size() - 1; i++) {
            sum_time += T[route[i] - 1][route[i + 1] - 1];
        }
        sum_time += T[route.back() - 1][0];
        if (sum_time == K) ++ans;
    } while (next_permutation(route.begin(), route.end()));

    cout << ans << "\n";

    return 0;
}
