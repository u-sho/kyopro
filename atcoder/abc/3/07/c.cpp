#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    /* H_A: Aの縦の長さ, W_A: Aの横の長さ*/
    int H_A, W_A;
    cin >> H_A >> W_A;
    vector<string> A(H_A);
    for (string &Ai : A) cin >> Ai;

    /* H_B: Bの縦の長さ, W_B: Bの横の長さ*/
    int H_B, W_B;
    cin >> H_B >> W_B;
    vector<string> B(H_B);
    for (string &Bi : B) cin >> Bi;

    /* H_X: Xの縦の長さ, W_X: Xの横の長さ*/
    int H_X, W_X;
    cin >> H_X >> W_X;
    vector<string> X(H_X);
    for (string &Xi : X) cin >> Xi;

    /**
     * min_H_A := min_i { A_i_j が黒いマス },
     * min_W_A := min_j { A_i_j が黒いマス },
     * max_H_A := max_i { A_i_j が黒いマス },
     * max_W_A := max_j { A_i_j が黒いマス },
     */
    int min_H_A = H_A, min_W_A = W_A, max_H_A = 0, max_W_A = 0;
    for (int i = 0; i < H_A; i++) {
        string::size_type first_black_it = A[i].find('#');
        if (first_black_it != string::npos) {
            min_H_A = min(min_H_A, i);
            min_W_A = min(min_W_A, int(first_black_it));
            max_H_A = max(max_H_A, i);
            max_W_A = max(max_W_A, int(A[i].find_last_of('#')));
        }
    }

    /**
     * min_H_B := min_i { B_i_j が黒いマス },
     * min_W_B := min_j { B_i_j が黒いマス },
     * max_H_B := max_i { B_i_j が黒いマス },
     * max_W_B := max_j { B_i_j が黒いマス },
     */
    int min_H_B = H_B, min_W_B = W_B, max_H_B = 0, max_W_B = 0;
    for (int i = 0; i < H_B; i++) {
        string::size_type first_black_it = B[i].find('#');
        if (first_black_it != string::npos) {
            min_H_B = min(min_H_B, i);
            min_W_B = min(min_W_B, int(first_black_it));
            max_H_B = max(max_H_B, i);
            max_W_B = max(max_W_B, int(B[i].find_last_of('#')));
        }
    }

    // solve: 全探索 (16 * max(H_)^3 * max(W_)^3)回ループ
    // X[0][0]をC[0][0]とする．
    /* d_A: AのCへの貼り付け方（C[dH_A][dW_A]にA[0][0]を貼る） */
    for (int dH_A = min_H_A; dH_A + max_H_A < H_X; dH_A++) {
        for (int dW_A = min_W_A; dW_A + max_W_A < W_X; dW_A++) {
            cout << "dH_A, dW_A = " << dH_A << ", " << dW_A << "\n";
            /* d_B: BのCへの貼り付け方（C[dH_B][dW_B]にB[0][0]を貼る） */
            for (int dH_B = min_H_B; dH_B + max_H_B < H_X; dH_B++)
                for (int dW_B = min_W_B; dW_B + max_W_B < W_X; dW_B++) {
                    cout << "dH_B, dW_B = " << dH_B << ", " << dW_B << "\n";
                    // d_A と d_B を ('#'をtrueとした) OR で畳み込む
                    bool is_OK = true;
                    for (int h_x = 0; h_x < H_X; h_x++) {
                        for (int w_x = 0; w_x < W_X; w_x++) {
                            // 範囲チェック
                            if (0 <= h_x + dH_A && h_x + dH_A < H_A)
                                if (0 <= w_x + dW_A && w_x + dW_A < W_A) {
                                    // d_A が黒ければCも黒い
                                    if (A[h_x + dH_A][w_x + dW_A] == '#') {
                                        if (X[h_x][w_x] == '#') continue;
                                        else {
                                            is_OK = false;
                                            cout << "false at " << h_x << ", "
                                                 << w_x << "\n";
                                            break;
                                        }
                                    }
                                }

                            if (0 <= h_x + dH_B && h_x + dH_B < H_B)
                                if (0 <= w_x + dW_B && w_x + dW_B < W_B) {
                                    // d_B が黒ければCも黒い
                                    if (B[h_x + dH_B][w_x + dW_B] == '#') {
                                        if (X[h_x][w_x] == '#') continue;
                                        else {
                                            is_OK = false;
                                            cout << "false at " << h_x << ", "
                                                 << w_x << "\n";
                                            break;
                                        }
                                    }
                                }

                            // d_A も d_B も黒くなければCは透明
                            if (X[h_x][w_x] == '#') {
                                is_OK = false;
                                break;
                            }
                        }
                        if (!is_OK) break;
                    }
                    if (is_OK) {
                        cout << "Yes\n";
                        return 0;
                    }
                }
        }
    }

    cout << "No\n";

    return 0;
}
