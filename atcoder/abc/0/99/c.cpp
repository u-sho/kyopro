#include <algorithm>
#include <iostream>
#include <vector>

using vi = std::vector<int>;

const vi pow6n = {1, 6, 36, 216, 1296, 7776, 46656, 279936};  // [0,7], [0,8)
const vi pow9n = {1, 9, 81, 729, 6561, 59049, 531441};        // [0,6], [0,7)
vi pows        = {1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049};

int main(void) {
    std::sort(pows.rbegin(), pows.rend());

    int N;
    std::cin >> N;

    int ans = 1'000'000'000;  // '

    // 9^p で i円， 6^p で (N-i)円を withdrow
    for (int i = 0; i <= N; ++i) {
        int withdrow_num = 0;

        // 9^p で i円 引き出す
        int i9 = i;
        for (int j = 6; j >= 0; --j) {
            withdrow_num += i9 / pow9n.at(j);
            i9 %= pow9n.at(j);
        }

        // 6^p で (N-i)円 引き出す
        int i6 = N - i;
        for (int j = 7; j >= 0; --j) {
            withdrow_num += i6 / pow6n.at(j);
            i6 %= pow6n.at(j);
        }

        ans = std::min(ans, withdrow_num);
    }

    std::cout << ans << '\n';

    return 0;
}
