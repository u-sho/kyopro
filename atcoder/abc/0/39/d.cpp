#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

const vector<std::pair<int, int>> MOVES = {{-1, -1},
                                           {-1, 0},
                                           {-1, 1},
                                           {0, -1},
                                           // here
                                           {0, 1},
                                           {1, -1},
                                           {1, 0},
                                           {1, 1}};

int main(void) {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &Si : S) cin >> Si;

    vector<string> res(H);
    for (string &r : res) {
        for (int i = 0; i < W; ++i) r.push_back('.');
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S.at(i).at(j) == '.') continue;
            bool wasBlack = true;
            for (const std::pair<int, int> &dm : MOVES) {
                int h = i + dm.first;
                int w = j + dm.second;
                if (h < 0 || w < 0 || h >= H || w >= W) continue;
                if (S[h][w] != '#') wasBlack = false;
            }
            if (wasBlack) {
                res.at(i).at(j) = '#';
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S.at(i).at(j) == '.') continue;
            bool possible = false;
            if (res.at(i).at(j) == '#') possible = true;
            for (const std::pair<int, int> &dm : MOVES) {
                if (possible) break;
                int h = i + dm.first;
                int w = j + dm.second;
                if (h < 0 || w < 0 || h >= H || w >= W) continue;
                if (res[h][w] == '#') possible = true;
            }
            if (!possible) {
                cout << "impossible\n";
                return 0;
            }
        }
    }

    cout << "possible\n";
    for (const string r : res) cout << r << '\n';

    return 0;
}