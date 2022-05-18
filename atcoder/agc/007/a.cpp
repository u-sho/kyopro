#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::make_pair;
using std::pair;
using std::queue;
using std::string;
using std::vector;
using Grid = vector<string>;
using HW   = pair<short, short>;

const char PASSED = '#';
const char WALL   = '.';

const vector<HW> MOVES = {
    make_pair(1, 0),  // 下へ
    make_pair(0, 1)   // 右へ
};

bool bfs(short H, short W, Grid A) {
    HW start = {0, 0};
    HW goal  = {H - 1, W - 1};

    queue<HW> que;
    que.push(start);

    while (!que.empty()) {
        HW prev = que.front();
        que.pop();

        bool wall_exist = false;
        bool pass_exist = false;
        for (const HW& dm : MOVES) {
            short h = prev.first + dm.first;
            short w = prev.second + dm.second;
            HW curr = {h, w};
            if (h < 0 || w < 0 || h >= H || w >= W) {
                wall_exist = true;
                continue;
            }
            if (A.at(h).at(w) == WALL) {
                wall_exist = true;
                continue;
            }
            if (curr == goal) return true;

            pass_exist = true;
            que.push(curr);
        }
        if (!wall_exist || !pass_exist) {
            return false;
        }
    }

    return false;
}

const string ans[2] = {"Impossible\n", "Possible\n"};

int main() {
    short H, W;
    std::cin >> H >> W;
    Grid A(H);
    for (short i = 0; i < H; ++i) {
        std::cin >> A.at(i);
    }

    bool able_to_reach_by_R_B_move = bfs(H, W, A);
    std::cout << ans[able_to_reach_by_R_B_move];

    return 0;
}