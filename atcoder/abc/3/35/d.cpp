#include <bits/stdc++.h>
using namespace std;

unsigned N, grid[45][45];

pair<int, int> operator+(const pair<int, int> &p1, const pair<int, int> &p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

bool isInGrid(const pair<int, int> &p) {
    if (p.first < 0 || p.second < 0) return false;
    if (p.first >= N || p.second >= N) return false;
    if (grid[p.first][p.second]) return false;
    return true;
}

int main() {
    cin >> N;

    pair<int, int> curr         = {0, 0};
    unsigned di                 = 0;
    const pair<int, int> dir[4] = {
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    };
    for (unsigned x = 1; x <= N * N; x++) {
        grid[curr.first][curr.second] = x;
        if (!isInGrid(curr + dir[di])) {
            di++;
            di %= 4U;
        }
        curr = curr + dir[di];
    }

    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            if (grid[i][j] == N * N) {
                cout << "T ";
            } else {
                cout << grid[i][j] << (j + 1U != N ? ' ' : '\n');
            }
        }
    }

    return 0;
}