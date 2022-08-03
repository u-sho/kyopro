#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using lli = long long;

constexpr lli inf = 1'000'000'000'000'000'018LL;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    size_t N, M;
    int T;
    cin >> N >> M >> T;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    // abc[from][?] = {to, cost}
    // bac[to][?] = {from, cost}
    vector<vector<pair<int, int>>> abc(N + 1UL), bac(N + 1UL);
    for (size_t i = 0UL; i < M; i++) {
        cout << abc.size() << bac.size() << "\n";
        int a, b, c;
        cin >> a >> b >> c;
        abc.at((size_t)a).push_back(make_pair(b, c));
        bac.at((size_t)b).push_back(make_pair(a, c));
        // cout << a << b << c << "\n";
    }

    // solve
    // 1 -> i への最短時間
    vector<lli> time_from_1(N + 1UL, inf);
    time_from_1.at(1) = 0LL;
    // i -> 1 への最短距離
    vector<lli> time_to_1(N + 1UL, inf);
    time_to_1.at(1) = 0LL;

    // time_from_1 を bfs で求める
    queue<int> next;
    next.push(1);
    while (!next.empty()) {
        int i = next.front();
        next.pop();

        for (const pair<int, int> &bc : abc.at(i)) {
            if (bc.first == 1) continue;
            if (time_from_1.at(i) + (lli)bc.second < time_from_1.at(bc.first)) {
                time_from_1.at(bc.first) = time_from_1.at(i) + (lli)bc.second;
                next.push(bc.first);
            }
        }
    }

    // time_to_1 を bfs で求める
    next.push(1);
    while (!next.empty()) {
        size_t i = next.front();
        next.pop();

        for (const pair<int, int> &ac : bac.at(i)) {
            if (ac.first == 1) continue;
            if (time_from_1.at(i) + (lli)ac.second < time_from_1.at(ac.first)) {
                time_from_1.at(ac.first) = time_from_1.at(i) + (lli)ac.second;
                next.push(ac.first);
            }
        }
    }

    // (i にできるだけ滞在したときの時間 × A_i) の最大値
    lli ans = 0LL;
    for (size_t i = 1UL; i <= N; i++) {
        ans = max(ans,
                  ((lli)T - time_from_1.at(i) - time_to_1.at(i)) * A.at(i + 1));
    }

    cout << ans << "\n";

    return 0;
}
