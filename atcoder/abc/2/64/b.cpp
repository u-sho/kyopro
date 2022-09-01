#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const vector<string> g = {
        "bbbbbbbbbbbbbbb", "bwwwwwwwwwwwwwb", "bwbbbbbbbbbbbwb",
        "bwbwwwwwwwwwbwb", "bwbwbbbbbbbwbwb", "bwbwbwwwwwbwbwb",
        "bwbwbwbbbwbwbwb", "bwbwbwbwbwbwbwb", "bwbwbwbbbwbwbwb",
        "bwbwbwwwwwbwbwb", "bwbwbbbbbbbwbwb", "bwbwwwwwwwwwbwb",
        "bwbbbbbbbbbbbwb", "bwwwwwwwwwwwwwb", "bbbbbbbbbbbbbbb",
    };

    unsigned short R, C;
    cin >> R >> C;
    cout << (g[R - 1][C - 1] == 'b' ? "black\n" : "white\n");

    return 0;
}
