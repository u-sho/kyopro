#include <bits/stdc++.h>
using namespace std;

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
//     for (std::size_t i = 0; i < v.size(); i++) {
//         os << v[i] << (i + 1UL != v.size() ? "" : "\n");  // 空白区切り
//         // os << v[i] << "\n";  // 改行区切り
//     }
//     return os;
// }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M, Q;
    cin >> N >> M >> Q;

    bitset<200'000> ALL_PAGES_USER_CAN_VIEW;
    for (uint i = 0; i < M; i++) {
        ALL_PAGES_USER_CAN_VIEW[i].flip();
    }

    vector<bitset<200'000>> pages_user_can_view(N);

    REP(q, Q) {
        uint query;
        cin >> query;
        if (query == 1) {
            uint X, Y;
            cin >> X >> Y;
            pages_user_can_view[X - 1][Y - 1] = true;
            continue;
        }
        if (query == 2) {
            uint X;
            cin >> X;
            pages_user_can_view[X - 1] |= ALL_PAGES_USER_CAN_VIEW;
            continue;
        }
        if (query == 3) {
            uint X, Y;
            cin >> X >> Y;
            cout << (pages_user_can_view[X - 1][Y - 1] ? "Yes\n" : "No\n");
        }
        // cout << X << ": " << pages_user_can_view[X - 1];

        // switch (query) {
        //     case 1:
        //         cin >> Y;
        //         pages_user_can_view[X - 1][Y - 1] = true;
        //         break;
        //     case 2:
        //         pages_user_can_view[X - 1] |= ALL_PAGES_USER_CAN_VIEW;
        //         break;
        //     case 3:
        //         cin >> Y;
        //         cout << (pages_user_can_view[X - 1][Y - 1] ? "Yes\n" :
        //         "No\n"); break;
        //     default:
        //         assert(-1);
        //         break;
        // }
    }

    return 0;
}
