#include <iostream>
#include <vector>

using namespace std;
constexpr unsigned R_MAX = 10u;
constexpr unsigned C_MAX = 10'000u;

unsigned R, C;
vector<vector<bool>> 煎餅の状態(R_MAX, vector<bool>(C_MAX));

unsigned count_出荷可能な煎餅(unsigned flip) {
    unsigned count = 0u;
    for (unsigned i = 0; i < C; i++) {
        unsigned count_column = 0u;
        for (unsigned j = 0; j < R; j++) {
            bool is_flip = (flip & (1u << j));
            if (煎餅の状態.at(j).at(i) ^ is_flip) {
                ++count_column;
            }
        }
        count += max(count_column, R - count_column);
    }
    return count;
}

int main(void) {
    cin >> R >> C;
    for (unsigned i = 0; i < R; i++) {
        for (unsigned j = 0; j < C; j++) {
            char c;
            cin >> c;
            煎餅の状態.at(i).at(j) = (c == '1');
        }
    }

    unsigned count = count_出荷可能な煎餅(0u);
    for (unsigned i = 1u; i < (1u << R); i++) {  // 2^10
        count = max(count, count_出荷可能な煎餅(i));
    }

    cout << count << '\n';

    return 0;
}