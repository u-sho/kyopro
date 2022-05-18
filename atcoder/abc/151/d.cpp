#include <bits/stdc++.h>

int wfs(int h, int w, bool initialPassed[][], bool passed[][], int start_h,
        int end_h, int start_w, int end_w) {}

int main() {
    using namespace std;

    int H, W;
    cin >> H >> W;
    char S[H][W];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) cin >> S[i][j];

    int ans = 0;
    bool passed[H][W], initialPassed[H][W];
    fill(initialPassed[0], initialPassed[H], false);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) initialPassed[i][j] = (S[i][j] == '#');
    copy(initialPassed[0], initialPassed[H], passed[0]);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!initialPassed[i][j])
                copy(initialPassed[0], initialPassed[H], passed[0]);
        }
    }

    return 0;
}
