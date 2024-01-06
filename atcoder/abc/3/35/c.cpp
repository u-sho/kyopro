#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, Q;
    cin >> N >> Q;

    deque<pair<int, int>> 龍;
    for (unsigned i = N; i >= 1U; i--) 龍.push_back({i, 0});

    REP(q, Q) {
        char kind;
        cin >> kind;
        if (kind == '1') {
            char C;
            cin >> C;
            auto next_head = 龍[N - 1];
            龍.pop_front();
            switch (C) {
                case 'R':
                    next_head.first++;
                    break;
                case 'L':
                    next_head.first--;
                    break;
                case 'U':
                    next_head.second++;
                    break;
                case 'D':
                    next_head.second--;
                    break;
            }
            龍.push_back(next_head);
        }
        if (kind == '2') {
            unsigned p;
            cin >> p;
            cout << 龍[N - p].first << ' ' << 龍[N - p].second << '\n';
        }
    }

    return 0;
}
