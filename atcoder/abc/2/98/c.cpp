#include <bits/stdc++.h>
using namespace std;

using ullong = unsigned long long;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;  // <= 2e5, #{box}
    cin >> N;
    unsigned Q;  // <= 2e5, #{query}
    cin >> Q;

    using pqu = priority_queue<unsigned, vector<unsigned>, greater<unsigned>>;
    vector<pqu> in_box(N + 1U);
    multimap<unsigned, unsigned> cards;

    while (Q--) {
        unsigned query_kind, i;
        cin >> query_kind >> i;

        // card i into the box j
        if (query_kind == 1) {
            unsigned j;
            cin >> j;
            in_box[j].push(i);

            bool has_card_i_in_box_j = false;
            auto [it_begin, it_end]  = cards.equal_range(i);
            for (auto it = it_begin; it != it_end; ++it) {
                if (it->second == j) has_card_i_in_box_j = true;
            }
            if (!has_card_i_in_box_j) cards.insert(make_pair(i, j));
            continue;
        }

        // display cards in the box i
        if (query_kind == 2) {
            if (in_box[i].empty()) {
                cout << "\n";
                continue;
            }
            pqu tmp           = in_box[i];
            const unsigned& x = tmp.top();
            cout << x;
            tmp.pop();
            while (!tmp.empty()) {
                const unsigned& x = tmp.top();
                cout << ' ' << x;
                tmp.pop();
            }
            cout << "\n";
            continue;
        }

        // display boxs of card i
        if (query_kind == 3) {
            auto [it_begin, it_end] = cards.equal_range(i);
            for (auto it = it_begin; it != it_end; ++it) {
                cout << (it->second) << ' ';
            }
            cout << "\n";
            continue;
        }
    }

    return 0;
}
