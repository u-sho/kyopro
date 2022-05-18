#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

int main(void) {
    using std::bitset;
    using std::cin;
    using std::cout;
    using std::vector;

    int N;
    cin >> N;
    vector<vector<int>> F(N);  // F[i][j] : 店i が 時間帯j に開いている
    for (int i = 0; i < N; ++i) {
        F.at(i).resize(10);
        for (int j = 0; j < 10; ++j) {
            cin >> F.at(i).at(j);
        }
    }
    // P[i][j] : 店iと同時に開く時間帯が丁度j個 のときの 店i についての利益
    vector<vector<int>> P(N);
    for (int i = 0; i < N; ++i) {
        P.at(i).resize(11);
        for (int j = 0; j < 11; ++j) {
            cin >> P.at(i).at(j);
        }
    }

    int x = -1000000000;
    for (std::size_t i = 1UL; i < 1024uL; ++i) {
        // 開店のパターンは2^10通り
        bitset<10> isOpen(i);

        int sum = 0;
        for (int j = 0; j < N; ++j) {
            // 店j と同時に開店している時間帯の個数
            short c = 0;
            for (short k = 0; k < 10; ++k) {
                if (F.at(j).at(k) && isOpen[k]) c++;
            }
            sum += P.at(j).at(c);
        }

        x = std::max(x, sum);
    }

    cout << x << '\n';

    return 0;
}