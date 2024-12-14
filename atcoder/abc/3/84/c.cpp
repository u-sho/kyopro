#include <iostream>
#include <set>

#define BitDP(flag, value) \
    for (decltype(value) flag = 0; flag <= (value); flag += (value))

using score_t       = uint;
using name_t        = std::string;
using participant_t = std::pair<score_t, name_t>;

struct comp {
    template <class T = participant_t>
    bool operator()(const T &l, const T &r) const {
        // 点数が同じなら辞書順
        if (l.first == r.first) return l.second > r.second;

        // 基本は点数順
        return l.first < r.first;
    }
};

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    score_t a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    std::set<participant_t, comp> participants;

    BitDP(A, a) BitDP(B, b) BitDP(C, c) BitDP(D, d) BitDP(E, e) {
        const score_t score = A + B + C + D + E;
        name_t solved       = "";
        if (A) solved.push_back('A');
        if (B) solved.push_back('B');
        if (C) solved.push_back('C');
        if (D) solved.push_back('D');
        if (E) solved.push_back('E');

        participants.insert({score, solved});
    }

    const participant_t first_participant = {a + b + c + d + e, "ABCDE"};

    auto it = participants.lower_bound(first_participant);
    for (uint i = 0; i < 31; ++i) {
        std::cout << it->second << '\n';
        --it;
    }

    return 0;
}
