#include <algorithm>
#include <iostream>
#include <string>

#define NP(A, i)  std::next_permutation(A[i].begin(), A[i].end())
#define REP(i, n) for (uint i = 0U; i < (n); i++)

uint N;
std::string R, C;
std::string A[5Z] = {".....", ".....", ".....", ".....", "....."};

// A[i]の先頭がR[i]か
bool is_A_ok_R(uint i) {
    REP(j, N) {
        if (A[i][j] == '.') continue;
        if (A[i][j] == R[i]) return true;
        else return false;
    }
    return false;
}

// 列の先頭が C[i] か
bool is_A_ok_C() {
    REP(j, N) {
        REP(i, N) {
            if (A[i][j] == '.') continue;
            if (A[i][j] == C[j]) break;
            else return false;
        }
    }
    return true;
}

// 列にABC一つずつか
bool do_columns_satisfy() {
    REP(j, N) {
        bool cA = false, cB = false, cC = false;
        REP(i, N) {
            if (A[i][j] == 'A') {
                if (cA) return false;
                else cA = true;
            }
            if (A[i][j] == 'B') {
                if (cB) return false;
                else cB = true;
            }
            if (A[i][j] == 'C') {
                if (cC) return false;
                else cC = true;
            }
        }
        if (!cA || !cB || !cC) return false;
    }
    return true;
}

int main() {
    using std::cin;
    using std::cout;
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    cin >> N;
    cin >> R;
    cin >> C;

    // 行にABC一つずつ
    REP(i, N) {
        A[i].resize(N);
        A[i][N - 3U] = 'A';
        A[i][N - 2U] = 'B';
        A[i][N - 1U] = 'C';
    }

    // 全探索
    do {  // 5! = 120
        // R[0]が先頭：5C2 * 2! = 20
        if (!is_A_ok_R(0U)) continue;
        do {
            if (!is_A_ok_R(1U)) continue;
            do {
                if (!is_A_ok_R(2U)) continue;
                do {
                    if (N > 3U)
                        if (!is_A_ok_R(3U)) continue;
                    do {
                        if (N > 4U)
                            if (!is_A_ok_R(4U)) continue;

                        if (!do_columns_satisfy()) continue;
                        if (!is_A_ok_C()) continue;

                        cout << "Yes\n";
                        REP(i, N) cout << A[i] << "\n";
                        return 0;

                    } while (NP(A, 4Z));
                } while (NP(A, 3Z));
            } while (NP(A, 2Z));
        } while (NP(A, 1Z));
    } while (NP(A, 0Z));

    cout << "No\n";
    return 0;
}