#include <bits/stdc++.h>
using namespace std;

using Participant = pair<uint, string>;

struct comp {
    template <typename T>
    bool operator()(const T &l, const T &r) const {
        if (l.first == r.first) {
            return l.second > r.second;
        }

        return l.first < r.first;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint abcde[5];
    for (auto &point : abcde) cin >> point;

    set<Participant, comp> participants;

    for (uint a = 0; a <= abcde[0]; a += abcde[0]) {
        for (uint b = 0; b <= abcde[1]; b += abcde[1]) {
            for (uint c = 0; c <= abcde[2]; c += abcde[2]) {
                for (uint d = 0; d <= abcde[3]; d += abcde[3]) {
                    for (uint e = 0; e <= abcde[4]; e += abcde[4]) {
                        const uint score = a + b + c + d + e;
                        string solved    = "";
                        if (a) solved.push_back('A');
                        if (b) solved.push_back('B');
                        if (c) solved.push_back('C');
                        if (d) solved.push_back('D');
                        if (e) solved.push_back('E');

                        participants.insert({score, solved});
                    }
                }
            }
        }
    }

    const uint sum = reduce(abcde, abcde + 5, 0U);
    auto it        = participants.lower_bound({sum, "ABCDE"});
    for (uint i = 0; i < 31; ++i) {
        cout << it->second << '\n';
        --it;
    }

    return 0;
}
