#include <bits/stdc++.h>

#define REP(i, n) for (uint_fast64_t i = 0ULL; i < (n); i++)

// std::lcm の多変数引数版
template <class Head, class... Tail>
constexpr Head std::lcm(Head head, Tail... tail) {
    return std::lcm(head, std::lcm(std::forward<Tail>(tail)...));
}
constexpr uint_fast64_t mod = std::lcm(8U, 7U, 6U, 5U, 4U, 3U, 2U, 1ULL);

int main() {
    using namespace std;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, X, Y;
    cin >> N >> X >> Y;
    vector<pair<unsigned, unsigned>> PT(N - 1U);
    for (auto &PTi : PT) cin >> PTi.first >> PTi.second;
    unsigned Q;
    cin >> Q;
    vector<unsigned> q(Q);
    for (unsigned &qi : q) cin >> qi;

    // 時刻 i∈[0, lcm[1,8]] からスタートしたときの移動時間
    array<uint_fast64_t, mod> transit_time_for_departure_at;
    REP(departure_time, mod) {
        // 時刻 departure_time からスタートしたときの到着時刻
        uint_fast64_t arrival_time = departure_time + X;
        for (const auto &[Pi, Ti] : PT) {
            if (arrival_time % Pi)
                arrival_time +=
                    Pi - (arrival_time % Pi);  // 次のバスまでの待ち時間
            arrival_time += Ti;                // バス移動時間
        }
        arrival_time += Y;

        transit_time_for_departure_at[departure_time] =
            arrival_time - departure_time;
    }

    for (const auto &qi : q) {
        // 時刻 qi で出発したときの到着時刻
        uint_fast64_t arrival_time =
            qi + transit_time_for_departure_at[qi % mod];

        cout << arrival_time << '\n';
    }

    return 0;
}
