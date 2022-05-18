#include <iostream>
#include <vector>

using std::vector;

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << p.first << " " << p.second;
    return os;
}

int main() {
    using std::cin;
    using std::cout;

    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H);
    for (vector<int> &ai : a) {
        ai.resize(W);
        for (int &aij : ai) {
            cin >> aij;
        }
    }

    using XY = std::pair<int, int>;
    vector<std::pair<XY, XY>> ans;
    // 奇数のやつを右に寄せる
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W - 1; ++j) {
            if (a[i][j] % 2) {
                // a[i][j]--;
                a[i][j + 1]++;
                ans.push_back({{i + 1, j + 1}, {i + 1, j + 2}});
            }
        }
    }
    // 右に寄せたやつをしたに寄せる
    for (int i = 0; i < H - 1; ++i) {
        if (a[i][W - 1] % 2) {
            // a[i][W-1]--;
            a[i + 1][W - 1]++;
            ans.push_back({{i + 1, W}, {i + 2, W}});
        }
    }

    // N = ans.size
    cout << ans.size() << '\n';
    for (const std::pair<XY, XY> &xyxy : ans) {
        cout << xyxy << '\n';
    }

    return 0;
}
