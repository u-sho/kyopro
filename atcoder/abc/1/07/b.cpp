#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr char BLACK = '#';
constexpr char WHITE = '.';

int main(void) {
    using std::cin;
    using std::cout;
    using std::string;
    using std::vector;

    int H, W;
    vector<string> a;

    cin >> H >> W;
    a.resize(H);
    for (auto &ai : a) cin >> ai;

    bool changed = true;  // 更新フラグ
    while (changed) {
        changed = false;

        for (int i = 0; i < H; ++i) {  // 空行を探す
            auto it = std::find(a.at(i).begin(), a.at(i).end(), BLACK);
            if (it == a.at(i).end()) {  // 黒が見つからないければ，行iを削除
                a.erase(a.begin() + i);
                --i;
                --H;
                changed = true;
            }
        }

        for (int i = 0; i < W; ++i) {  // 空列を探す
            bool black_exist = false;
            for (int j = 0; j < H; ++j) {
                if (a.at(j).at(i) == BLACK) {
                    black_exist = true;
                    break;
                }
            }
            if (!black_exist) {
                for (int j = 0; j < H; ++j) {  // 列iを削除
                    a.at(j).erase(a.at(j).begin() + i);
                }
                --i;
                --W;
                changed = true;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        cout << a.at(i) << '\n';
    }

    return 0;
}