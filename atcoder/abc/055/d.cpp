#include <bits/stdc++.h>
using namespace std;

#define unknown 'X'  // NOTE!!
#define say_same 'o'
#define say_diff 'x'
#define disable "-1"

#define Ss ss_sw_ws_ww.at(0UL)
#define Sw ss_sw_ws_ww.at(1UL)
#define Ws ss_sw_ws_ww.at(2UL)
#define Ww ss_sw_ws_ww.at(3UL)

string solve(const size_t N, string &s) {
    s = s.at(N - 1UL) + s + s.at(0UL);

    const string sheep = "WS";
    string ss(N + 2UL, unknown);
    vector<string> ss_sw_ws_ww(4UL, ss);
    Ss.at(1UL) = Ss.at(2UL) = Sw.at(1UL) = Ws.at(2UL) = sheep[true];
    Sw.at(2UL) = Ws.at(1UL) = Ww.at(1UL) = Ww.at(2UL) = sheep[false];
    if (s.at(1UL) == say_same) {
        Ss.at(0UL) = Ww.at(0UL) = sheep[true];
        Sw.at(0UL) = Ws.at(0UL) = sheep[false];
    } else {
        Ss.at(0UL) = Ww.at(0UL) = sheep[false];
        Sw.at(0UL) = Ws.at(0UL) = sheep[true];
    }

    for (size_t i = 2UL; i <= N; i++) {
        for (string &ss_i : ss_sw_ws_ww) {
            bool i_is_sheep   = (ss_i.at(i) == sheep[true]);
            bool im1_is_sheep = (ss_i.at(i - 1UL) == sheep[true]);
            if (s.at(i) == say_same)
                ss_i.at(i + 1UL) = sheep[(i_is_sheep == im1_is_sheep)];
            else
                ss_i.at(i + 1UL) = sheep[(i_is_sheep != im1_is_sheep)];
        }
    }

    for (const string &ss_i : ss_sw_ws_ww) {
        if (ss_i.at(N) == ss_i.at(0UL) && ss_i.at(N + 1UL) == ss_i.at(1UL))
            return ss_i.substr(1UL, N);
    }
    return disable;
}

int main() {
    size_t N;
    cin >> N;
    string s;
    cin >> s;

    cout << solve(N, s) << "\n";
    return 0;
}
