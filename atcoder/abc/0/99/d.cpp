#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
    using std::cin;
    using std::cout;
    using std::vector;

    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C);
    for (int i = 0; i < C; ++i) {
        D.at(i).resize(C);
        for (int j = 0; j < C; ++j) {
            cin >> D.at(i).at(j);
        }
    }
    vector<int> c_mod_0(C);
    vector<int> c_mod_1(C);
    vector<int> c_mod_2(C);
    std::fill(c_mod_0.begin(), c_mod_0.end(), 0);
    std::fill(c_mod_1.begin(), c_mod_1.end(), 0);
    std::fill(c_mod_2.begin(), c_mod_2.end(), 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int c;
            cin >> c;
            if ((i + j) % 3 == 0) c_mod_0.at(c - 1) += 1;
            if ((i + j) % 3 == 1) c_mod_1.at(c - 1) += 1;
            if ((i + j) % 3 == 2) c_mod_2.at(c - 1) += 1;
        }
    }

    // c_mod_0 -> color i
    // c_mod_1 -> color j
    // c_mod_2 -> color k
    int min_wrongness = 1'000'000'000;  //'
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j == i) continue;
            for (int k = 0; k < C; ++k) {
                if (k == i || k == j) continue;
                int d_sum = 0;
                for (int c = 0; c < C; ++c) {
                    d_sum += c_mod_0.at(c) * D.at(c).at(i);
                    d_sum += c_mod_1.at(c) * D.at(c).at(j);
                    d_sum += c_mod_2.at(c) * D.at(c).at(k);
                }
                min_wrongness = std::min(min_wrongness, d_sum);
            }
        }
    }

    std::cout << min_wrongness << '\n';
    return 0;
}
